//
// Created by misash on 10/10/22.
//


#include <iostream>
#include <deque>

using namespace std;


struct MinHeap{

    deque<int> heap;
    int size;

    MinHeap(){
        size = 0;
    }

    void insert(int x){
        int currentPos = size;
        heap.push_back(x);
        size ++;

        while(heap[currentPos] < heap[parent(currentPos)]){
            swap(currentPos,parent(currentPos));
            currentPos = parent(currentPos);
        }
    }

    int parent(int index){
        return (index -1)/2;
    }

    int leftChild(int index){
        return 2*index + 1;
    }

    int rightChild(int index){
        return 2*index +2;
    }

    void swap(int a , int b){
        int aux = heap[a];
        heap[a] = heap[b];
        heap[b] = aux;
    }


    void print(){
        cout<<"\n";
        for (int i : heap) {
            cout<<i<<" ";
        }
    }


};



int main(){


    MinHeap hp;

    int nums[] = {30,48,15,67,24,17,5};

    for(int i : nums)
        hp.insert(i);

    hp.print();


}
