#include <iostream>
#include <cstring>
#include <stack>
#include <functional>

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


template <typename T>
void reverse(Node<T>*&first)
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
        Node<T>*q= nullptr;
        Node<T>*r= nullptr;
        while (p->next!= nullptr)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        p->next=q;
        first=p;
}

template <typename T>
bool isPalyndrome(Node<T>*first)
{
    Node<T> *p=first;
    std::stack<T> st;
    while (p!= nullptr)
    {
        st.push(p->data);
        p=p->next;
    }

    p=first;
    while (p!= nullptr)
    {
        if(p->data==st.top())
        {
            st.pop();
        }
        else
        {
            return false;
        }
        p=p->next;
    }
    return true;
}


template <typename T>
bool isSubsequence(Node<T>*first,Node<T>*second) //checks whether the second list is a sublist of the first one
{
    if(second== nullptr)
    {
        return true;
    }
    if(count(first)<count(second))
    {
        return false;
    }
    Node<T>*p=first;
    int secCount=count(second);
    while (p!= nullptr)
    {
            Node<T>*tmp2=second;
            Node<T>*tmp1=p;
            while (tmp1!= nullptr && tmp2!= nullptr &&tmp1->data==tmp2->data) {
                tmp1=tmp1->next;
                tmp2=tmp2->next;
                secCount--;
            }
            if(secCount==0)
            {
                return true;
            }

        p=p->next;
    }
    return false;
}
template <typename T>
int subsequencesCount(Node<T>*first,Node<T>*second) //проверка колко пъти second се среща във first
{
    int counter=0;
    if(second== nullptr)
    {
        return counter;
    }
    if(count(first)<count(second))
    {
        return counter;
    }
    Node<T>*p=first;

    while (p!= nullptr)
    {
        Node<T>*tmp2=second;
        Node<T>*tmp1=p;
        int secCount=count(second);
        while (tmp1!= nullptr && tmp2!= nullptr &&tmp1->data==tmp2->data) {
            tmp1=tmp1->next;
            tmp2=tmp2->next;
            secCount--;
        }
        if(secCount==0)
        {
            counter++;
        }

        p=p->next;
    }
    return counter;
}
template <typename T>
bool isKTimes(Node<T>*first,Node<T>*second, int k)
{
    int counter=0;
    counter=subsequencesCount(first,second);
    return k == counter;
}


using pred=std::function<bool(int)>;  //takes int and returns bool
void project(Node<int>*l,pred p,Node<int>*&l1,Node<int>*&l2 )
//функцията създава и връща чрез l1 списък на всички елементи na четни позиции, за които p е истина
//създава и връща чрез l2 списък на всички елементи на нечетна позиция, за който р е истина
{
        l1= nullptr;
        l2= nullptr;

        if(l== nullptr)
        {
            return;
        }
        Node<int>*t=l;
        Node<int>*q= nullptr;
        Node<int>*r= nullptr;
        for(int i=0; i<count(l);i++)
        {
            if(i%2==0)
            {
               if(p(t->data))
               {
                   Node<int>*h=new Node<int>;
                 if(l1== nullptr)
                 {

                     h->data=t->data;
                     h->next= nullptr;
                     q=h;
                     l1=h;
                 }
                 else
                 {
                     h->data=t->data;
                     h->next= nullptr;
                     q->next=h;
                     q=h;
                 }
               }
            }
            else
            {
                if(p(t->data))
                {
                    Node<int>*h=new Node<int>;
                    if(l2== nullptr)
                    {

                        h->data=t->data;
                        h->next= nullptr;
                        r=h;
                        l2=h;

                    }
                    else
                    {
                        h->data=t->data;
                        h->next= nullptr;
                        r->next=h;
                        r=h;
                    }
                }
            }
            t=t->next;

        }
}

