#include<bits/stdc++.h>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int prod = 1;
    int n = nums.size();
    
    int prodWithoutZero = 1;
    
    set<int> zeroIndex;
    
    for(int i=0;i<n;i++){
        if(nums[i] != 0){
            prodWithoutZero *= nums[i];
        }else{
            zeroIndex.insert(i);
        }
    }
    
    int zerosCount =  0 ;
    zerosCount = zeroIndex.size(); 

    if(zerosCount == n)
        return nums;
    
 
    for(int i=0;i<n;i++){

        if(zerosCount == 0){
            nums[i] = prodWithoutZero/nums[i];
        }else if(zerosCount == 1  && nums[i] == 0){
            nums[i] = prodWithoutZero;
        }else{
            nums[i] = 0;
        }
    
        
    }
    return nums;
}


// without division 
vector<int> productExceptSelfWithoutdivision(vector<int>& nums) {
    int n = nums.size();
    vector<int> t1(n);
    vector<int> t2(n);
    vector<int> result(n);

    t1[0]=1;
    // multiply from left to right
    for(int i=0;i<n-1;i++){
        t1[i+1] = t1[i]*nums[i];
    }

    t2[n-1] = 1;
    // multiply from right to left
    for(int i=n-1;i>0;i--){
        t2[i-1] = t2[i]*nums[i];
    }
    for(int i=0;i<n;i++)
        result[i] = t1[i]*t2[i];
    
    return result;
}

int main(){
    
    vector<int> vect{0,1};    // 0,0,0,3

    vect = productExceptSelfWithoutdivision(vect);

    int n = vect.size();

    for(int i=0;i<n;i++){
        cout<<vect[i]<<" ";
    }

    return 0;
}