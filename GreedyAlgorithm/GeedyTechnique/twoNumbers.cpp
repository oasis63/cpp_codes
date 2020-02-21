#include<bits/stdc++.h>
using namespace std;


/*
Minimum sum of two numbers formed from digits of an array
*/

int main(){

    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];


    vector<int> nums;

    for(int i=0;i<n;i++){
        if(arr[i])
            nums.push_back(arr[i]);
    }

    sort(nums.begin(),nums.end());

    int len = nums.size();

    vector<int> v1;
    vector<int> v2;

    v1.push_back(nums[0]);
    v2.push_back(nums[1]);

    for(int i=2;i<len;i+=2){

        if(nums[i]){
            if((i+1)<len && nums[i+1]){
                v1.push_back(nums[i+1]);
            }
            v2.push_back(nums[i]);
        }
    }


    int num1 = 0;

    for(int i=0;i<v1.size();i++){
        num1 = num1*10 + v1[i];
    }

    int num2 = 0;

    for(int i=0;i<v2.size();i++){
        num2 = num2*10 + v2[i];
    }

    cout<<num1<<" "<<num2<<endl;

    cout<<num1+num2<<endl;

}