void split(Node<int> *l, pred p, Node<int> *&l1, Node<int> *&l2) {
    l1 = nullptr;
    l2 = nullptr;

    if (l == nullptr) {
        return;
    }
    Node<int> *t = l;
    Node<int> *q = nullptr;
    Node<int> *r = nullptr;
    for (int i = 0; i < count(l); i++)
    {
        if (p(t->data))
        {
            Node<int> *h = new Node<int>;
            if (l1 == nullptr) {

                h->data = t->data;
                h->next = nullptr;
                l1 = h;
                q = h;
            }
            else{

                h->data = t->data;
                h->next = nullptr;
                q->next = h;
                q=h;

               }
        }
        else {
            Node<int> *h = new Node<int>;
            if (l2 == nullptr) {

                h->data = t->data;
                h->next = nullptr;
                l2 = h;
                r = h;
            } else {

                h->data = t->data;
                h->next = nullptr;
                r->next = h;
                r=h;

            }
        }

        t = t->next;
    }
}

using predicate=std::function<bool(int,int)>;
void zip(Node<int>*l1, Node <int>*l2,predicate p, Node<int>*&l3)
{
    if(l1== nullptr)
    {
        return;
    }
    if(l2== nullptr)
    {
        return;
    }
    l3= nullptr;
    Node<int>*t= nullptr;
    while (l1!= nullptr)
    {
        if(p(l1->data,l2->data))
        {
            Node<int>*h=new Node<int>;
            if(l3== nullptr)
            {
                h->data=l1->data+l2->data;
                h->next= nullptr;
                l3=h;
                t=h;

            }
            else
            {
                h->data=l1->data+l2->data;
                h->next= nullptr;
                t->next=h;
                t=h;
            }
        }
        l1=l1->next;
        l2=l2->next;
    }
}


template <typename T>
void merge(Node<T>*&first,Node<T>*second)
{
        if(second== nullptr)
        {
            return;
        }
        if(first== nullptr){
            first=second;
        }

        Node<T>*f= first;
        Node<T>*last= nullptr;
        if(f->data<second->data)
        {
            last=first;
            f=f->next;
            last->next= nullptr;
        }
        else
        {
            first=last=second;
            second=second->next;
            last->next= nullptr;
        }

        while (f!= nullptr && second!= nullptr)
        {
            if(f->data<second->data)
            {
                last->next=f;
                last=f;
                f=f->next;
                last->next= nullptr;
            }
            else
            {
                last->next=second;
                last=second;
                second=second->next;
                last->next= nullptr;
            }
        }

        if(f!= nullptr)
        {
            last->next=f;
        }
        if(second!= nullptr)
        {
            last->next=second;
        }








}

int main() {

    int arr[]={1,2,3,1,2,3,1,2};
    Node<int>*first=create<int>(arr,8);
    //print(first);
    //mirror(first);
   // fillGaps(first);
 //  removeDups(first);
   // print(first);


   // char str[]={"11 21"};
  //  Node<char>*head=create<char>(str,strlen(str));
    //reverse(head);
    //print(head);
  //  std::cout<<isPalyndrome(head);

//
//  int arr2[]={1,2};
//  Node<int>*sec=create<int>(arr2,2);
//  std::cout<<isSubsequence(first,sec)<<std::endl;
//  std::cout<<subsequencesCount(first,sec)<<std::endl;
//  std::cout<<isKTimes(first,sec,3);



    int a[]={1,6,4,3,8,8};

    Node<int>*list=create<int>(a,6);
    Node<int>*l1= nullptr;
    Node <int>*l2= nullptr;


   // project(list,[](int x){return x>3;},l1,l2);
   // split(list,[](int x){ return x%2==0;},l1,l2);
  //  print(l1);
//    print(l2);


    int array[]={2,8,10,15};
    int b[]={4,7,12,14};
    Node<int>*l=create<int>(array,4);
    Node<int>*lb=create<int>(b,4);
    Node<int>*l3= nullptr;
  //  zip(l,lb,[](int x,int y){ return y%x==0;},l3); //едно число дели друго точно когато остатъкът е равен на 0
    //print(l3);
    merge<int>(l,lb);
    print(l);


    return 0;
}
