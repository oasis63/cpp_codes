#include<bits/stdc++.h>
using namespace std;

/*
Connect n ropes with minimum cost
*/

int solve(vector<int>input,int n){

    int minCost = 0;
    //input.erase(vect.begin());

    int len = input.size();

    priority_queue<int,vector<int>,greater<int>> pq(input.begin(),input.end());

    while(pq.size() > 1 ){

        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int sum = first+second;
        minCost += sum;

        pq.push(sum);
    }


    return minCost;
}

int main(){

   vector<int> input = {4,3,2,6};
   int n=input.size();

   cout<<solve(input,n)<<endl;
}
