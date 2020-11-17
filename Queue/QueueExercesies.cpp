#include <iostream>
#include <stack>
#include <queue>
void print(std::queue <int> q)  //works with a copy of the actual data
{
    while (!q.empty())
    {
        std::cout<<q.front()<<" ";
        q.pop();
    }
    std::cout<<std::endl;

}

void printOriginal(std::queue<int> q)
{
    int size=q.size();
    for(int i=0; i<size;i++)
    {
        int currentElement=q.front();
        std::cout<<q.front()<<" ";
        q.pop();
        q.push(currentElement);
    }
    std::cout<<std::endl;

}



void test()
{
    std::queue<int> q;

    q.push(5);
    q.push(6);
    q.push(7);


    //std::cout<<q.back()<<std::endl; //gives the last element in the queue;
    //std::cout<<q.front()<<std::endl; //gives the first element in the queue;
    //std::cout<<q.size()<<std::endl;
    //print(q);
    q.pop(); //pops the first element of the queue
    std::cout<<"Elements of q"<<std::endl;
    print(q);

    std::queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    std::cout<<"Elements of q1"<<std::endl;
    print(q1);
    std::cout<<std::endl;

    q.swap(q1);//swaps elements of both queues
    print(q);
    print(q1);
}


int findMin(std::queue<int>q)  //works with a copy of the actual data
{
    int minElement=INT_MAX;
    while (!q.empty())
    {
        int elem=q.front();
        q.pop();
        if(elem<minElement)
        {
            minElement=elem;
        }

    }
    return minElement;
}

void removeOdds(std::queue <int>& q)
{
    int size=q.size();
    for(int i=0; i<size;i++)
    {
        int currentElement=q.front();
        if(currentElement%2==0)
        {
            q.push(currentElement);
        }
        q.pop();
    }
}

void reverse(std::queue<int>&q)
{
    std::stack<int>st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

}

int nthSequence(int num, int seqNum)
{
    std::queue<int> q;
    q.push(num);
    while (--seqNum)
    {
        q.push(q.front()+1);
        q.push(q.front()*2);
        q.pop();
    }
    return q.front();

}
//std::queue <int>&
std::queue<int> merge(std::queue <int>q, std::queue<int> r)  //ако искам функцията е с референция, трябва вътре да заделям в хийпа с указател от тип queue и да връшам резултата
{
   // std::queue<int>*result=new std::queue<int>();
    std::queue<int>three;
    while (!q.empty() && !r.empty())
    {
        if(q.front()<=r.front())
        {
            three.push(q.front());
            q.pop();
        }
        else
        {
            three.push(r.front());
            r.pop();
        }
    }

    while (!q.empty() && r.empty())
    {
        three.push(q.front());
        q.pop();
    }

    while (q.empty() && !r.empty())
    {
         three.push(r.front());
        r.pop();
    }

    //return *result;
    return three;

}


void printBinaries(int n) {
    // Правим си опашка от стрингове и добавяме "1"
    std::queue<std::string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        // Следващите числа в двоичен запис се получават като от текущото
        // най-малко добавим нула и единица най-отзад. Тези две нови числа
        // ги добавяме към опашката.
        std::string front = q.front();
        q.pop();
       std:: cout << front << std::endl;

        q.push(front + "0");
        q.push(front + "1");
    }
}


int main() {

    std::queue<int> q;
    q.push(1);
    q.push(5);
    q.push(7);
  //  std::cout<<findMin(q);
    //removeOdds(q);
 // printOriginal(q);
  //  reverse(q);
   // printOriginal(q);

   //std::cout<<nthSequence(42,4);
   std::queue<int>r;
   r.push(3);
   r.push(4);
   r.push(6);


   std::queue<int> three=merge(q,r);
   printOriginal(three);


   printBinaries(5);
    return 0;
}
