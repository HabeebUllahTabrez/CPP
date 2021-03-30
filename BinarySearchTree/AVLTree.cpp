#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
};

class AVLTree
{
public:
    Node *root;

    AVLTree(): root(NULL) {};
    Node* recInsert(Node *p, int key);
    int nodeHeight(Node *p);
    Node* getRoot() { return root; };
    int getBalanceFactor(Node *p);
    Node* LLRotation(Node *p);
    Node* LRRotation(Node *p);
    Node* RRRotation(Node *p);
    Node* RLRotation(Node *p);
};

int AVLTree::nodeHeight(Node *p)
{
    int hl, hr;
    
    hl = p && p->lchild ? (p->lchild->height) : 0;
    hr = p && p->rchild ? (p->rchild->height) : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVLTree::getBalanceFactor(Node *p)
{
    int hl, hr;
    
    hl = p && p->lchild ? (p->lchild->height) : 0;
    hr = p && p->rchild ? (p->rchild->height) : 0;

    return hl - hr;
}

Node* AVLTree::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

Node* AVLTree::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

Node* AVLTree::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = p;
    plr->lchild = pl;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

Node* AVLTree::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

Node* AVLTree::recInsert(Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    
    if (key < p->data)
        p->lchild = recInsert(p->lchild, key);
    if (key > p->data)
        p->rchild = recInsert(p->rchild, key);

    p->height = nodeHeight(p);

    if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}


int main(void)
{
    AVLTree at;

    // at.root = at.recInsert(at.getRoot(),30);
    // at.recInsert(at.getRoot(),20);
    // at.recInsert(at.getRoot(),10);
    // at.recInsert(at.getRoot(),9);
    // at.recInsert(at.getRoot(),5);
    // at.recInsert(at.getRoot(),3);

    at.root = at.recInsert(at.getRoot(),30);
    at.recInsert(at.getRoot(),10);
    at.recInsert(at.getRoot(),20);

    cout << at.getRoot()->data << endl;
    // cout << at.getRoot()->rchild->lchild->data;
    cout << at.getRoot()->lchild->data << endl;
    cout << at.getRoot()->rchild->data << endl;
}