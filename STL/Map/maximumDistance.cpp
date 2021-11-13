#include<bits/stdc++.h>
using namespace std;


int maximumDistance(int arr[],int n){

    int glb_max = INT_MIN;

    // key , first_occurrence
    map<int,int> mp;

    for(int i=0;i<n;i++){
        if(mp[arr[i]] == 0){
            mp[arr[i]] = i+1;
        }else{
            glb_max = max(glb_max,i-mp[arr[i]]+1);
        }
    }

    return glb_max;

}


int main(){
    
    int arr[] = {3,2,1,2,1,4,5,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);


    cout<<"maximumDistance : " << maximumDistance(arr,n)<<endl;

    return 0;
}