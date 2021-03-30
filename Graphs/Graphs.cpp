#include<iostream>
using namespace std;

/* ------------------- QUEUE --------------------- */

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

/* ----------------------------------------------------- */

class Graphs
{
    int G[7][7];
    int n;
public:
    Graphs() : G {
                    {0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}
                }, n(7) {};
    void BFS(int start)
    {
        int i = start;
        LLQueue Q;
        int visited[7] = {0};

        cout << i << " ";
        visited[i] = 1;
        Q.enqueue(i);

        while (!Q.isEmpty())
        {
            i = Q.dequeue();
            for (int j = 1; j < n; j++)
            {
                if (G[i][j] == 1 && visited[j] == 0)
                {
                    cout << j << " ";
                    visited[j] = 1;
                    Q.enqueue(j);
                }
            }
        }
    }
    void DFS(int start)
    {
        static int visited[7] = {0};
        if (visited[start] == 0)
        {
            cout << start << " ";
            visited[start] = 1;
            for (int j = 1; j < n; j++)
            {
                if (G[start][j] == 1 && visited[j] == 0)
                    DFS(j);
            }
        }
    }
};

int main()
{
    Graphs gr;
    // gr.BFS(5);
    gr.DFS(4);
    
    return 0;
}
