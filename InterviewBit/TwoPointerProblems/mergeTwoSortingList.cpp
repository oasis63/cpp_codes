#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {

   int n = A.size();
   int m = B.size();
   vector<int> vect;

    int i=0,j=0;
    while(i<n && j<m){
        if(A[i] < B[j]){
            vect.push_back(A[i]);
            i++;
        }else{
            vect.push_back(B[j]);
            j++;
        }
    }

    while(i<n){
        vect.push_back(A[i]);
        i++;
    }

    while(j<m){
        vect.push_back(B[j]);
        j++;
    }


    A.clear();
    int len = vect.size();
    for(int z=0;z<len;z++){
        A.push_back(vect[z]);
    }
}


int main(){

    vector<int> A{-4,3};
    vector<int> B{-2,-2};

    merge(A,B);

    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }


    return 0;
}
