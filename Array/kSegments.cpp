#include<bits/stdc++.h>
using namespace std;

/*
Divide an array into k segments to 
maximize maximum of segment minimums

*/

bool isPossible(vector<int> &vect,int m,int currMin){
    int stuReq = 1;
    int curSum = 0;
    for(int i=0;i<vect.size();i++){
        if(vect[i] > currMin)
            return false;
        if(curSum + vect[i] > currMin){
            stuReq++;
            curSum = vect[i];
            if(stuReq > m)
                return false;
        }else{
            curSum += vect[i];
        }
    }
    return true;
}


int books(vector<int> &vect,int m){

    int sum = 0;
    int cnt = 0;
    int n = vect.size();

    if( n < m)
        return -1;

    for(int i=0;i<n;i++)
        sum += vect[i];


    int low = 0,high = sum;
    int ans = INT_MAX;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(isPossible(vect,m,mid)){
            ans = min(ans,mid);
            high = mid-1;
        }
        else
            low = mid + 1;
    }

    return ans;

}




int main(){

    vector<int> vect{10,3,5,7};
    cout<<books(vect,2)<<endl;

    return 0;
}
