#include <iostream>
template <typename T>
class Stack
{
private:
    T *arr;
    int topIndex; //index of last element in stack
    int capacity; // capacity of stack

    void resize();
    void copyStack(const Stack& other);
    void copy(const T* stackArr);


public:
    
    Stack();
    Stack(const Stack &other);
    Stack &operator=(const Stack &other);
    ~Stack();

    void push(T x);
    void pop();
    bool isEmpty();
    bool isFull();
    T top();
    void display();

};
template <typename T>
Stack<T>::Stack():topIndex(-1),capacity(8) {
    arr=new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack &other)
{
    copyStack(other);
}

template <typename T>
void Stack<T>::copy(const T *stackArr)
{
    for(int i=0; i<capacity;i++)
    {
        arr[i]=stackArr[i];
    }

}
template <typename T>
Stack<T>&Stack<T>::operator=(const Stack &other)
{
    if(this!=other)
    {
        delete []arr;
        copyStack(other);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    delete []arr;
}
template<typename T>
void Stack<T>::copyStack(const Stack &other)
{
    topIndex=other.topIndex;
    capacity=other.capacity;
    arr=new T[capacity];
    copy(other.arr);
}
template <typename T>
void Stack<T>::resize()
{
    T* ptr=arr;
    arr=new T[2*capacity];
    copy(ptr);
    capacity=capacity*2;
    delete[]ptr;

}
template <typename T>
bool Stack<T>::isEmpty()
{
    return topIndex == -1;
}
template <typename T>
void Stack<T>::pop()
{
    if(!isEmpty())
    {
        topIndex--;
        return;
    }
    std::cout<<"Stack empty!"<<std::endl;
}
template <typename T>
T Stack<T>::top()
{
    if(!isEmpty())
    {
        return arr[topIndex];

    }
    std::cerr<<"Empty stack"<<std::endl;
    return T();

}
template <typename T>
bool Stack <T>::isFull()
{
    return topIndex == capacity - 1;
}

template <typename T>
void Stack <T>::push(T x)
{
    if(isFull()) {
        resize();
    }
        topIndex++;
        arr[topIndex]=x;

}

template <typename T>
void Stack<T>::display()
{
    while (!isEmpty())
    {
        std::cout<<top()<<std::endl;
        pop();
    }
}



int main() {

    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    

    
    std::cout<<st.isEmpty()<<std::endl;
    st.display();



    return 0;
}
