#include<bits/stdc++.h>
using namespace std;

/*
Find the first and last occurrence of an element in the sorted array.
if not present return -1 
*/

vector<int> searchRange(const vector<int> &vect, int val) {
    
    bool fs = true;  // firstSearch

    int firstIndex = -1;

    int low = 0,high=vect.size()-1,mid;

    while(low<=high){
        mid = low + (high-low)/2;
        if(vect[mid] == val){
            firstIndex = mid;
            if(fs){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            
        }
        else if(val > vect[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    fs = false;    // firstSearch is over 
    int lastIndex = -1;

    low = 0,high=vect.size()-1,mid;

    while(low<=high){
        mid = low + (high-low)/2;
        if(vect[mid] == val){
            lastIndex = mid;
            if(fs){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            
        }
        else if(val > vect[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    
    vector<int> ans;
    
    if(firstIndex == -1 || lastIndex == -1){
        ans.push_back(-1);
        ans.push_back(-1);
    }else{
        ans.push_back(firstIndex);
        ans.push_back(lastIndex);
    }
    
    return ans;
}


int main(){

    vector<int> vect{5,7,7,8,8,10};

    vector<int> ans = searchRange(vect,8);

    cout<<ans[0]<<" "<<ans[1]<<endl;

    ans = searchRange(vect,324);

    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}
