#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;

    n=2*n+1;

    priority_queue<int>pq;

    for(int i=0;i<n;i++){
        int t;cin>>t;
        pq.push(t);
    }



    int f = pq.top();
    pq.pop();

    int count=1;

  while(!pq.empty()){
      int second = pq.top();
      if(second==f)
        count++;
      else{
          if(count&1){
              cout<<f<<endl;
              break;
          }

          f=second;
          count=1;


      }
    pq.pop();

  }




}
