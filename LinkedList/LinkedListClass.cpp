
#include <iostream>


struct Node{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList();
    LinkedList(int A[], int n);
    ~LinkedList();

    void display();
    void insert(int index, int x);

    void deleteElement(int index);
    int length();

};

LinkedList::LinkedList():first(nullptr)
{

}
LinkedList ::LinkedList(int *A, int n)
{
    Node *last;
    first=new Node;
    Node *t=first;
    t->data=A[0];
    t->next= nullptr;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next= nullptr;
        last->next=t;
        last=t;
    }
}
LinkedList::~LinkedList()
{
    Node *p=first;
    while(p!= nullptr)
    {
        first=first->next;
        delete p;
        p=first;
    }
}

void LinkedList::display()
{
    Node *p=first;
    while(p!= nullptr)
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

void LinkedList::insert(int index, int x)
{
    if(index <0)
    {
        std::cout<<"Invalid place to insert"<<std::endl;
        return;
    }
    Node *p=first;
    Node *t;
    if(index==0)
    {
        t=new Node;
        t->data=x;
        t->next=p;
        first=t;
    }
    else
    {
        for(int i=0; i<index-1;i++)
        {
          p=p->next;
        }
        if(p) {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }

}

void LinkedList::deleteElement(int index)
{
    Node *p=first;
    Node *q= nullptr;
    if(index <= 0)
    {
        return ;
    }
    if(index==1)
    {
        first=first->next;
        delete p;

    }
    else
    {
        for(int i=0; i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        if(p) {
            q->next = p->next;
            delete p;
        }
    }
}
int LinkedList ::length()
{
    int count=0;
    Node *p=first;
    while(p!= nullptr)
    {
        count+=1;
        p=p->next;
    }
    return count;
}



int main() {
    int arr[]={1,2,3,4,5};
    LinkedList l(arr,5);
    l.display();
    l.insert(3,6);
    l.display();
    std::cout<<l.length()<<std::endl;
    l.deleteElement(3);
    l.display();

    return 0;
}
