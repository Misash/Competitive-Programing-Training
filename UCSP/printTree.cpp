//
// Created by misash on 13/09/22.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
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

void printVec(vector<vector<string>> arr , string fileName=""){

    int f = arr.size(), c = arr[0].size();
    cout<<"\n\n\n";
    if(fileName != ""){
        fstream File ;
        File.open(fileName , std::ios_base::app);
        File<<"\n\n\n\n";
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cout<<arr[i][j]<<"\t";
                File<<arr[i][j]<<"\t";
            }
            cout<<endl;
            File<<endl;
        }
    }else{
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
}


template <class T>
void CBinTree<T>::PrintNiveles() {

    string delimiter = " ";
    string fill = "+";

    int height = 2*MaxDepth(root) + 1 , j = 0;
    vector<vector<string>> down(height, vector<string> (size, delimiter));

    InOrderTrack(root, down, 0, j);


    cout<<"\n\n";
    for (int i = 0; i < height; ++i) {
        for (j = 0; j < size; ++j)
            if(down[i][j] != delimiter && down[i][j] != fill  ){
                CBinTreeNode<T>** p;
                if ( Find(stoi(down[i][j]), p) ){
                    //check nodes
                    for (int x = 0; x <=1 ; ++x) {
                        if((*p)->nodes[x]){
                            int k = j;
                            while(down[i + 2][k] == delimiter || down[i + 2][k] == fill ){
                                down[i + 1][k]=fill;
                                k = (x)? k+1 : k-1;
                            }
                            down[i + 1][k]=fill;
                        }
                    }

                }
            }
    }

    fstream strassenFile ;
    string fileName = "./output.txt";
    strassenFile.open(fileName, ios::out);

    vector<vector<string>> left;
    vector<vector<string>> up;
    vector<vector<string>> right;

    printVec(down,fileName);

    RotateVec(down, left,delimiter);
    printVec(left,fileName);

    RotateVec(left, up,delimiter);
    printVec(up,fileName);

    RotateVec(up, right,delimiter);
    printVec(right,fileName);


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


void generate_random_vector(int n, vector<int> &vec) {

    int vec_size = 3 + (rand() % n);
    vec.resize(vec_size);
    for (int k = 0; k < vec_size; ++k) {
        vec[k] = 1 + (rand() % 99);
    }

}

int main()
{
    srand(time(0));
    CBinTree<int> t;

    //PRUEBAS
    vector<int> v;
//    vector<int> v = {811,3,10,1,4585,2525,62,9,144,4444,7555,153,20,18,1889};
//    vector<int> v = {50,40,80,30,43,60,95,20,35,73,90,99,10,28};
    generate_random_vector(20,v);


    for (int i : v) {
        t.Ins(i);
    }

    cout<<"\noutput";
    t.PrintNiveles();

}

