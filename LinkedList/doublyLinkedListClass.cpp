#include <iostream>
template <typename T>
class DoublyLinkedList
{
    struct Node
    {
        Node* prev;
        T data;
        Node* next;

    };

private:
    Node *first;
    void free();
    void copy(const DoublyLinkedList& other);
public:
    DoublyLinkedList():first(nullptr){};
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList&operator=(const DoublyLinkedList& other);
    ~DoublyLinkedList();

 //   const T& operator[](int index) ;
    T& operator[](int index);



    int length();
    void pushBack(T x);
    void pushFront(T x);
    void print();
    void popBack();
    void popFront();
    void insert(int position, T x);
    void deleteNode(int position);
};



template <typename T>
void DoublyLinkedList<T>::free()
{
    Node *p=first;
    while(p!= nullptr)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    free();
}

template  <typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList &other)
{
    first=other.first;
    Node *p=first;
    while(p!= nullptr)
    {
        pushBack(p->data);
        p->next;
    }
}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &other)
{
    copy(other);
}


template <typename T>
void DoublyLinkedList<T>::pushBack(T x)
{
    Node *p=first;
    if(first== nullptr)
    {
        Node *t=new Node;
        t->data=x;
        t->next= nullptr;
        t->prev= nullptr;
        first=t;
    }
    else
    {
        while (p->next!= nullptr)
        {
            p=p->next;
        }

        Node *t=new Node;
        t->data=x;
        t->next= nullptr;
        t->prev=p;
        p->next=t;
    }
}

template <typename T>
void DoublyLinkedList<T>::pushFront(T x)
{
    if(first== nullptr)
    {
        Node *t=new Node;
        t->data=x;
        t->next= nullptr;
        t->prev= nullptr;
    }
    else
    {
        Node *t=new Node;
        t->data=x;
        t->prev= nullptr;
        t->next=first;
        first->prev=t;
        first=t;

    }
}

template <typename T>
void DoublyLinkedList<T>::popBack()
{

    if(first== nullptr)
    {
        return;
    }
    else if(first->next== nullptr)
    {
        delete first;
        first= nullptr;
    }
    else
    {
        Node *p = first;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->prev->next = nullptr;

        delete p;
    }
}

template <typename T>
void DoublyLinkedList<T>::popFront()
{
    if(first== nullptr)
    {
        return;
    }
    else if(first->next== nullptr)
    {
        delete first;
        first= nullptr;
    }
    else
    {

        Node *p=first;
        first=first->next;
        first->prev= nullptr;
        p->next= nullptr;
        delete p;
        p= nullptr;
    }

}

template <typename T>
int DoublyLinkedList<T>::length()
{
    int counter=0;
    Node *p=first;
    while(p!= nullptr)
    {
        counter++;
        p=p->next;
    }
    return counter;
}

template <typename T>
void DoublyLinkedList<T>::insert(int position, T x)
{
    if(position<0 || position > length())
    {
        return;
    }
    if(position==0)
    {
        pushFront(x);
    }
    else if(position==length())
    {
        pushBack(x);
    }
    else
    {
        Node *p=first;
        for(int i=0; i<position-1;i++)
        {
            p=p->next;
        }
        Node *t=new Node;
        t->data=x;
        t->next=p->next;
        t->next->prev=t;
        p->next=t;
        t->prev=p;

    }

}
template <typename T>
void DoublyLinkedList<T>::deleteNode(int position)
{
    if(position==1)
    {
        popFront();
    }
    else if(position==length())
    {
        popBack();
    }
    else
    {
        Node *q=first;
        Node *p=first;
        for(int i=0; i<position-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        q->next->prev=q;
        delete p;
        p=nullptr;

    }
}

template <typename T>
void DoublyLinkedList<T>::print()
{
    Node *p=first;
    while(p!= nullptr)
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

template<typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList &other) {
    if(this!=&other)
    {
        free();
        copy(other);
    }
    return *this;
}

//template<typename T>
//const T &DoublyLinkedList<T>::operator[](int index)  {
//    if(index>length())
//    {
//        throw std::out_of_range("Out of range");
//
//    }
//    Node *p=first;
//    for(int i=0; i<index;i++)
//    {
//        p=p->next;
//    }
//    return p->data;
//
//}

template<typename T>
T &DoublyLinkedList<T>::operator[](int index) {
    if(index>length())
    {
        throw std::out_of_range("Out of range");

    }
    Node *p=first;
    for(int i=0; i<index;i++)
    {
        p=p->next;
    }
    return p->data;
}

int main() {
    DoublyLinkedList <int> dl;
    dl.pushBack(4);
    dl.pushBack(5);
    dl.print();
    dl.pushFront(9);
    dl.print();
    dl.popBack();
    dl.print();
    dl.popFront();
    dl.print();

    dl.insert(0,5);
    dl.print();
    dl.insert(2,3);
    dl.print();
    dl.insert(3,6);
    dl.print();
    dl.deleteNode(2);
    dl.print();
    dl.print();
    std::cout<<dl[2]<<std::endl;//calls const T& operator[](int index), which only allows to print the value and NOT change it,if the first operator is missing it
    //uses the second which which also allows changing the value;
    dl[2]=1; //calls T& operator[](int index),which allows printing and changing the value
    //TODO error when I have the two operators
      dl.print();


    return 0;
}
