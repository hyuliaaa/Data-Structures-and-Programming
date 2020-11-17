#include <iostream>

template <typename T>
class Queue
{
    struct Node
    {
        T data;
        Node *next;
    };
private:
    Node *head;
    Node *last;

    void copy(const Queue& other);
    void free();
public:
    Queue():head(nullptr),last(nullptr){};
    Queue(const Queue& other);
    Queue& operator=(const Queue&other);
    ~Queue();

    void enqueue(T x); //add to back
    T dequeue(); //remove from front
    void print();
    bool isEmpty(){ return head== nullptr;};
};

template<typename T>
void Queue<T>::copy(const Queue &other) {
        Node *p=other.head;
        while (p!= nullptr)
        {
            enqueue(p->data);
            p=p->next;
        }
}

template<typename T>
void Queue<T>::enqueue(T x) {

    if(head== nullptr && last== nullptr) {
        Node *t = new Node;
        t->data = x;
        t->next = nullptr;
        head = t;
        last = t;
    }
    else
    {
        Node *p=head;
        while(p->next!= nullptr)
        {
            p=p->next;
        }
        Node *t=new Node;
        t->data=x;
        t->next= nullptr;
        p->next=t;
        last=t;
    }
}

template<typename T>
void Queue<T>::print() {
    Node *p=head;
    while(p)
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

template<typename T>
void Queue<T>::free() {
    Node *t=head;
    while (t!= nullptr)
    {
        head=head->next;
        delete t;
        t=head;
    }
}

template<typename T>
Queue<T>::~Queue() {
    free();
}

template<typename T>
Queue<T>::Queue(const Queue &other) {
    copy(other);
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &other) {
    if(this!=&other)
    {
        free();
        copy(other);
    }
    return *this;
}

template<typename T>
T Queue<T>::dequeue() {
    if(head== nullptr)
    {
        return T() ;
    }
    else
    {
        int data;
        Node *p=head;
        head=head->next;
        data=p->data;
        delete p;
        p=head;
        return data;

    }

}

int main() {

    Queue <int> q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(1);
    q.print();
    int data=q.dequeue();
    q.print();
    std::cout<<data<<std::endl;


    return 0;
}
