#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class AddressNode
{
public:
    Node *NodeAddress;
    AddressNode *next;
};

class Stack
{
private: 
    AddressNode *top;
public:
    Stack() { top = NULL; }
    void push(Node *x);
    Node* pop();
    int isEmpty() {return top == NULL;}
    int isFull() 
    {
        AddressNode *t = new AddressNode;
        if (t == NULL)
        {
            delete t;
            return 1;
        }
        return 0;
    };
    Node* stackTop()
    {
        if (isEmpty())
            return NULL;

        return top->NodeAddress;
    }
};

void Stack::push(Node *x)
{
    AddressNode *t = new AddressNode;
    if (t == NULL)
        cout << "Stack is Full" << endl ;
    else
    {
        t->NodeAddress = x;
        t->next = top;
        top = t;
    }
}

Node* Stack::pop()
{
    AddressNode x;
    if (top == NULL)
        cout << "Stack is Empty" << endl ;
    else
    {
        AddressNode *p = top;
        x.NodeAddress = top->NodeAddress;
        top = top->next;
        delete p;
    }
    return x.NodeAddress;
}

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree(): root(NULL) {}
    void insert(int key);
    Node* getRoot() { return root; }
    void displayInorder(Node* p);
    Node* search(int key);
    int height(Node *p);
    Node* InPred(Node *p);
    Node* InSucc(Node *p);
    Node* recInsert(Node *p, int key);
    Node* recDelete(Node *p, int x);
    void createPreOrd(int pre[], int n);
    void createPostOrd(int pre[], int n);
    void createTree();
};

void BinarySearchTree::insert(int key)
{
    Node *p, *q, *t;
    p = root;

    if (root == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        root = t;
        return;
    }
    
    while (p != NULL)
    {
        q = p;
        if (key < p->data)
            p = p->lchild;
        else if (key > p->data)
            p = p->rchild;
        else
            return;
    }

    t = new Node;
    t->data = key;
    t->lchild = t->rchild = NULL;
    
    if (key > q->data)
        q->rchild = t;
    else
        q->lchild = t;
    
}

void BinarySearchTree::displayInorder(Node* p)
{
    if(p)
    {
        displayInorder(p->lchild);
        cout << p->data << " ";
        displayInorder(p->rchild);
    }
}

Node* BinarySearchTree::search(int key)
{
    Node *p = root;

    while (p)
    {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->lchild;
        else if (key > p->data)
            p = p->rchild;
    }
    return NULL;
}

Node* BinarySearchTree::recInsert(Node *p, int key)
{
    if (p == NULL)
    {
        Node *t;
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return NULL;
    }
    
    if (key < p->data)
        p->lchild = recInsert(p->lchild, key);
    if (key < p->data)
        p->rchild = recInsert(p->rchild, key);

    return NULL;
}

int BinarySearchTree::height(Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        if (x > y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

Node* BinarySearchTree::InPred(Node *p)
{
    p = p->lchild;
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

Node* BinarySearchTree::InSucc(Node *p)
{
    p = p->rchild;
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

Node* BinarySearchTree::recDelete(Node *p, int x)
{
    if (p == NULL)
        return NULL;
    if (!p->lchild && !p->rchild)
    {
        if (p==root)
            root = NULL;
        delete p;
        return NULL;
    }

    if (x < p->data)
        p->lchild = recDelete(p->lchild, x);
    else if (x > p->data)
        p->rchild = recDelete(p->rchild, x);
    else
    {
        Node *q;
        if(height(p->lchild) > height(p->rchild))
        {
            q = InPred(p);
            p->data = q->data;
            p->lchild = recDelete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p);
            p->data = q->data;
            p->rchild = recDelete(p->rchild, q->data);
        }
    }
    
    return p;
}

void BinarySearchTree::createPreOrd(int pre[], int n)
{
    Stack stk;
    Node *p, *t;
    int i = 0;

    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;

    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (pre[i] > p->data && (stk.isEmpty() ? true : pre[i] < stk.stackTop()->data))
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
                p = stk.pop();
        }
    }
}

void BinarySearchTree::createPostOrd(int pre[], int n)
{
    Stack stk;
    Node *p, *t;
    int i = n-1;

    root = new Node;
    root->data = pre[i--];
    root->lchild = root->rchild = NULL;
    p = root;

    while (i >= 0)
    {
        if (pre[i] > p->data)
        {
            t = new Node;
            t->data = pre[i--];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            stk.push(p);
            p = t;
        }
        else
        {
            if (pre[i] < p->data && (stk.isEmpty() ? true : pre[i] > stk.stackTop()->data))
            {
                t = new Node;
                t->data = pre[i--];
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                p = t;
            }
            else
                p = stk.pop();
        }
    }
}

int main(void)
{
    BinarySearchTree BST;
    // BST.insert(3);
    // BST.insert(1);
    // BST.insert(5);
    // BST.insert(2);
    // BST.insert(4);

    int a[5] = {3, 2, 1, 4, 5};
    int b[5] = {1, 2, 5, 4, 3};

    // BST.createPreOrd(a, 5);
    BST.createPostOrd(b, 5);

    BST.displayInorder(BST.getRoot());
    BST.recDelete(BST.getRoot(), 3);
    BST.recDelete(BST.getRoot(), 5);
    BST.insert(8);
    cout << endl;
    BST.displayInorder(BST.getRoot());
    cout << endl;

    if(BST.search(3))
    {
        cout << "It is Found! " << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }
    
    return 0;
}