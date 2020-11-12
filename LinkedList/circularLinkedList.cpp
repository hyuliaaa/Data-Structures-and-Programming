#include <iostream>
#include <stdexcept>

struct Node
{
    int data;
    Node *next;
}*head;

void create(const int arr[], int n)
{
    head=new Node;
    head->data=arr[0];
    head->next= nullptr;
    Node *p=head;

    for(int i=1;i<n;i++)
    {
        Node *t=new Node;
        t->data=arr[i];
        p->next=t;
        p=p->next;
    }
    p->next=head;

}

void print(Node *p)
{
    do
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }while (p!=head);
    std::cout<<std::endl;
}

void printRecursive(Node *p)
{
    static int isHeadVisited= 0;
    if(p!=head  || isHeadVisited== 0)
    {
        std::cout<<p->data<<" ";
        isHeadVisited= 1;
        printRecursive(p->next);

    }
}

int length(Node *p)
{
    int counter=0;
    do{
        counter++;
        p=p->next;
    }while (p!=head);
    return counter;
}

void insert(Node *p, int position, int x)
{
    if(position < 0 || position > length(head))
    {
        return;
    }

    if(position==0 || position==length(head)) {
        Node *t = new Node;
        t->data = x;

        if (head == nullptr)
        {
            head = t;
            head->next = head;
        }
        else{

            while (p->next != head) {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
            head=t;
        }
    }
    else
    {
        Node *t=new Node;
        t->data=x;
        for(int i=0; i<position-1;i++)
        {
            p=p->next;
        }

        t->next=p->next;
        p->next=t;

    }
}

void deleteNode(Node *p, int position)
{
    if(position<0 || position>length(head))
    {
        throw "Not valid position";
        return;
    }
    if(position==1)
    {
        if(head== nullptr)
        {
            throw "No head to delete";
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else
    {
        Node *q= nullptr;
        for(int  i=0; i<position-1;i++)
        {
            q=p;
            p=p->next;
        }

        q->next=p->next;
        delete p;

    }
}



bool hasCycle(Node *p)
{

    Node *q=head;

    while(p && q)
    {
        p=p->next;
        p=p->next;
        q=q->next;
        if(p==q)
        {

            return true;
        }

    }
    return false;
}

int main() {

    int arr[]={1,2,3,4};
    create(arr,4);
    std::cout<<hasCycle(head)<<std::endl;
    print(head);


    insert(head,4,6);

    print(head);
    deleteNode(head,1);
    deleteNode(head,4);
    deleteNode(head,2);
    print(head);
    return 0;
}
