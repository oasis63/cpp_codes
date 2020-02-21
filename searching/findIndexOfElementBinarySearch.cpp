#include<bits/stdc++.h>
using namespace std;

/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
*/

int  searchInsert(vector<int> &vect, int val) {

    int n = vect.size();

    if(val < vect[0])
        return 0;
    else if(val > vect[n-1])
        return n;

    
    int low = 0,high=n-1,mid;
    int ans = -1;


    while(low<=high){

        mid = low + (high-low)/2;

        if(vect[mid] == val){
           ans = mid;
           break;
        }
        else if(val > vect[mid]){

            if((mid+1) < n && val < vect[mid+1])
                ans = mid+1;

            low = mid + 1;
        }
        else{ // val < vect[mid]

             if((mid-1) >= 0 && val > vect[mid-1])
                ans = mid;

            high = mid - 1;
        }
    }

    
    
    return ans;
}


int main(){

    vector<int> vect{1,3,5,6};

    cout<<searchInsert(vect,4)<<endl;

    return 0;
}
