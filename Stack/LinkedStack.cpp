#include <iostream>
template <typename T>
class Stack
{
    struct Node
    {
        T data;
        Node* next;
    };
private:
    Node* top;
    void copy(const Stack<int>& other);
    void free();
    void pushBack(T x);
public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();


    bool isEmpty()const;
    void push(T x);
    void pop();
    void print();
    T topEl();
};

template <typename T>
Stack<T>::Stack() :top(nullptr) {}

template <typename T>
void Stack<T>::copy(const Stack<int>& other)  //TODO
{
    if (other.isEmpty())
    {
        return;
    }

    Node* p = other.top;
    while (p != nullptr)
    {
        pushBack(p->data);
        p = p->next;
    }


}

template <typename T>
void Stack<T>::free()
{
    Node* p = top;
    while (p != nullptr)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
    copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other)
    {
        free();
        copy(other);
    }
}

template<typename T>
Stack<T>::~Stack() {
    free();
}

template<typename T>
void Stack<T>::push(T x) {
    if (top == nullptr)
    {
        Node* t = new Node;
        t->data = x;
        t->next = nullptr;
        top = t;
    }
    else
    {
        Node* t = new Node;
        t->data = x;
        t->next = top;
        top = t;
    }
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template<typename T>
void Stack<T>::print() {
    Node* p = top;
    while (p != nullptr)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

template<typename T>
void Stack<T>::pop() {
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node* p = top;
        top = top->next;
        delete p;
        p = nullptr;
    }
}

template<typename T>
T Stack<T>::topEl() {
    if (isEmpty())
    {
        std::cerr << "Empty Stack";
        return 0;
    }
    else
    {
        Node* p = top;
        return p->data;
    }
}

template<typename T>
void Stack<T>::pushBack(T x) {
    if (isEmpty())
    {
        Node* t = new Node;
        t->data = x;
        t->next = nullptr;
        top = t;
    }
    else
    {
        Node* p = top;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        Node* t = new Node;
        t->data = x;
        t->next = nullptr;
        p->next = t;

    }
}


int main() {
    Stack <int> st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.pop();
    st.print();

    Stack <int>s = st;
    s.print();


    return 0;
}
