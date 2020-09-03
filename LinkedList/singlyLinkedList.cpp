#include <iostream>

struct Node //self-referential structure
{
    int data;
    Node *next;
}*first= nullptr, *second= nullptr,*third= nullptr; //global pointer, accessible everywhere in the program

void create(int arr[],int n)
{
    Node *t;
    Node *last;
    first=new Node;
    t=first;
    t->data=arr[0];
    t->next= nullptr;
    last=t;

    for(int i=1; i<n;i++)
    {
        t=new Node;
        t->data=arr[i];
        t->next= nullptr;
        last->next=t;
        last=t;
    }

}
void create2(int arr[],int n)
{
    Node *t;
    Node *last;
    second=new Node;
    t=second;
    t->data=arr[0];
    t->next= nullptr;
    last=t;

    for(int i=1; i<n;i++)
    {
        t=new Node;
        t->data=arr[i];
        t->next= nullptr;
        last->next=t;
        last=t;
    }

}




void display(Node *p)
{
    while(p!= nullptr)
    {
        std::cout<<p->data<<" ";
        p=p->next;
    }
}

void recursiveDisplay(Node *p)
{

    if(p!= nullptr)
    {
        std::cout<<p->data<<" ";
        recursiveDisplay(p=p->next); //p->next it is possible to give as function parameter
    }

}
void reverseDisplay(Node *p)
{
    if(p!=nullptr)
    {
        reverseDisplay(p->next);
        std::cout<<p->data<<" ";
    }
}

int nodeNumber(Node *p)
{
    int counter=0;
    while(p!=nullptr)
    {
        counter++;
        p=p->next;
    }
    return counter;
}

int recursiveNodeNumber(Node *p)
{
    if(p==nullptr)
    {
        return 0;
    }
    else
    {
        return recursiveNodeNumber(p->next)+1;
    }
}

int elementsSum(Node *p)
{
    int sum=0;
    while(p!= nullptr)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}


int recursiveElementsSum(Node *p)
{
    if(p== nullptr)
    {
        return 0;
    }
    else
    {
        return recursiveElementsSum(p->next)+p->data;
    }
}

int maxElement(Node *p)
{
    int maxEl=INT_MIN;
    while (p!=nullptr)
    {
       if(p->data > maxEl)
       {
           maxEl=p->data;
       }
       p=p->next;
    }
    return maxEl;
}

int findElement(Node *p, int x)
{
    while(p)
    {
        if(p->data == x)
        {
            std::cout<<"Element is found" <<std::endl;
            return x;
        }
        p=p->next;
    }
    return -1;
}

