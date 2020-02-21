/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
You are given a target value to search. If found in the array, return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

*/


#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int search(const vector<int> &vect,int val){

    int n = vect.size();
    int low = 0,high = n-1,mid;

    while(low<=high){
        mid = low + (high-low)/2;
        if(vect[mid]== val){
            return mid;
        }else if(vect[0] <= vect[mid]){  // left part is sorted
            if(vect[0]<= val && val < vect[mid])
                high = mid-1;
            else
                low = mid+1;
        }else{// right part is sorted
            if(vect[mid] < val && val <= vect[n-1])
                low = mid+1;
            else
                high = mid-1;
        }   
    }

    return -1;
}


int main(){
        
    vector<int> vect {
                        180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 
                        194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 
                        17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 
                        45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 
                        79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 
                        107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 
                        127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 
                        156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 
                        176, 177
                    };

    cout<<search(vect,43)<<endl;
    
}