#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m,k,a,b;
    cin>>n>>m>>k;

    vector< pair<int,int> > adj[n+1];

    int values[n+1];
    for(int i=1;i<=n;i++)
        cin>>values[i];

    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(make_pair(values[b],b));
        adj[b].push_back(make_pair(values[a],a));
    }

        

   for(int i=1;i<=n;i++){
       
        if(adj[i].size() >= k){
            sort(adj[i].begin(),adj[i].end());
            cout<<adj[i][adj[i].size() - k].second<<endl;
        }else{
            cout<<-1<<endl;
        }
   }



}


