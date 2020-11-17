#include <iostream>
#include <stack>
template <typename T>
class Queue
{
    std::stack<T> st1;
    std::stack<T> st2;

public:
    void enqueue(T x);
    T dequeue();
};

template<typename T>
void Queue<T>::enqueue(T x) {
   st1.push(x);

}

template<typename T>
T Queue<T>::dequeue() {
    T value;
    if(st2.empty())
    {
        if(st1.empty())
        {
            std::cerr<<"Queue is empty";
            return T();
        }
        else
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
    }
    value=st2.top();
    st2.pop();
    return value;
}


int main() {
    Queue <int> q;
    q.enqueue(5);
    q.enqueue(6);
    int value=q.dequeue();
    std::cout<<value<<std::endl;
    return 0;
}
