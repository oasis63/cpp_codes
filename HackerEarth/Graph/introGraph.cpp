#include<bits/stdc++.h>
using namespace std;

const int msize = 1001;

bool graph[msize][msize] = {false};

void print(){
    for(int i=0;i<msize;i++){
        for(int j=0;j<msize;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int q;
    cin>>q;
    while(q-- > 0){
        cin>>a>>b;
        if(graph[a][b]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


}
#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;
    
    bool graph[n+1][n+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            graph[i][j]=false;
        }
    }
    
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int q;
    cin>>q;
    while(q-- > 0){
        cin>>a>>b;
        if(graph[a][b]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


}
