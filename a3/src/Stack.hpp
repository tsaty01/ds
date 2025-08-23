#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>

constexpr static std::size_t INITIAL_CAP = 10;

template <typename T>
class Stack {
    T* m_data          = nullptr;
    std::size_t m_size = 0, m_capacity = 0;

    static void relocate(T* from, std::size_t size, T* to) {
        for (std::size_t i = 0; i < size; ++i) {
            to[i] = std::move(from[i]);
        }
    }

    static void copy_assign(T* from, std::size_t size, T* to) {
        for (std::size_t i = 0; i < size; ++i) {
            to[i] = from[i];
        }
    }

    void free() {
        delete[] m_data;
        m_data     = nullptr;
        m_size     = 0;
        m_capacity = 0;
    }

protected:
    T* data() const { return m_data; }

public:
    Stack() {}

    explicit Stack(std::size_t capacity) : m_capacity(capacity) {
        reserve(capacity);
    }

    Stack(std::initializer_list<T> list) {
        for (const T& item : list) {
            push(item);
        }
    }

    Stack(const T* ptr);

    Stack(const Stack& other) {
        reserve(other.m_capacity);
        m_size = other.m_size;
        copy_assign(other.m_data, m_size, m_data);
    }

    Stack& operator=(const Stack& other) {
        if (this == &other) return *this;
        reserve(other.m_capacity);
        m_size = other.m_size;
        copy_assign(other.m_data, m_size, m_data);
        return *this;
    }

    Stack(Stack&& other) {
        reserve(other.m_capacity);
        m_size = other.m_size;
        relocate(other.m_data, other.m_size, m_data);
        other.free();
    }

    Stack& operator=(Stack&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_data;
        reserve(other.m_capacity);
        m_size = other.m_size;
        relocate(other.m_data, other.m_size, m_data);
        other.free();
        return *this;
    }

    ~Stack() { free(); }

    std::size_t size() const { return m_size; }

    std::size_t capacity() const { return m_capacity; }

    std::string to_string();

    void reserve(std::size_t cap) {
        if (cap <= m_size) return;
        T* newdata = new T[cap];
        if (m_data) {
            relocate(m_data, m_size, newdata);
            // Calls the dtor for all elements
            delete[] m_data;
        }
        m_data     = newdata;
        m_capacity = cap;
    }

    void push(const T& item) {
        if (m_capacity == 0) reserve(INITIAL_CAP);
        if (m_size >= m_capacity) {
            reserve(2 * m_capacity);
        }
        m_data[m_size++] = item;
    }

    void push(T&& item) {
        if (m_capacity == 0) reserve(INITIAL_CAP);
        if (m_size >= m_capacity) {
            reserve(2 * m_capacity);
        }
        m_data[m_size++] = item;
    }

    void pop() {
        if (!isEmpty()) {
            m_data[m_size - 1].~T();
            m_size--;
        }
    }

    bool isEmpty() const { return m_size == 0; }

    bool isFull() const { return m_size == m_capacity; }

    void display() const {
        for (int i = m_size - 1; i >= 0; --i) {
            std::cout << m_data[i] << '\n';
        }
    }

    T* peek() {
        if (!isEmpty()) {
            return &m_data[m_size - 1];
        }
        return nullptr;
    }

    void reverse() {
        for (int i = 0; i < m_size / 2; ++i) {
            std::swap(m_data[i], m_data[m_size - 1 - i]);
        }
    }
};

template <>
inline Stack<char>::Stack(const char* str) {
    int len = 0;
    while (str[len]) {
        push(str[len++]);
    }
}

template <>
inline void Stack<char>::display() const {
    for (int i = 0; i < m_size; ++i) {
        std::cout << m_data[i];
    }
    std::cout << '\n';
}

template <>
inline std::string Stack<char>::to_string() {
    std::string str;
    str.resize(m_size);
    for (int i = 0; i < m_size; ++i) {
        str[i] = m_data[i];
    }
    return str;
}
