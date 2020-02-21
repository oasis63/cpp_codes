#include<bits/stdc++.h>
using namespace std;

int availability(int taxi[],int m){

    for(int i=0;i<m;i++){
        if(taxi[i]==0){
            taxi[i]=1;
            return i;
        }
    }

    return -1;
}

void printVect(vector<pair<int,int>> pass){

    int len = pass.size();

    for(int i=0;i<len;i++){
        cout<<pass[i].first<<" "<<pass[i].second<<endl;
    }

    cout<<endl;

}

int main(){

  int n,m;   // n users ...m taxis
  cin>>n>>m;

  int taxi[m];
  memset(taxi,0,sizeof(taxi));

  int rtime,ttime,ftime;

  priority_queue<int,vector<int>,greater<int>> minTime;

  map<int,int> pass;

  int top_elem =  -1;

  for(int i=0;i<n;i++){
    cin>>rtime>>ttime;
    ftime = rtime+ttime;

    if(!minTime.empty()){
        top_elem = minTime.top();
    }

    if(rtime >= top_elem   && top_elem!=-1){
        minTime.pop();
        minTime.push(ftime);


        int idx = pass[top_elem];
        pass.erase(top_elem);
        pass[ftime] = idx;

        cout<<idx<<" ";

        taxi[idx-1] = 1;

        top_elem=-1;

    }else{

        int tid = availability(taxi,m);

        if(tid==-1){
            cout<<-1<<" ";

        }else{
            pass[ftime] = tid+1;
            minTime.push(ftime);
            cout<<tid+1<<" ";

        }

    }
  }


 // printVect(passenger);

    while(!minTime.empty()){
        minTime.pop();
    }

}
