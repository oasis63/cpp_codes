#include<bits/stdc++.h>
using namespace std;

/*
Connect n ropes with minimum cost
*/


#define ll long long
long long int minCost(int n, vector<int> v) {


    priority_queue<int,vector<int>,greater<int>> pq;
    ll sum = 0;

    for(int i=0;i<n;i++){
        pq.push(v[i]);
    }


    while(!pq.empty()){
        ll t1 = pq.top();pq.pop();
        ll t2 = pq.top();pq.pop();
        sum += t1+t2;

        if(pq.empty())
            break;

        pq.push(t1+t2);
    }

    return sum;

}

int main(){
    int n = 4;
    vector<int>vect{4,3,2,6};

    cout<<minCost(n,vect)<<endl;
}
