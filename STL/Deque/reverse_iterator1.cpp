#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){

   ll tc;cin>>tc;
   char opt;
   ll s,r;

   deque<pair<int,int>> dq;

   while(tc--){
        cin>>opt;
        if(opt == 'E'){
            cin>>s>>r;
            if(dq.empty()){
                dq.push_back(make_pair(s,r));
            }else{
                dq.push_back(make_pair(s,r));
            }
        }
        else if(opt=='D'){
            pair<int,int> ret = dq.front();
            cout<<ret.first<<" "<<ret.second<<endl;
            dq.pop_front();
        }
   }

  deque<pair<int,int>>::reverse_iterator rit = dq.rbegin();

   for(;rit!=dq.rend();rit++){
        cout<<rit->first<<" "<<rit->second<<endl;
   }

   deque<pair<int,int>>:: iterator itr = dq.begin();

    cout<<endl;
   while(itr != dq.end()){
    cout<<itr->first<<" "<<itr->second<<endl;
    itr++;
   }

}

/*

4
E 1 1
E 2 1
E 4 3
E 1 3


*/

