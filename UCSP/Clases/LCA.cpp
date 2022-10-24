//
// Created by misash on 11/10/22.
//

#include <iostream>

using namespace std;
#define node(a,l,r) new Node<char>(a,l,r)

template<class  T>
struct Node{
    T val;
    Node* child[2];
    Node(T val,Node * left = 0, Node *right=0){
        this->val = val;
        child[0] = left;
        child[1] = right;
    }
};


Node<char> *LCA (Node<char> *root ,char p,char q){
    if(!root) return 0;
    if(root->val == p || root->val == q ) return root;

    Node<char> *left = LCA(root->child[0],p,q);
    Node<char> *right = LCA(root->child[1],p,q);

    if( left && right) return root;
    else return  (left ? left : right);

}


int main(){

        Node<char> *root =
                new Node<char>('a',node('b',node('d',0,0),node('e',0,0))
                               ,node('c',node('f',0,0),node('g',0,0)));

        char res = LCA(root,'d','g')->val;

        cout<<res;

}
