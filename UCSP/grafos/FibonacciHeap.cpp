//
// Created by misash on 16/11/22.
//

#ifndef CPCLION_FIBONACCIHEAP_CPP
#define CPCLION_FIBONACCIHEAP_CPP

#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    virtual pair<int, int> top() = 0;
    virtual pair<int, int> pop() = 0;
    virtual void push(pair<int, int>) = 0;
    virtual int getOperations() = 0;
    virtual bool condition() = 0;
private:
    int operations;
};


struct Node
{
    pair<int,int> data;
    int degree;
    Node *child, *sibling, *parent;

    explicit Node(pair<int, int>);
};
typedef pair<int, int> iPair;


class PriorityQueue: public Heap{

    priority_queue<iPair, vector<iPair>, greater<> >pq;
    public:
    PriorityQueue(){}
    pair<int, int> top(){
        return pq.top();
    }
    pair<int, int> pop(){
        pq.pop();
        return {0,0};
    }
    void push(pair<int, int> p){
        pq.push(p);
    }
    bool condition(){
        return !pq.empty();
    }
    int getOperations(){ return 0; }
};



class FibonacciHeap: public Heap
{
public:
    FibonacciHeap();
    pair<int, int> top();
    pair<int, int> pop();
    void push(pair<int, int>);
    int getOperations();
    void printTree(Node *h);
    void printHeap();
    bool condition();
protected:
    pair<int, int> extractMin();
    void insertATreeInHeap(Node *tree);
    list<Node*> removeMinFromTreeReturnFHeap(Node *tree,Node*& n);
    Node* mergeFibonacciTrees(Node *b1, Node *b2);
    list<Node*> unionFibonacciHeap(list<Node*> l1,Node*,list<Node*> l2,Node*);
    void adjust();
    void insert(pair<int,int> key);
    Node* getMin();
private:
    int operations;
    list<Node*> heap;
    Node *minNode;
};


bool FibonacciHeap::condition()
{
    return top() != make_pair(-1, -1);
}

FibonacciHeap::FibonacciHeap()
{
    operations = 0;
    minNode = NULL;
}

int FibonacciHeap::getOperations()
{
    return operations;
}

void FibonacciHeap::push(pair<int, int> Node)
{
    insert(Node);
    return;
}

pair<int, int> FibonacciHeap::top()
{
    if(heap.size() == 0)
        return make_pair(-1, -1);

    return getMin()->data;
}

pair<int, int> FibonacciHeap::pop()
{
    if(heap.size() == 0)
        return make_pair(-1, -1);

    pair<int, int> Node = extractMin();

    return Node;
}

Node::Node(pair<int,int> key)
{
    this->data = key;
    this->degree = 0;
    this->child = this->parent = this->sibling = NULL;
}


void FibonacciHeap::insert(pair<int,int> key)
{
    Node *temp = new Node(key);
    insertATreeInHeap(temp);
}

list<Node*> FibonacciHeap::removeMinFromTreeReturnFHeap(Node *tree,Node*& min_lo)
{
    list<Node*> tempheap;
    Node *temp = tree->child;
    Node *lo;
    operations++;
    while (temp)
    {
        if(((temp)->data).first < (min_lo->data).first)
            min_lo = temp;
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        tempheap.push_front(lo);
    }
    return tempheap;
}


pair<int, int> FibonacciHeap::extractMin()
{
    if(heap.size() == 0)
        return make_pair(-1, -1);
    list<Node*> new_heap,lo;
    Node *temp;
    temp = getMin();
    list<Node*>::iterator it;
    it = heap.begin();
    Node *min_newheap = new Node(make_pair(INT_MAX,-1));
    Node *min_lo = new Node(make_pair(INT_MAX,-1));
    while (it != heap.end())
    {
        if (*it != temp)
        {
            new_heap.push_back(*it);
            if(((*it)->data).first < (min_newheap->data).first)
                min_newheap = (*it);
        }
        it++;
    }
    operations++;
    lo=removeMinFromTreeReturnFHeap(temp,min_lo);
    heap = unionFibonacciHeap(new_heap,min_newheap,lo,min_lo);
    adjust();
    return temp->data;
}


void swap(Node *b1,Node *b2)
{
    Node *a;
    a=b1;
    b1=b2;
    b2=a;
}

Node* FibonacciHeap::mergeFibonacciTrees(Node *b1, Node *b2)
{
    if ((b1->data).first > (b2->data).first)
    {
        swap(b1, b2);
        operations++;
    }
    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
}

list<Node*> FibonacciHeap::unionFibonacciHeap(list<Node*> l1,Node *min1, list<Node*> l2, Node *min2)
{
    copy(l1.rbegin(), l1.rend(), front_inserter(l2));
    if(min1==NULL)
        minNode = min2;
    else if(min2==NULL)
        minNode = min1;
    else
    {
        if((min1->data).first < (min2->data).first)
            minNode = min1;
        else
            minNode = min2;
    }
    return l2;
}

void FibonacciHeap::adjust()
{
    if (heap.size() <= 1)
        return;
    list<Node*>::iterator it;
    it = heap.begin();
    map<int,Node*>m;
    while(it!=heap.end())
    {
        while(m[(*it)->degree]!=NULL)
        {
            int deg = (*it)->degree;
            *it = mergeFibonacciTrees(*it,m[(*it)->degree]);
            list<Node*>::iterator it_temp;
            it_temp = heap.begin();
            while((*it_temp)!=m[deg])
                it_temp++;
            it_temp=heap.erase(it_temp);
            m[deg]=NULL;
        }
        m[(*it)->degree]=(*it);
        it++;
    }
    operations++;
    return;
}

void FibonacciHeap::insertATreeInHeap(Node *tree)
{
    list<Node*> temp;
    temp.push_back(tree);
    heap = unionFibonacciHeap(heap,minNode,temp,tree);
    return;
}

Node* FibonacciHeap::getMin()
{
    if (heap.size() == 0)
        return NULL;
    return minNode;
}
void FibonacciHeap::printTree(Node *h)
{
    while (h)
    {
        printTree(h->child);
        h = h->sibling;
    }
}

void FibonacciHeap::printHeap()
{
    list<Node*> ::iterator it;
    it = heap.begin();
    while (it != heap.end())
    {
        printTree(*it);
        it++;
    }
}



#endif //CPCLION_FIBONACCIHEAP_CPP
