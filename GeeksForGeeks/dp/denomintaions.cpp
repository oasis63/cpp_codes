#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


void solve(int num){

     int denos[] =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
      // map<int,int> mp;


     for(int i = 9;i>=0;i--){
        if(denos[i] <= num){
            int d = num/denos[i];
            num = num%denos[i]; 
          /*  cout<<denos[i]<<endl;
            mp[denos[i]] = d;*/
            while(d--){
                cout<<denos[i]<<" ";
            }
        }

        if(num == 0)
            break;
     }

  /*   for(pair<int,int> p : mp){
        cout<<p.first << "   " << p.second<<endl;
     }*/

     cout<<endl;
}


int main(){
    
    int tc;
    cin>>tc;

    while(tc--){
        int sum;cin>>sum;
        solve(sum);
    }

    return 0;
}