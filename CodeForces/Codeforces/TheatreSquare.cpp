#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a;
    cin>>n>>m>>a;

    int theatreArea = n*m;
    int stoneArea = a*a;

    if(stoneArea >= theatreArea && a>=n && a>=m){
        cout<<1<<endl;
    }else{
        int h = n/a;
        if(n%a!=0){
            h++;
        }
        int v = m/a;
        if(m%a!=0){
            v++;
        }

        if(a>=m  ||  a>= n){
            cout<<(h>v?h:v)<<endl;
        }else
            cout<<(h+v)<<endl;
    }

}
