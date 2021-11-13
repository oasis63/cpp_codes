#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(int n, vector<int> A){
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     */
    priority_queue<ll> pq;

    for(int i=0;i<n;i++){
            pq.push(A[i]);
        if(pq.size() < 3){
            cout<<-1<<endl;
        }else{
            ll t1 = pq.top();
            pq.pop();
            ll t2 = pq.top();
            pq.pop();
            ll t3 = pq.top();
            pq.pop();
            pq.push(t1);
            pq.push(t2);
            pq.push(t3);
            cout<<t1*t2*t3<<endl;
        }
    }

}

int main(){

    int n=5;
    vector<int>v{367399,636047,367082,90634,863200};
    solve(n,v);
}
