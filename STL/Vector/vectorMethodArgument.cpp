#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

void displayArr(int arr[],int n){   
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void modifyArr(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i] = arr[i]*(i+1);
    }
}

void dispVect(vector<int> vect){
    int sz = vect.size();
    for(int i=0;i<sz;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

void modifyVect(vector<int> vect){
    int sz = vect.size();
    for(int i=0;i<sz;i++){
        vect[i] = vect[i]*(i+1);
    }
}

void modifyVect2(vector<int> &vect){
    int sz = vect.size();
    for(int i=0;i<sz;i++){
        vect[i] = vect[i]*(i+1);
    }
}

/* void modifyVect3(const vector<int> &vect){
    int sz = vect.size();
    for(int i=0;i<sz;i++){
        vect[i] = vect[i]*(i+1);   // will give some compile time error
    }
}  */


int main(){
    
    int arr[] = {1,2,34};
    int n = 3;

    cout<<"When we pass an array to a function, a pointer is actually passed."<<endl;
    cout<<"changes made inside the function are  reflected outside."<<endl;
    displayArr(arr,n);
    modifyArr(arr,n);
    displayArr(arr,n);

    cout<<"When a vector is passed to a function, a copy of the vector is created"<<endl;
    cout<<"changes made inside the function are not reflected outside because function has a copy."<<endl;

    vector<int> vect{8,9,10};
    dispVect(vect);
    modifyVect(vect);
    dispVect(vect);

    cout<<"\nPassing by reference of a vector may change its values"<<endl;
    modifyVect2(vect);
    dispVect(vect);

   /* cout<<"\nIf we do not want a function to modify a vector, we can pass it as a const reference."<<endl;
    modifyVect3(vect);   // will give some compile time error
    dispVect(vect);  */




    return 0;
}