#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>

constexpr static std::size_t INITIAL_CAP = 10;

template <typename T, class Alloc = std::allocator<T>>
class Queue {
    void free() {
        std::destroy(m_data, m_data + m_size);
        // Deallocate the memory
        AT::deallocate(alloc, m_data, m_capacity);
        m_data     = nullptr;
        m_size     = 0;
        m_capacity = 0;
    }

protected:
    T* m_data          = nullptr;
    std::size_t m_size = 0, m_capacity = 0;
    Alloc alloc;
    using AT = std::allocator_traits<Alloc>;

    T* data() const { return m_data; }

    void reserve(std::size_t cap) {
        if (cap <= m_capacity) return;
        T* newdata = AT::allocate(alloc, cap);
        if (newdata) {
            if (m_data) {
                // Because newdata is uninitialized memory
                std::uninitialized_move(m_data, m_data + m_size, newdata);
                std::destroy(m_data, m_data + m_size);
                AT::deallocate(alloc, m_data, m_capacity);
            }
            m_data     = newdata;
            m_capacity = cap;
        }
    }

public:
    Queue() {}

    explicit Queue(std::size_t capacity) : m_capacity(capacity) {
        reserve(capacity);
    }

    Queue(std::initializer_list<T> list) {
        reserve(list.size());
        for (const T& item : list) {
            enqueue(item);
        }
    }

    Queue(const T* ptr);

    Queue(const Queue& other) {
        reserve(other.m_capacity);
        m_size = other.m_size;
        std::uninitialized_copy(other.m_data, other.m_data + other.m_size,
                                m_data);
    }

    Queue& operator=(const Queue& other) {
        if (this == &other) return *this;
        reserve(other.m_capacity);
        // Simple copying to already constructed memory
        std::copy_n(other.m_data, std::min(other.m_size, m_size), m_data);
        if (other.m_size > m_size) {
            std::uninitialized_copy(other.m_data + m_size,
                                    other.m_data + other.m_size,
                                    m_data + m_size);
        } else if (m_size > other.m_size) {
            // Destroy the extra elements
            std::destroy(m_data + other.m_size, m_data + m_size);
        }
        m_size = other.m_size;
        return *this;
    }

    Queue(Queue&& other) noexcept :
        m_data(other.m_data), m_size(other.m_size),
        m_capacity(other.m_capacity) {
        other.m_data     = nullptr;
        other.m_size     = 0;
        other.m_capacity = 0;
    }

    Queue& operator=(Queue&& other) noexcept {
        if (this == &other) return *this;
        m_data           = other.m_data;
        m_size           = other.m_size;
        m_capacity       = other.m_capacity;
        other.m_data     = nullptr;
        other.m_size     = 0;
        other.m_capacity = 0;
        return *this;
    }

    ~Queue() { free(); }

    std::size_t size() const { return m_size; }

    std::size_t capacity() const { return m_capacity; }

    std::string to_string();

    void enqueue(const T& item) {
        if (m_capacity == 0) {
            reserve(INITIAL_CAP);
        } else if (m_size == m_capacity) {
            std::cout << "Queue is full, cannot enqueue more items.\n";
            return;
        }
        AT::construct(alloc, m_data + m_size, item);
        m_size++;
    }

    void enqueue(T&& item) {
        if (m_capacity == 0) {
            reserve(INITIAL_CAP);
        } else if (m_size == m_capacity) {
            std::cout << "Queue is full, cannot enqueue more items.\n";
            return;
        }
        AT::construct(alloc, m_data + m_size, std::move(item));
        m_size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            std::move(m_data + 1, m_data + m_size, m_data);
            AT::destroy(alloc, m_data + m_size - 1);
            m_size--;
        }
    }

    bool isEmpty() const { return m_size == 0; }

    bool isFull() const { return m_size == m_capacity; }

    void display() const {
        for (int i = 0; i < m_size; ++i) {
            std::cout << m_data[i] << '\n';
        }
    }

    T* front() {
        if (!isEmpty()) {
            return &m_data[0];
        }
        return nullptr;
    }

    T* back() {
        if (!isEmpty()) {
            return &m_data[m_size - 1];
        }
        return nullptr;
    }
};

template <>
inline Queue<char>::Queue(const char* str) {
    int len = 0;
    while (str + len) {
        enqueue(str[len++]);
    }
}

template <>
inline void Queue<char>::display() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_data[i];
    }
    std::cout << '\n';
}

template <>
inline std::string Queue<char>::to_string() {
    std::string str;
    str.resize(m_size);
    for (int i = 0; i < m_size; ++i) {
        str[i] = m_data[i];
    }
    return str;
}

template <typename T>
class CircularQueue : public Queue<T> {
    using Queue<T>::m_data;
    using Queue<T>::m_size;
    using Queue<T>::m_capacity;
    std::size_t m_front = 0, m_rear = 0;

private:
    using Queue<T>::reserve;

public:
    using Queue<T>::Queue;
    using Queue<T>::size;
    using Queue<T>::capacity;
    using Queue<T>::to_string;
    using Queue<T>::isEmpty;
    using Queue<T>::isFull;
    using Queue<T>::display;

    void enqueue(const T& item) {
        if (m_capacity == 0) {
            reserve(INITIAL_CAP);
        } else if (m_size == m_capacity) {
            std::cout << "Queue is full, cannot enqueue more items.\n";
            return;
        }
        m_data[m_rear] = item;
        m_rear         = (m_rear + 1) % m_capacity;
        m_size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            m_front = (m_front + 1) % m_capacity;
            m_size--;
        }
    }

    T* front() {
        if (!isEmpty()) {
            return &m_data[m_front];
        }
        return nullptr;
    }

    T* back() {
        if (!isEmpty()) {
            std::size_t idx = (m_rear + m_capacity - 1) % m_capacity;
            return &m_data[idx];
        }
        return nullptr;
    }
};
