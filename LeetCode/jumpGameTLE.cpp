#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

bool canJumpUtil(vector<int> nums,int n,int currIndex){
    // int currValue = nums[currIndex];
    cout<<"currIndex " << currIndex <<endl;
    if(currIndex >= n-1){
        cout<<">="<<endl;
        return true;
    }
    if(nums[currIndex] == 0)
        return false;
    // for(int i=nums[currIndex];i<n;i++){
    int currValue = nums[currIndex];
    cout<< " currValue "<< currValue<<endl;
        for(int j=1;j<=currValue;j++){
            if(canJumpUtil(nums,n,currIndex+j)){
                cout<<"inside If " <<currValue<<endl;
                return true;    
            }
        }
    // }
    return false;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n==1)
        return true;
    return canJumpUtil(nums,n,0);
}

int main(){

    // vector<int> vect{3,2,1,0,4};
    // vector<int> vect{2,3,1,1,4};
    // vector<int> vect{2,0};
    vector<int> vect{2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    
    cout<<canJump(vect)<<endl;

    return 0;
}