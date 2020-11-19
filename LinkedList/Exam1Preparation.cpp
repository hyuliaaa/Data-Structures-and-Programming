#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
Node<T>*create(T arr[], int size)
{
    if(size==0)
    {
        return nullptr;
    }

    Node<T>*p=new Node<T>;
    p->data=arr[0];
    p->next= nullptr;

    Node<T>*first=p;

    for(int i=1;i<size;i++)
    {
        Node <T>*t=new Node<T>;
        t->data=arr[i];
        p->next=t;
        t->next= nullptr;
        p=t;
    }

    return first;
}



template <typename T>
void mirror(Node <T>*& first)
{
    Node <T>*p=first;
    while(p->next!= nullptr)
    {
        p=p->next;
    }

    Node<T>*q=first;
    int counter=count(first);
    while (counter!=0 &&q!= nullptr)
    {
        Node <T>*t=new Node<T>;
        t->data=q->data;
        t->next=p->next;
        p->next=t;
        q=q->next;
        counter--;


    }


}

template <typename T>
int count(Node <T>*first)
{
    int counter=0;
    while (first!= nullptr)
    {
        counter++;
        first=first->next;
    }
    return counter;
}

template <typename T>
void print(Node<T>*first)
{
    while (first!= nullptr)
    {
        std::cout<<first->data<<" ";
        first=first->next;
    }
    std::cout<<std::endl;


}


template <typename T>
void fillGaps(Node<T>*&first)
{
    if(first== nullptr)
    {
        return;
    }
    if(first->next== nullptr)
    {
        return;
    }

    Node<T>*p=first;
    while (p->next!= nullptr &&p!= nullptr)
    {
        int counter=(p->next->data)-(p->data);

        if(counter>1)
        {
            while (counter!=1)
            {
                Node<T>*t=new Node<T>;
                t->data=p->data+1;
                t->next=p->next;
                p->next=t;
                p=t;
                counter--;
            }
        }else {
            p = p->next;
        }
    }
}

template <typename T>
void removeDups(Node<T>*&first)
{
    if(first== nullptr)
    {
        return;
    }
    if(first->next== nullptr)
    {
        return;
    }

    Node<T> *p=first;
    while (p!= nullptr)
    {
        if(p->next!= nullptr)
        {
            Node<T>*curr=p->next;
            Node<T>*t=p;
            while(curr!= nullptr)
            {
                if(p->data==curr->data)
                {
                    t->next=curr->next;
                    delete curr;
                    curr=t->next;
                }
                else
                {
                    t=curr;
                    curr=curr->next;
                }
           }

        }
        p=p->next;
    }

}





int main() {

    int arr[]={1,1};
    Node<int>*first=create<int>(arr,2);
    //print(first);
    //mirror(first);
   // fillGaps(first);
   removeDups(first);
    print(first);
    return 0;
}
