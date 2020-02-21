// Adjacency List of Graph using List

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int> *arr;

};

int main(){

    int **a;

    a=new int*[5];

    for(int i=0;i<5;i++)
        a[i] = new int[5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            a[i][j] = i*j;
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<a[i][j]<<"  ";
        cout<<endl;
    }

    //system("pause");

    return 0;
}
