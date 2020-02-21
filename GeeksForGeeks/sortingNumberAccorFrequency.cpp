#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n){

    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    vector<int>vect[131];

    for(auto p : mp){
//        cout<<p.first<<"  "<<p.second<<endl;
        vect[p.second].push_back(p.first);
    }

//    cout<<"\nMulti Vector  \n " <<endl;
    for(int i=130;i>=0;i--){
        if(vect[i].size() != 0){
            for(int j =0;j<vect[i].size();j++){
                int t = i;
                while(t--)
                    cout<<vect[i][j]<<" ";
            }
        }
    }

    cout<<endl;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        solve(arr,n);
    }
    return 0;
}
