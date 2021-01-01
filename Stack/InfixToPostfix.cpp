#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class Stack
{
private:
    T *st;
    int size;
    int top;
public:
    Stack()
    {
        size = 10;
        top = -1;
        st = new T[size];
    }
    Stack(int n)
    {
        size = n;
        top = -1;
        st = new T[size];
    }
    int isFull();
    int isEmpty();
    T stackTop();
    void push(T n);
    T pop();
    T peek(int index);
    void display();
};

template<class T>
int Stack<T>::isFull()
{
    return top == (size - 1);
}

template<class T>
int Stack<T>::isEmpty()
{
    return top == -1;
}

template<class T>
T Stack<T>::stackTop()
{
    if (isEmpty())
        return -1;
    return st[top];
}

template<class T>
void Stack<T>::push(T n)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    st[top] = n;
}

template<class T>
T Stack<T>::pop()
{
    T x;
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    x = st[top];
    top--;
    return x;
}

template<class T>
T Stack<T>::peek(int index)
{
    T x = -1;

    if (top-index+1 < 0)
        cout << "Invalid Index";
    else
        x=st[top-index+1];

    return x;
}

template<class T>
void Stack<T>::display()
{
    int i;
    for (i = top; i >= 0; i--)
        cout<<st[i]<<" ";
    cout<<endl;
}

// Fuctions to convert infix to Postfix

int isOperand(char x)
{
    if( x == '+' || x == '-' || x == '*' || x == '/' )
        return 0;
    else
        return 1;
}

int optPre(char x)
{
    if( x == '+' || x == '-' )
        return 1;
    else if( x == '*' || x == '/' )
        return 2;
    else
        return 0;
}

char* InfixtoPostfix(char* infix)
{
    int i = 0, j = 0;
    Stack<char> stk(strlen(infix) + 1);
    char *postfix = new char[strlen(infix) + 1];

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (optPre(infix[i]) > optPre(stk.stackTop()))
                stk.push(infix[i++]);
            else
                postfix[j++] = stk.pop();
        }
    }
    while (!stk.isEmpty())
    {
        postfix[j++] = stk.pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char infix[] = "a+b*c-d/e";
    char *postfix = InfixtoPostfix(infix);

    cout << postfix;
    return 0;
}