/*
Given an array S of n integers, find three integers in S such that
the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution
*/

#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());

    int n = A.size();
    int minSum = 1000000000,sum=0;

    for(int i=0;i<n-2;i++){
        // fix the smallest number

        int j = i+1,k=n-1;
        while(j<k){

            sum = A[i]+A[j]+A[k];
            if(abs(sum - B) < abs(minSum - B)){
                minSum=sum;
            }
            if(sum > B){
                k--;
            }else{
                j++;
            }
        }
    }
    return minSum;

}


int main(){

    vector<int> vect1 {5, -2, -1, -10, 10};
    int target1 = 5;


    cout<<threeSumClosest(vect1,target1)<<endl;

}



