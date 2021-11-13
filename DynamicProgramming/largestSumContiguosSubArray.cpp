#include<bits/stdc++.h>
using namespace std;

// Largest Sum Contiguous Subarray

// Kadane's Algorithm

int subArraySum(int a[],int n){

    int max_so_far=0,max_ending=0;

    for(int i=0;i<n;i++){
        max_ending = max_ending + a[i];
        if(max_ending < 0 )
            max_ending=0;
        else if(max_ending > max_so_far)
            max_so_far=max_ending;
    }

    return max_so_far;
}
int main(){
 
    int input[] = {-2,-3,4,-1,-2};

    cout<<subArraySum(input,5)<<endl;

     int input2[] = {-2,-3,4,-1,-2,1,5,-3};

    cout<<subArraySum(input2,8)<<endl;


}
