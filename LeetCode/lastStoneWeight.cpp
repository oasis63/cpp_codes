#include<bits/stdc++.h>
using namespace std;


int lastStoneWeight(vector<int>& stones) {

    priority_queue<int> pq;     // decreasing queue
    int n = stones.size();

    for(int i=0;i<n;i++){
        pq.push(stones[i]);
    }

    int ans = 0;

    while(!pq.empty()){

        int t1 = pq.top();pq.pop();
        int t2 = 0;
        int diff = 0;

        if(!pq.empty()){
            t2 = pq.top(); pq.pop();
            diff = abs(t1-t2);
            pq.push(diff);
        }else{
            ans = t1;
            break;
        }


        ans = abs(t1-t2);
    }

 
    return ans;
}

int main(){

    vector<int> stones{2,7,4,1,8,1};

    cout<<lastStoneWeight(stones)<<endl;

    return 0;
}
