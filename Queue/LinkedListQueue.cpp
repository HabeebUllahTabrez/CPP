#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LLQueue
{
private:
    Node *front;
    Node *rear;
public:
    LLQueue() 
    {
        front = rear = NULL;
    }
    int isFull();
    int isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

int LLQueue::isEmpty()
{
    return front == NULL;
}

int LLQueue::isFull()
{
    Node *t;
    t = new Node;
    if (t == NULL)
    {
        delete t;
        return 1;
    }
    return 0;
}

void LLQueue::enqueue(int x)
{
    if (isFull())
        cout << "Queue Full!" << endl;
    else
    {
        Node *t;
        t = new Node;

        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        rear->next = t;
        rear = t;
    }
}

int LLQueue::dequeue()
{
    int x = -1;
    if (isEmpty())
        cout << "Queue Empty!" << endl;
    else
    {
        Node *t;
        t = new Node;
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void LLQueue::display()
{
    Node *p = front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(void)
{
    LLQueue Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);

    Q.display();
    Q.dequeue();
    Q.display();


    return 0;
}