#include <iostream>

struct Node
{
    Node *prev;
    int data;
    Node *next;
}*first=nullptr;

void create(const int arr[],int n)
{
    first=new Node;
    first->data=arr[0];
    first->prev= nullptr;
    first->next=nullptr;
    Node *p=first;

    for(int i=1; i<n;i++)
    {
        Node *t=new Node;
        t->data=arr[i];
        t->prev=p;
        p->next=t;
        t->next= nullptr;
        p=t;
    }
}

int findMiddle(Node *p)
{
   Node *q=first;
   while(p!= nullptr)
   {
       p=p->next;
       if(p)
       {
           p=p->next;
       }
       if(p!= nullptr)q=q->next;
   }
    return q->data;
}

void insertAtMiddle(Node *p, int x)
{
    Node *q=first;
    while(p!= nullptr)
    {
        p=p->next;
        if(p)
        {
            p=p->next;
        }
        if(p!= nullptr)q=q->next;
    }
    Node *t=new Node;
    t->data=x;
    t->next=q->next;
    q->next->prev=t;
    t->prev=q;
    q->next=t;
}


void print(Node *p)
{
    while(p!=nullptr)
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

int countNodes(Node *p)
{
    int counter=0;
    while(p!=nullptr)
    {
        counter++;
        p=p->next;
    }
    return counter;
}

void insert(Node *p,int position,int x)
{
    if(position<0 || position>countNodes(first))
    {
        return;
    }
    if(position==0)
    {
        if(first== nullptr)
        {
            first=new Node;
            first->data=x;
            first->prev=nullptr;
            first->next= nullptr;
        }
        else
        {
            Node *t=new Node;
            t->data=x;
            t->prev=nullptr;
            t->next=first;
            first->prev=t;
            first=t;
        }
    }
    else if(position==countNodes(first))
    {
        Node *t=new Node;
        t->data=x;

        for(int i=0; i<position-1;i++)
        {
            p=p->next;
        }
        t->next=nullptr;
        p->next=t;
        t->prev=p;
    }
    else
    {
        for(int i=0;i<position-1;i++)
        {
            p=p->next;
        }
        Node *t=new Node;
        t->data=x;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
        t->prev=p;
    }
}


void deleteNode(Node *p, int position)
{
    if(position < 0 || (position>countNodes(first)))
    {
        return;
    }
    if(position==1)
    {
        first=first->next;
        first->prev= nullptr;
        delete p;
        p=first;
    }


    else
    {
        Node *q= nullptr;
        for(int i=0; i<position-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        if(p->next!= nullptr) {
            p->next->prev = q;
        }
        delete p;
    }

}


void swapValues(Node *p, int a, int b)
{

    if(a <=0 || b<=0 || a>countNodes(first) || b>countNodes(first))
    {
        return;
    }
    Node *q=first;
    for(int i=0; i<a-1;i++)
    {
        p=p->next;
    }
    for(int i=0; i<b-1;i++)
    {
        q=q->next;
    }

    int tmp=p->data;
    p->data=q->data;
    q->data=tmp;
}



int main() {

    int arr[]={4,5,6,7};
    create(arr,4);
    print(first);
    insert(first,4,1);
    print(first);
    deleteNode(first,1);
    print(first);
    std::cout<<findMiddle(first)<<std::endl;
    insertAtMiddle(first,3);
    print(first);
    insertAtMiddle(first,4);
    print(first);
    swapValues(first,2,4);
    print(first);

    return 0;
}
