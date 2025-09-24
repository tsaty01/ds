#include <initializer_list>
#include <iostream>
#include <utility>

template <typename T>
class Node;

template <typename T>
class LinkedList {
    Node<T>* head = nullptr;

public:
    LinkedList() {}

    LinkedList(std::initializer_list<T> list) {
        Node<T>* tail = nullptr;
        for (const T& item : list) {
            Node<T>* n = new Node(item);
            if (!head) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail       = n;
            }
        }
    }

    void display() const {
        Node<T>* p = head;
        while (p) {
            std::cout << p->data;
            if (p->next) {
                std::cout << " -> ";
            }
            std::cout << '\n';
            p = p->next;
        }
    }
};

template <typename T>
class Node {
    T data;
    Node* next = nullptr;

    static Node* clone_chain(const Node* src_next) {
        Node* head    = nullptr;
        Node* tail    = nullptr;
        const Node* p = src_next;

        while (p) {
            Node* n = new Node(p->data);
            if (!head) {
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail       = n;
            }
            p = p->next;
        }
        return head;
    }

    static void destroy_chain(Node* p) {
        while (p) {
            Node* tmp = p->next;
            delete p;
            p = tmp;
        }
    }

public:
    explicit Node(const T& v) : data(v) {}

    explicit Node(T&& v) : data(std::move(v)) {}

    Node(const Node& other) : data(other.data) {
        next = clone_chain(other.next);
    }

    Node(Node&& other) : data(std::move(other.data)), next(other.next) {
        other.next = nullptr;
    }

    // copy/move-and-swap
    // Can handle both copy and move assignment
    Node& operator=(Node other) {
        swap(other);
        return *this;
    }

    ~Node() {
        destroy_chain(next);
        next = nullptr;
    }

    void swap(Node& rhs) {
        using std::swap;
        swap(data, rhs.data);
        swap(next, rhs.next);
    }

    friend class LinkedList<T>;
};

template <typename T>
void swap(Node<T>& a, Node<T>& b) {
    a.swap(b);
}
