#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> vect,int idx){

  int len = vect.size();
  int ans = 0;

  deque<pair<int,int>> dq;

  for(int i = 0 ;i < len ; i++ ){
    pair<int,int> p{vect[i],i};
    dq.push_back(p);
  }

  while(true){
    pair<int,int> p = dq.front();dq.pop_front();
   
    if(p.second == idx  && p.first == 1){
        ans++;
        break;
    }

    ans++;
    p.first = p.first - 1;

    dq.push_back(p);

  }



  return ans;
}

int main(){
  
  vector<int> vect{2,3,2,4,3};
  int idx = 2;

  cout<<solve(vect,idx)<<endl;

  return 0;
}


/*
Buying Show Tickets - Exercise

Problem Statement : "A line has formed to buy tickets for a concert.  
In order to delay a shortage caused by brokers buying large blocks of tickets, 
venue management has decided to sell only one ticket at a time. 
Buyers have to wait through the line again if they want to buy more tickets.  
Jesse is standing in line and has a number of tickets to purchase.

Given a list of ticket buyers with their numbers of desired tickets, 
determine how long it will take Jesse to purchase his tickets.  
Jesse's position in line will be stated, and each transaction takes 1 unit of time.
  For your purposes, no time is spent moving to the back of the line."


*/