#include<bits/stdc++.h>
using namespace std;

const int inf =  100005;

int id[inf];            // can be considered as parent[] of the index
long long sz[inf];      // union by size

int findSet(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x=id[x];
    }
    return x;
}

void combine(int x,int y){

    int p = findSet(x);
    int q = findSet(y);

    if(p==q)
        return;
    id[q] = p;
    sz[p] += sz[q];
    sz[q] = -1;

}

int main(){

    int n;
    cin>>n;

    int m;
    cin>>m;

    for(int i=1;i<=n;i++){
        id[i]=i;            // make set
        sz[i]=1;
    }

    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        combine(a,b);
    }

    long long int ans = 0;
    for(int i=1;i<=n;i++){
        if(id[i] == i){
            ans += (sz[i]*(sz[i]-1))/2;
        }
    }

    cout<<ans<<endl;
}

/*
4
2
1 2
3 4

ans: 2


*/
