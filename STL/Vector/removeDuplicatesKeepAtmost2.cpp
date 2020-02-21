#include<bits/stdc++.h>
using namespace std;
/*
Given a sorted array, remove the duplicates in place
such that each element can appear atmost twice and return the new length.


exmaple:
            {1,1,1,1,4,4,4,2,2,5}

            ans :  {1,1,4,4,2,2,5}

*/


int removeDuplicates(vector<int> &A) {
    int n = A.size();
    if(n==0 || n==1)
        return n;

    int t = 0;

    for(int i=1;i<n;i++){

        // consecutively 3 elements are equal
        if(i<n-2 && A[i] == A[i+1] && A[i] == A[i+2]){
            continue;
        }else{
            A[t]=A[i];
            t++;
        }
    }
    A.resize(t);
    return t;
}



int main(){

//    vector<int> vect { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

   vector<int> vect{1,1,1,4};

    cout<<removeDuplicates(vect)<<endl;

    cout<<"--Vector after removing the duplicates---"<<endl;
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }

    return 0;
}
