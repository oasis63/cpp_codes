#include <bits/stdc++.h>
using namespace std;

/*
Different ways of initializing a vector
*/

void printVect(vector<int> vect){
    for(int x : vect){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main (){

    vector<int> vect;
    vect.push_back(3);
    vect.push_back(3432);
    vect.push_back(433);
    printVect(vect);

    cout<<"\nSpecifying size and initializing all values : "<<endl;

    int n = 3;
    // all values as 10
    vector<int> vect1(n,10);
    printVect(vect1);

    cout<<"\nInitializing like an array\n"<<endl;
    vector<int> vect2{10,20,30};
    printVect(vect2);

    cout<<"\nInitializing from array\n"<<endl;
    int arr[] = {11,22,33};
    n = sizeof(arr)/sizeof(arr[0]);

    vector<int> vect3(arr,arr+n);
    printVect(vect3);

    cout<<"\nInitializing from another vector"<<endl;
    vector<int> vect4(vect3.begin(),vect3.end());
    printVect(vect4);

}