Node* search(Node *p, int x)
{
    while(p)
    {
        if(p->data==x)
        {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

Node *recursiveSearch(Node *p, int x)
{
    if(p== nullptr)
    {
        return nullptr;
    }

    if(p->data==x)
    {
        return p;
    }

    recursiveSearch(p->next,x);

}

Node *searchByMovingElementToFront(Node *p, int x)
{
    Node *q= nullptr;
    while(p)
    {
        if(p->data==x)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;

        }
        q=p;
        p=p->next;

    }
    return nullptr;
}
Node *insertAtBeginning(int x)
{
    Node *t;
    t=new Node;
    t->data=x;
    t->next=first;
    first=t;
    return first;
}

void insert(int pos, int x)
{
    Node *p;
    Node *t;
    if(pos<0)
    {
        return;
    }
    if(pos==0)
    {
        t=new Node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else if (pos >0)
    {
        p=first;

        for(int i=0;i<pos-1 && p;i++)  //checking whether p is pointing at some node, it should not be null
        {
            p=p->next;
        }
        if(p)
        {
            t=new Node;
            t->data=x;
            t->next = p->next;
            p->next = t;
        }
    }
}
void insertInSortedList(Node *p,int x)
{


    Node *t=new Node;
    t->data=x;
    t->next= nullptr;

    Node *q= nullptr;
    if(first== nullptr)
    {
        first=t;
    }
    else
        {

        while (p->data < x && p) {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
            {
            t->next = q->next;
            q->next = t;
        }
    }
}
void deleteFirstNode() // deletion takes constant time
{
    Node *p=first;
      first = p->next;
    delete p;
}

void deleteAtGivenPosition(int pos)
{
    Node *p=first;
    Node *q= nullptr;
    if(pos<0)
    {
        return;
    }
    else if(pos==1)
    {
        first=p->next;
        delete p;
    }
    else
    {
        for(int i=0; i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        if (p) {
            q->next = p->next;
            delete p;
        }
    }
}

bool isSorted()
{
    Node *p=first;

    while (p->next!= nullptr)
    {
       if(p->data > p->next->data)
       {

           return false;
       }
       p=p->next;
    }
    return true;
}

bool sorted()
{
    int x=INT_MIN;
    Node *p=first;
    while (p!= nullptr)
    {
        if(p->data < x)
        {
            return false;
        }
        x=p->data;
        p=p->next;
    }
    return true;
}



void removeDuplicatesInSortedList(Node *p)
{

    Node *q=p->next;

    while(q!=nullptr)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
void reversingByChangingElements(Node *p) // we just change the value of the nodes, their addresses stay the same!!
{
    int i=0;
    int *arr=new int[nodeNumber(p)];
    p=first;
    while(p!= nullptr) //copying all elements from linked list to array
    {
        arr[i]=p->data;
        p=p->next;
        i++;
    }

    p=first;
    i--;
    while(p!= nullptr) //copying all the elements from array to linked list
    {
        p->data=arr[i];
        i--;
        p=p->next;
    }
    delete []arr;
}

void reverseBySlidingPointers(Node *p)
{
    Node *q= nullptr;
    Node *r= nullptr;

    while(p!= nullptr)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void concatenate(Node *p, Node *q)
{

    third=p;
    while(p->next!= nullptr)
    {
        p=p->next;
    }
    p->next=q;
}

void merge(Node *p, Node *q)
{
    first=p;
    Node *last= nullptr;
    if(p->data > q ->data)
    {
        third=q;
        last=third;
        q=q->next;
        last->next= nullptr;
    }
    else
    {
        third=p;
        last=p;
        p=p ->next;
        last->next= nullptr;
    }

    while (p && q)
    {
      if(p->data < q ->data)
      {
          last->next=p;
          last=p;
          p=p->next;
          last->next= nullptr;

      }
      else
      {
          last->next= q;
          last=q;
          q=q->next;
          last->next= nullptr;
      }
    }

    if(p!= nullptr)
    {
        last->next=p;

    }
    if(q!= nullptr)
    {
        last->next=q;
    }


}
bool hasLoop(Node *p) //we take two pinters and we move p by one step and q by 2 steps if they are equal it means we have a cycle
{

    Node *q=p;

    while(p && q)
    {
        p=p->next;
        q=q->next;
        q=q->next;
        if(p==q)
        {
            return true;
        }
    }
    return false;
}
int main()
{
  //  int arr[]={1,1,2,3,3,4,6};
//    create(arr,7);
//    insertInSortedList(first,5);
  //  display(first);
 //   std::cout<<std::endl;
//    deleteFirstNode();
 //   display(first);
 //   std::cout<<std::endl;
//    deleteAtGivenPosition(3);
//    display(first);
 //   std::cout<<isSorted();
    //removeDuplicatesInSortedList(first);
    //display(first);
    //std::cout<<std::endl;
    //reverseBySlidingPointers(first);
    //reversingByChangingElements(first);
    int arr2[]={5,6,7,8,9};
    create2(arr2,5);
    //merge(first,second);
   // concatenate(second,first);
    //display(third);

    //creating a loop
    Node *t1=second->next->next;
    Node *t2=second->next->next->next->next;
    t2->next=t1;

    std::cout<<hasLoop(second);

    return 0;
}
