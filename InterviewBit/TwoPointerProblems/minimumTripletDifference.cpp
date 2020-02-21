/*
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number
from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |

*/

#include<bits/stdc++.h>
using namespace std;

int minTripletDiff(vector<int> &A, vector<int> &B, vector<int> &C) {
    int l=A.size();
    int m=B.size();
    int n=C.size();

    int ans = INT_MAX;
    int i=0,j=0,k=0;

    while(i<l && j<m && k<n){
        int a = A[i];
        int b = B[j];
        int c = C[k];

        int mx =max(a,max(b,c));
        int mn =min(a,min(b,c));

        int diff = abs(mx-mn);
        if(diff < ans)
            ans = diff;

        if(mn == a){
            i++;
        }else if(mn == b){
            j++;
        }else if(mn == c){
            k++;
        }
    }

    return ans;

}

int main(){

    vector<int> A {1, 4, 5, 8, 10 };
    vector<int> B {6, 9, 15 };
    vector<int> C {2, 3, 6, 6};

    cout<<minTripletDiff(A,B,C)<<endl;   // 5,6,6

}
