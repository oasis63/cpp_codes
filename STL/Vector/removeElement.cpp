#include<bits/stdc++.h>
using namespace std;

// remove element without taking any extra space
// Time ans Space Complexity :-  O(1) and O(1) respectively

int removeElement(vector<int> &A, int B) {
    int n = A.size();
    int t = 0;
    for(int i=0;i<n;i++){
        if(A[i] == B){
            continue;
        }
        A[t]=A[i];
        t++;
    }
    A.resize(t);
    return t;
}


int main(){

     vector<int> vect{4,1,1,1,2,1,1,3,5};

    cout<<removeElement(vect,1)<<endl;

    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }


    return 0;
}



