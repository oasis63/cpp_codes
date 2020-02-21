/*
Given an array ‘A’ of sorted integers and
another non negative integer k, find if there
exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :
            {1,3,5}
            k=4

            return 1;
*/

#include<bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &A, int B) {

    int n = A.size();

    int j=0;
    for(int i=0;i<n;i++){
        j=max(j,i+1);
        while(j<n && (A[j] - A[i] < B))
            j++;
        if(A[j] - A[i] == B)
            return 1;
    }

    return 0;
}


int main(){

    vector<int> vect {1,3,5};
    int k = 4;

    vector<int> vect1 { 1, 2, 2, 3, 4};
    int k1 = 0;

    cout<<diffPossible(vect1,k1)<<endl;

    return 0;
}
