#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    CircularQueue(): size(10), front(0), rear(0) { Q = new int[size]; }
    CircularQueue(int n): size(n), front(0), rear(0) { Q = new int[size]; }

    int isFull();
    int isEmpty();
    void enqueue(int x);
    int dequeue();
    void Display();
};

int CircularQueue::isFull()
{
    return (rear+1)%size == front;
}

int CircularQueue::isEmpty()
{
    return front == rear;
}

void CircularQueue::enqueue(int x)
{
    if (isFull())
        cout << "Queue Full!" << endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if (isEmpty())
        cout << "Queue Empty!" << endl;
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::Display()
{
    int i = front+1;

    do
    {
        cout << Q[i] << " ";
        i = (i+1)%size;
    }while(i != (rear+1)%size);

    cout << endl;
}

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.enqueue(70);
    q.enqueue(80);
    q.dequeue();
    q.enqueue(100);

    q.Display();
    cout << q.dequeue() << endl;
    q.Display();
    
    return 0;
}