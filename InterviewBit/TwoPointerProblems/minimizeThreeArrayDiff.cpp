/*
Given 3 arrays A, B and C. All 3 of the arrays are sorted.
Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

i.e. minimize | max(a,b,c) - min(a,b,c) |

*/

#include<bits/stdc++.h>
using namespace std;

int minimize(vector<int> &A, vector<int> &B, vector<int> &C) {
    int l=A.size();
    int m=B.size();
    int n=C.size();

    int ans = INT_MAX;
    int i=0,j=0,k=0;

    while(i<l && j<m && k<n){
        int a = A[i];
        int b = B[j];
        int c = C[k];

        int mx = max(a,max(b,c));
        int mn = min(a,min(b,c));

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

    vector<int> A {1, 4, 10};
    vector<int> B {2,15,20};
    vector<int> C {10,12};

    cout<<minimize(A,B,C)<<endl;   // 5,6,6

    return 0;
}
