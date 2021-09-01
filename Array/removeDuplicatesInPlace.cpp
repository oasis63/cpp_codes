#include<bits/stdc++.h>
using namespace std;
/*
removeDuplicates of an Array 
in-place

*/

int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    if(len == 0)
      return 0;

    int ind = 0;
    for(int i=0;i<len;i++){
      if(nums[i] != nums[ind]){
        ind++;
        nums[ind] = nums[i];
      }
    }
    // for(int i=0;i<len;i++){
    //   cout<<nums[i]<<"  ";
    // }
    // cout<<endl;

    return ind+1;
}



int main(){
  
  // vector<int> nums{1,2,3,3,3,4,5,5,5,8};
  // vector<int> nums{1,2,3};
  // vector<int> nums;
  vector<int> nums{0,0,0,1,1,1,2,2,3,3,4};

  cout<<removeDuplicates(nums)<<endl;  

  return 0;
}

/*

nums :  0 1

ind :   0 1 2 





*/