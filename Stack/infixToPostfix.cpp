#include <iostream>
#include <stack>
#include <cstring>
bool isOperand(char c)
{
    return !(c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
//идея на решението: Взимаме един стек и заделяме динамично памет с дължината на подадения низ, правим проверка,ако текушият символ е операнд просто го 
//просто го добавяме към динамично заделеният масив, ако е операция обаче:
//1)ако стекът е празен добавяме операцията в него
//2)ако не е: проверяваме дали прецеденцията на текущият символ е по-голяма от тази на символът,който е на върха на стека
//ако да:
//просто я push-ваме в стека
//ако не: взимаме операцията, която е на st.top и я добавяме към динамичния масив
//работи з лявоасоциативни операции!!!!
char *convert(char *infix)  //reverse polish notation - тоест а+б, аб+, в това решение правим записът само за операции от ляво на дясно(лявоасоциативни)
{
    char *postfix=new char[strlen(infix)+1];
    std::stack<char> st;
    int i=0; int j=0;
    while (infix[i]) {
        if (isOperand(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            if (st.empty()) {
                st.push(infix[i]);
                i++;
            } else {
                if (precedence(infix[i]) > precedence(st.top())) {
                    st.push(infix[i]);
                    i++;
                } else {
                    char el = st.top();
                    st.pop();
                    postfix[j] = el;
                    j++;


                }

            }
        }

    }
        while (!st.empty()) {
            char symb = st.top();
            st.pop();
            postfix[j] = symb;
            j++;
        }
        postfix[j]='\0';
    return postfix;
}

int main() {

    char arr[]={"a*b+c"};
    char *a=convert(arr);
    std::cout<<a;

    return 0;
}
