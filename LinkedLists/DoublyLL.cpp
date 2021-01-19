#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL
{
private:
    Node *head;
public:
    DoublyLL(int A[], int n);
    ~DoublyLL();
    void display();
    int length();
    void insertNode(int pos, int x);
    int deleteNode(int pos);
    void reverse();
};

DoublyLL::DoublyLL(int A[], int n)
{
    Node *last, *t;
    int i;

    head = new Node;
    head->data = A[0];
    head->prev = NULL;
    head->next = NULL;

    last = head;

    for (i = 1 ; i < n ; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void DoublyLL::display()
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " " ;
        p = p->next;
    }
    cout << endl;
}

int DoublyLL::length()
{
    Node *p = head;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void DoublyLL::insertNode(int pos, int x)
{
    Node *p = head;
    Node *t;
    int i;

    if (pos < 0 || pos > length())
        return;

    t = new Node;
    t->data = x;

    if (pos == 0)
    {
        t->prev = NULL;
        t->next = head->next;
        head->prev = t;
        head = t;
    }
    else
    {
        for (i = 0; i < pos-1 ; i++)
            p = p->next;

        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int DoublyLL::deleteNode(int pos)
{
    Node *p = head;
    int i, x = -1;

    if (pos < 1 || pos > length())
        return x;
    
    if (pos == 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        
    }
    else
    {
        for (i = 0; i < pos-1 ; i++)
            p = p->next;
        
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        
    }

    x = p->data;
    delete p;
    
    return x;
}

void DoublyLL::reverse()
{
    Node *p = head;
    Node *temp;

    while (p)
    {
        if (p->next == NULL)
            head = p;
            
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;
    }
}

DoublyLL::~DoublyLL()
{
    Node *p;
    while (head)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

int main()
{
    int A[] = {1,2,4,5,6,6,7,8,90};
    DoublyLL dl(A, 9);
    dl.display();
    cout << "Length: " <<dl.length() << endl;
    dl.reverse();
    dl.display();
    return 0;
}