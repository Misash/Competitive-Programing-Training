//
// Created by misash on 13/09/22.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


template <class T>
struct CBinTreeNode
{
    CBinTreeNode(T v)
    {
        value = v;
        nodes[0] = nodes[1] = 0;
    }
    T value;
    CBinTreeNode<T>* nodes[2]; //0 left, 1 right
};


template <class T>
class CBinTree
{
public:

    CBinTree();
    CBinTreeNode<T>* Root();
    bool Find(T x, CBinTreeNode<T>**& p);
    bool Ins(T x);
    int MaxDepth(CBinTreeNode<T>* n);
    void Print();
    int Size();
    void InOrderTrack(CBinTreeNode<T>*  , vector<vector<string>> & , int , int &);
    void PrintNiveles();
    void RotateVec(vector<vector<string>> a , vector<vector<string>> &b, string);



private:
    CBinTreeNode<T>* root;
    bool brep;
    int size;
};

template <class T>
CBinTree<T>::CBinTree()
{
    root = 0;
    brep = 0;
    size = 0;
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::Root()
{
    return root;
}

template <class T>
bool CBinTree<T>::Find(T x, CBinTreeNode<T>**& p)
{
    for (   p = &root;
            *p && (*p)->value != x;
            p = &((*p)->nodes[ (*p)->value < x ])
            );
    return *p != 0;
}

template <class T>
bool CBinTree<T>::Ins(T x)
{
    CBinTreeNode<T>** p;
    if ( Find(x,p) ) return 0;
    *p = new CBinTreeNode<T>(x);
    size++;
    return 1;
}


template <class T>
int CBinTree<T>::Size() {
    return size;
}


template <class T>
int CBinTree<T>::MaxDepth(CBinTreeNode<T>* n)
{
    if ( !n ) return -1;
    return std::max(MaxDepth(n->nodes[0]), MaxDepth(n->nodes[1])) + 1;
}



template <class T>
void CBinTree<T>::InOrderTrack(CBinTreeNode<T>* data , vector<vector<string>> &v ,  int i, int &j)
{
    if ( !data ) return;
    InOrderTrack(data->nodes[0],v,i+1,j);
    v[2*i][j++] = std::to_string(data->value);
    InOrderTrack(data->nodes[1],v,i+1,j);
}

void printVec(vector<vector<string>> vec){
    cout<<"\n\n";
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j)
            cout<<vec[i][j]<<" ";
        cout<<"\n";
    }
}

template <class T>
void CBinTree<T>::PrintNiveles() {

    string delimiter = " ";

    int height = 2*MaxDepth(root) + 1 , j = 0;
    vector<vector<string>> down(height, vector<string> (size, delimiter));

    InOrderTrack(root, down, 0, j);


    cout<<"\n\n";
    for (int i = 0; i < height; ++i) {
        for (j = 0; j < size; ++j)
            if(down[i][j] != delimiter && down[i][j] != "+"  ){
                CBinTreeNode<T>** p;
                if ( Find(stoi(down[i][j]), p) ){
                    //check nodes
                    for (int x = 0; x <=1 ; ++x) {
                        if((*p)->nodes[x]){
                            int k = j;
                            while(down[i + 2][k] == delimiter || down[i + 2][k] == "+" ){
                                down[i + 1][k]="+";
                                k = (x)? k+1 : k-1;
                            }
                            down[i + 1][k]="+";
                        }
                    }

                }
            }
    }

    vector<vector<string>> left;
    vector<vector<string>> up;
    vector<vector<string>> right;

    printVec(down);

    RotateVec(down, left,delimiter);
    printVec(left);

    RotateVec(left, up,delimiter);
    printVec(up);

    RotateVec(up, right,delimiter);
    printVec(right);


}

template <class T>
void CBinTree<T>::RotateVec(vector<vector<string>> a , vector<vector<string>>& b , string delimiter){

    b.resize(a[0].size(), vector<string> (a.size(), delimiter));

    int row = b.size() , col = b[0].size();

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j)
            b[j][ a.size() - 1 -i] = a[i][j];
    }

}


//template <class T>
//void CBinTree<T>::PrintRight(string& sb, string padding, string pointer , CBinTreeNode<T> * node){
//    if(!node) return;
//
//    sb += padding;
//    sb += pointer;
//    sb += to_string(node->value);
//    sb += "\n";
//
//    string paddingForBoth = padding;
//    if( node != root)
//        paddingForBoth += (pointer == "└── ") ? "   " : "│  " ;
//
//
//    for (int i = 0; i <= 1; ++i) {
//        if(node->nodes[0] && node->nodes[1])
//            pointer = (node->nodes[i] && i)?  "└── " : "├── ";
//        else if(node->nodes[i])
//            pointer =  "└── ";
//        PrintRight(sb, paddingForBoth, pointer, node->nodes[i]);
//    }
//
//}
//
//
//
//template <class T>
//void CBinTree<T>::PrintLeft(string& sb, string padding, string pointer , CBinTreeNode<T> * node){
//    if(!node) return;
//
//    sb += padding;
//    sb += pointer;
//    sb += to_string(node->value);
//    sb += "\n";
//
//    string paddingForBoth = padding;
//    if( node != root)
//        paddingForBoth += (pointer == "└── ") ? "   " : "│  " ;
//
//
//    for (int i = 0; i <= 1; ++i) {
//        if(node->nodes[0] && node->nodes[1])
//            pointer = (node->nodes[i] && i)?  "└── " : "├── ";
//        else if(node->nodes[i])
//            pointer =  "└── ";
//        PrintRight(sb, paddingForBoth, pointer, node->nodes[i]);
//    }
//
//}




template <class T>
void CBinTree<T>::Print()
{
    std::cout<<"\n";
    string parseTree;
//    PrintRight(parseTree, "", "", root);
//    PrintLeft(parseTree, "", "", root);
//    cout<<parseTree;
//    InOrder(root);
}





int main()
{
    CBinTree<int> t;

    //PRUEBA
    vector<int> v = {8,3,10,1,0,2,6,9,144,4,7,13,20,18};
//    vector<int> v = {50,40,80,30,43,60,95,20,35,73,90,99,10,28};

    for (int i : v) {
        t.Ins(i);
    }


    cout<<"\noutput";
    t.PrintNiveles();



}

