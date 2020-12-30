#include <iostream>
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


int main()
{
    Stack<char> stk(5);
    stk.push('a');
    stk.push('b');
    stk.push('c');
    stk.push('d');
    stk.push('e');
    stk.push('f');

    stk.display();

    cout<<stk.peek(1)<<endl;

    return 0;
}