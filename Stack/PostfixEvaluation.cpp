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

// Functions to evaluate an Postfix Expression

int isOperand(char x)
{
    if( x == '+' || x == '-' || x == '*' || x == '/' )
        return 0;
    else
        return 1;
}

int evaluate(char *postfix)
{
    int i, x1, x2, r;
    Stack<int> stk(strlen(postfix) + 1);
    for (i = 0; postfix[i] != '\0' ; i++)
    {
        if (isOperand(postfix[i]))
            stk.push(postfix[i] - '0');
        else
        {
            x2 = stk.pop();
            x1 = stk.pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 +  x2;
                stk.push(r);
                break;
            
            case '-':
                r = x1 -  x2;
                stk.push(r);
                break;
            
            case '*':
                r = x1 *  x2;
                stk.push(r);
                break;
            
            case '/':
                r = x1 /  x2;
                stk.push(r);
                break;
            
            default:
                break;
            }
        }
    }
    return stk.pop(); 
}

int main()
{
    char postfix[] = "35*62/+4-";
    cout << "Result: " << evaluate(postfix) << endl;
    return 0;
}