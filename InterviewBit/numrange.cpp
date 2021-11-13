/*
Given an array of non negative integers A, and a range (B, C),
find the number of continuous subsequences in the array which
have sum S in the range [B, C] or B <= S <= C

*/

#include<bits/stdc++.h>
using namespace std;

int numRange(vector<int> &A, int B, int C) {

    // copied code

    int i = 0;
    int j = 0;
    int sum = 0;
    int count = 0;

    while(i < A.size()){
        sum = sum + A[j];
        if((sum >= B) && (sum <= C)){
            count++;
            j++;
        }
        else if(sum < B){
            j++;
        }
        else if(sum > C){
            i++;
            j = i;
            sum = 0;
        }
        if(j == A.size()){
            sum = 0;
            i++;
            j = i;
        }
    }

    return count;
}

int main(){

    vector<int> vect{10,5,1,0,2};
    int B = 6;
    int C = 8;

    int count = numRange(vect,B,C);

    cout<<count<<endl;
}

/*
Continuous subsequence is defined as all the numbers
A[i], A[i + 1], .... A[j]
where 0 <= i <= j < size(A)
*/
