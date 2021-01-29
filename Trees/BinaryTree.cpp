#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *lchild, *rchild;
};

class AddressNode
{
public:
    TreeNode *NodeAddress;
    AddressNode *next;
};

class Stack
{
private: 
    AddressNode *top;
public:
    Stack() { top = NULL; }
    void push(TreeNode *x);
    TreeNode* pop();
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
};

void Stack::push(TreeNode *x)
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

TreeNode* Stack::pop()
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

class LLQueue
{
private:
    AddressNode *front;
    AddressNode *rear;
public:
    LLQueue() 
    {
        front = rear = NULL;
    }
    int isFull();
    int isEmpty();
    void enqueue(TreeNode *x);
    TreeNode* dequeue();
    void Display();
};

int LLQueue::isEmpty()
{
    return front == NULL;
}

int LLQueue::isFull()
{
    AddressNode *t;
    t = new AddressNode;
    if (t == NULL)
    {
        delete t;
        return 1;
    }
    return 0;
}

void LLQueue::enqueue(TreeNode *x)
{
    if (isFull())
        cout << "Queue Full!" << endl;
    else
    {
        AddressNode *t;
        t = new AddressNode;

        t->NodeAddress = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

TreeNode* LLQueue::dequeue()
{
    AddressNode x;
    x.NodeAddress = NULL;
    if (isEmpty())
        cout << "Queue Empty!" << endl;
    else
    {
        AddressNode *t;
        t = front;
        x.NodeAddress = front->NodeAddress;
        front = front->next;
        delete t;
    }
    return x.NodeAddress;
}

void LLQueue::Display()
{
    AddressNode *p = front;
    while (p != NULL)
    {
        cout << p->NodeAddress->data << " ";
        p = p->next;
    }
    cout << endl;
}

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree(): root(NULL) {};
    void CreateTree();
    TreeNode* getRootNode() { return root; }
    void PreOrder(TreeNode *p);
    void PostOrder(TreeNode *p); 
    void InOrder(TreeNode *p);
    void ItPreOrder();
    void ItInOrder();
    void ItPostOrder(); 
    void LevelOrder();
    int height(TreeNode *p);
    int nodeCount(TreeNode *p);
    int getDegNodes(TreeNode *p, int degree);
};

void BinaryTree::CreateTree()
{
    TreeNode *p, *t;
    int x;
    LLQueue Q;

    cout << "Enter the Root Value: ";
    cin >> x;

    root = new TreeNode;
    root->data = x;
    root->lchild = root->rchild = NULL;
    Q.enqueue(root);

    while (!Q.isEmpty())
    {
        p = Q.dequeue();
        cout << "Enter the Left child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Q.enqueue(t);
        }
        cout << "Enter the Right child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Q.enqueue(t);
        }
    }
}

void BinaryTree::PreOrder(TreeNode *p)
{
    if(p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void BinaryTree::PostOrder(TreeNode *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void BinaryTree::InOrder(TreeNode *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void BinaryTree::ItPreOrder()
{
    Stack stk;
    TreeNode *p = root;

    while(p || !stk.isEmpty())
    {
        if(p)
        {
            cout << p->data << " ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void BinaryTree::ItInOrder()
{
    Stack stk;
    TreeNode *p = root;

    while(p || !stk.isEmpty())
    {
        if(p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    cout << endl;
}

void BinaryTree::ItPostOrder()
{
    Stack stk;
    TreeNode *p = root;
    long int temp;

    while(p || !stk.isEmpty())
    {
        if(p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            temp = (int)stk.pop();
            if (temp > 0)
            {
                stk.push((TreeNode *)-temp);
                p = p->rchild;
            }
            else
            {
                cout << p->data << " ";
                p = NULL;
            }
        }
    }
    cout << endl;
}

void BinaryTree::LevelOrder()
{
    LLQueue Q;
    TreeNode *p = root;
    cout << p->data << " ";
    Q.enqueue(p);
    while (!Q.isEmpty())
    {
        p = Q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            Q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            Q.enqueue(p->rchild);
        }
    }
    cout << endl;
}
int BinaryTree::height(TreeNode *p)
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
int BinaryTree::nodeCount(TreeNode *p)
{
    int x, y;
    if (p != NULL)
    {
        x = height(p->lchild);
        y = height(p->rchild);
        return x+y+1;
    }
    return 0;
}
int BinaryTree::getDegNodes(TreeNode *p, int degree)
{
    int x, y;
    if (p != NULL)
    {
        x = getDegNodes(p, degree);
        y = getDegNodes(p, degree);

        if (degree == 0)
        {
            if (!p->lchild && !p->rchild)
                return x+y+1;
            return x+y;
        }
        else if(degree == 2)
        {
            if (p->lchild && p->rchild)
                return x+y+1;
            return x+y;
        }
        else if (degree == 1)
        {
            if ((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
                return x+y+1;
            return x+y;
        }
    }
    return 0;
}

int main(void)
{
    BinaryTree Tr;
    Tr.CreateTree();

    Tr.PreOrder(Tr.getRootNode());
    cout << endl;
    Tr.InOrder(Tr.getRootNode());
    cout << endl;
    Tr.PostOrder(Tr.getRootNode());
    cout << endl;
    Tr.LevelOrder();
}