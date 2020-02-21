#include<bits/stdc++.h>
using namespace std;

// Maximum Sum Contiguous Subarray

// Kadane's Algorithm   ...  Dynamic Algorithm   ....  O(n)
// works for all negative numbers also

int subArraySum(int a[],int n){

    int max_so_far=a[0]; 
    int curr_max = a[0];

    for(int i=1;i<n;i++){
        curr_max = max(curr_max+a[i],a[i]);
        max_so_far=max(max_so_far,curr_max);
    }

    return max_so_far;
}


int main(){

    int input[] = {-2,-3,-4,-1,-2};

    cout<<subArraySum(input,5)<<endl;

     int input2[] = {-2,-3,4,-1,-2,1,5,-3};

    cout<<subArraySum(input2,8)<<endl;

    int input3[] = {1,2,3,4};
    cout<<subArraySum(input3,4)<<endl;


}
