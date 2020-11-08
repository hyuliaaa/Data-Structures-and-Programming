#include <iostream>
#include <cstring>
#include <cmath>
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

    void getStr(const char *str);
    void pushString(const char *str);
    bool validBrackets(const char *str);



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
        std::cout<<top();
        pop();
    }
}

template <typename T>
void Stack<T>::getStr(const char *str)
{

        for(int i=0; str[i];i++)
        {
            push(str[i]);
        }
        display();

}

template <typename T>
void Stack<T>::pushString(const char*str)
{
    for(int i=0; str[i];i++)
    {
        push(str[i]);
    }
}

template <typename T>
bool Stack<T>::validBrackets(const char* str)
{

}
template<typename T>
int countElements(Stack <T>st)
{
    int counter=0;
    while(!st.isEmpty())
    {
        counter++;
        st.pop();
    }
    return counter;
}

bool arePair(char opening, char closing)
{
    if(opening=='(' && closing==')')
    {
        return true;
    }
    else if (opening=='{' && closing=='}')
    {
        return true;
    }
    else if(opening=='[' && closing==']')
    {
        return true;
    }
    return false;
}

bool validParenthesis(const char *str)
{
    Stack <char> st;
    int len=strlen(str);
    for(int i=0; i<len;i++)
    {
        if(str[i]=='{' || str[i]=='[' || str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]=='}' || str[i]==']' || str[i]==')')
        {
            if(st.isEmpty() || !arePair(st.top(),str[i]))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.isEmpty();
}


double apply(char op, double first, double second)
{
    switch (op)
    {
        case '+':
            return first+second;
        case '-':
            return first-second;
        case '*':
            return first*second;
        case '/':
            return first/second;
        case '^':
            return pow(first,second);
        default:
            return 0;
    }
}

double reversePolishNotation(const char *str) //обратен полски запис
{
    Stack <double> st;
    for(int i=0; str[i]; i++)
    {
        if(isdigit(str[i]))
        {
            st.push(str[i]-'0');
        }
        else
        {
            double first=st.top();
            st.pop();
            double second=st.top();
            st.pop();
            st.push(apply(str[i],first,second));
        }
    }
    return st.top();
}

double polishNotation(const char *str) //полски запис
{
    Stack<double>st;
    Stack <char>op;
    for(int i=0; str[i];i++)
    {
        if(isdigit(str[i]))
        {
            st.push(str[i]-'0');
            if(countElements(st)>=2) {
                double first = st.top();
                st.pop();
                double second = st.top();
                st.pop();
                st.push(apply(op.top(), first, second));
                op.pop();
            }
        }
        else
        {
            op.push(str[i]);

        }
    }
    return st.top();
}


bool validExpression(const char *str) //проверява дали в израза има излишни скоби
{
    Stack <char> st;
    for(int i=0; str[i];i++)
    {
        if(str[i]=='(')
        {
            st.push(str[i]);
        }
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            if(st.top()!='#')
            {
                st.push('#');
            }
        }
        if(str[i]==')')
        {
            if(st.top()=='#')
            {
                st.pop();
                st.pop();
            }
            else
            {
                return true;
            }

        }
    }
    return false;
}
int main() {

    Stack <char> st;
  //  std::cout<<validParenthesis("((}})[]");
    //  std::cout<<reversePolishNotation("223+*6*");
  //  std::cout<<polishNotation("+*+1234");
  std::cout<<validExpression("(1+3)");


  //  st.display();



    return 0;
}
