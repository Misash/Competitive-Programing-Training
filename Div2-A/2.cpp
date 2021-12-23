

#include <iostream>

using namespace std;

void intercambio(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


void mezclar(int *a, int *b,int *c)
{
    int len=(*c-*a)+1;
    int temp[len];
    int *init=a;

    for (int *i = temp; i < temp+len ; ++i) {
        if((temp+len - i) %2 == 0){
            *i = *a++;
        }else{
            *i= *b++;
        }
    }

    for (int *i = temp; i <temp+len ; ++i) {
        *init++ = *i;
    }


}

int main() {
//    int A[10] = {1,3,5,7,9,2,4,6,8,10};
//
//    cout<<"Array antes"<<endl;
//    for(int i=0; i<10;i++)
//        cout<<A[i]<<" ";
//    cout<<endl;
//
//    mezclar(&A[0],&A[5],&A[9]);
//
//    cout<<"Array despues"<<endl;
//    for(int i=0; i<10;i++)
//        cout<<A[i]<<" ";
//    cout<<endl;
//
//    return 0;

//    for (int i = 4; i > 0 ; i /=2) {
//        cout<<i;
//    }

    int ar[] = {8,2,3,6};
    int *p=ar;
    cout<<*(p+3);


}