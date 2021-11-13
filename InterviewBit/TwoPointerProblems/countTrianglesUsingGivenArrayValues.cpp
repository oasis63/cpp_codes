#include<bits/stdc++.h>
using namespace std;

/*

Given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line 
segment, count the number of triangles which can be formed using these 
array values.

*/

int countTriangles(vector<int> &A) {
    sort(A.begin(),A.end());

    int n = A.size();

    if(n<=2)
        return 0;

    long long ans=0,left,right;

    for(int i=0;i<n;i++){

        left = 0;
        right = i-1;
        while(left<right){
            if(A[left]+A[right] > A[i]){
                ans+= right-left;
                right--;
            }else{
                left++;
            }
        }
    }

    long long mod = pow(10,9);
    int ret = ans%(mod+7);

  return ret;
}




int main(){

    vector<int> vect {1, 1, 1, 2, 2};

    cout<<countTriangles(vect)<<endl;

    return 0;
}

