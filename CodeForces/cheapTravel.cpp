#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,a,b;
    cin>>n>>m>>a>>b;

    float tm = b/m;

    int sum = 0;

    if(tm<a){
        int div = n/m;
        n=n%m;
        sum = div*b;

        int m1 = n*a;

        if(m1 < b){
            sum += m1;
        }else{
            sum += b;

        }

    }else{
        sum += n*a;
    }

    cout<<sum<<endl;

}
