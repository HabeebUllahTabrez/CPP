#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CLinkedList
{
private:
    Node *head;
public:
    CLinkedList() { head = NULL; }
    CLinkedList(int A[], int n);
    ~CLinkedList();

    void display();
    int length();
    void insert(int pos, int x);
    int deleteNode(int pos);
};

CLinkedList::CLinkedList(int A[], int n) 
{
    int i;
    Node *t, *tail;
    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (i = 1; i < n ; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CLinkedList::display()
{
    Node *h = head;
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << endl;
}

int CLinkedList::length()
{
    Node *p = head;
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void CLinkedList::insert(int pos, int x)
{
    Node *p, *t;
    int i;

    if (pos < 0 || pos > length())
        return;

    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < pos-1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int CLinkedList::deleteNode(int pos)
{
    Node *p = head;
    Node *q;
    int i, x;

    if (pos < 1 || pos > length())
        return -1;
    
    if (pos == 1)
    {
        x = head->data;
        while (p->next != head)
            p = p->next; 
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < pos-2 ; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    
    return x;
}

CLinkedList::~CLinkedList()
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
    int A[]= {1,2,3,3,45,543};
    CLinkedList cl(A, 6);
    cl.display();
    cl.insert(0, 2);
    cl.deleteNode(4);
    cl.display();
    
    return 0;
}