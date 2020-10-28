#include <iostream>
using namespace std;

// class for each node in a linked list
class Node
{
public:
    int data;
    Node *next;
};

// class for linked list
class LinkedList
{
private:
    Node *head;
public:
    LinkedList() { head = NULL; }
    LinkedList(int A[], int n);
    ~LinkedList();

    Node* getHead() { return head; }
    void display();
    int getLength();
    int getSum();
    int getMax();
    int getMin();
    Node* lSearch(int key);
    void insertNode(int pos, int x);
    void sortedInsert(int x);
    int deleteNode(int pos);
    int isSorted();
    void removeDuplicates();
    void reverseList();
    void recReverseList(Node *q, Node *p);
    Node* concat(Node *q);
    Node* mergeSorted(Node *q);
    int isLoop();
};

LinkedList::LinkedList(int A[], int n) 
{
    int i;
    Node *t, *tail;
    head = new Node;

    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (i = 1; i < n ; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = head;
    while (head)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::display()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::getLength()
{
    Node *p = head;
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int LinkedList::getSum()
{
    Node *p = head;
    int s = 0;
    while (p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int LinkedList::getMax()
{
    Node *p = head;
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int LinkedList::getMin()
{
    Node *p = head;
    int min = INT32_MAX;
    while (p)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

Node* LinkedList::lSearch(int key)
{
    Node *p = head;
    Node *q = NULL;
    if (key == p->data)
        return p;
    while (p)
    {
        q = p;
        p = p->next;
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
    }
    return NULL;
}

void LinkedList::insertNode(int pos, int x)
{
    Node *p = head;
    Node *t;
    int i;

    if (pos < 0 || pos > getLength())
        return;
    
    t = new Node;
    t->data = x;

    if (pos == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (i = 0; i < pos-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void LinkedList::sortedInsert(int x)
{
    Node *p = head;
    Node *t, *q;
    t = new Node;

    t->data = x;
    t->next = NULL;

    if (head == NULL)
        head = t;
    else
    {
        while (p && (p->data < x))
        {
            q = p;
            p = p->next;
        }
        if (p == head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int LinkedList::deleteNode(int pos)
{
    Node *p = head;
    Node *q;
    int x=-1, i;

    if (pos < 1 || pos > getLength())
        return x;
    
    if (pos == 1)
    {
        q = head;
        x = q->data;
        head = head->next;
        delete q;
        return x;
    }
    else
    {
        for (i = 0; i < pos-1 ; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int LinkedList::isSorted()
{
    Node *p = head;
    int x = INT32_MIN;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return -1;
        }
        x = p->data;
        p = p->next;    
    }
    return 1;
}

void LinkedList::removeDuplicates()
{
    Node *p = head;
    Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void LinkedList::reverseList()
{
    Node *p = head;
    Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void LinkedList::recReverseList(Node *q, Node *p)
{
    if (p)
    {
        recReverseList(p, p->next);
        p->next = q;
    }
    else
        head = q;
}

Node* LinkedList::concat(Node *q)
{
    Node *p = head;
    Node *third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    return third;
}

Node* LinkedList::mergeSorted(Node *q)
{
    Node *p = head;
    Node *tail, *third;
    if (p->data < q->data)
    {
        third = tail = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = tail = q;
        q = q->next;
        third->next = NULL;
    }
    
    while (p && q)
    {
        if (p->data < q->data)
        {
            tail->next = p;
            tail = p;
            p = p->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = q;
            tail = q;
            q = q->next;
            tail->next = NULL;
        }
    }
    if (p)
    {
        tail->next = p;
    }
    else
    {
        tail->next = q;
    }
    
    return third;
}

int LinkedList::isLoop()
{
    Node *f = head;
    Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } while ((p && q) && (p != q));

    return p == q ? 1 : -1;
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int A[] = {-5,2,5,69,69,100,420};
    int B[] = {4,6,9,10,99,1000};
    LinkedList l1(A, 7);
    LinkedList l2(B, 6);
    Node *third;

    cout << "First: " << endl;
    l1.display();
    cout << "Second: " << endl;
    l2.display();

    third = l1.mergeSorted(l2.getHead());
    cout << "Third: " << endl;
    display(third);

    return 0;
}