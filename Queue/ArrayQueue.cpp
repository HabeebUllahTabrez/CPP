#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(): size(10), front(-1), rear(-1) { Q = new int[size]; }
    Queue(int n): size(n), front(-1), rear(-1) { Q = new int[size]; }

    int isFull();
    int isEmpty();
    void enqueue(int x);
    int dequeue();
    void Display();
};

int Queue::isFull()
{
    return rear == (size-1);
}

int Queue::isEmpty()
{
    return front == rear;
}

void Queue::enqueue(int x)
{
    if (isFull())
        cout << "Queue Full!" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (isEmpty())
        cout << "Queue Empty!" << endl;
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::Display()
{
    for(int i=front+1 ; i<=rear ; i++)
        cout << Q[i] << " ";
    cout << endl;
}

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(50);
    q.enqueue(100);

    q.Display();
    cout << q.dequeue() << endl;
    q.Display();
    
    return 0;
}