#include<bits/stdc++.h>
using namespace std;

/*
Given 2 sorted arrays, find all the elements which occur in both the arrays.
*/

vector<int> intersect(const vector<int> &A, const vector<int> &B) {

   int n = A.size();
   int m = B.size();
   vector<int> vect;

    int i=0,j=0;
    while(i<n && j<m){
        if(A[i] < B[j]){
//            vect.push_back(A[i]);
            i++;
        }else if(A[i] < B[j]){
//            vect.push_back(B[j]);
            j++;
        }else {
            vect.push_back(A[i]);
             i++;
             j++;
        }
    }


   return vect;
}


int main(){

    vector<int> A{1,2,3,3,4,5,6};
    vector<int> B{3,3,5};

    vector<int> vect = intersect(A,B);

    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }

    return 0;
}
