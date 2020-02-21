#include<iostream>
using namespace std;

typedef struct name {
    int num;
    char ch;
    string name;

}number;


int main(){

    int a = 53;  // allocation of memory

    int *p ;

    p = new int[3];

    *(p+0) = 43;
    *(p+1) = 1;
    *(p+2) = 2;

    for(int i=0;i<3;i++){
        cout<<*p<<" ";
        p++;
    }

    delete[] p;

    number n;
    n.num = 34;
    n.ch='c';
    n.name="Rajesh Raman Bosak";

    cout<<"\nValues from the structure \n"<<endl;

    cout<<n.num<<endl;
    cout<<n.ch<<endl;
    cout<<n.name<<endl;


}
