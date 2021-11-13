#include<bits/stdc++.h>
using namespace std;

/*
    Wrong Output .... recode it ...
*/


int main(){
    int n,sum=0,t;
    cin>>n;

    int in[n];

    for(int i=0;i<n;i++){
        cin>>in[i];

    }

    sort(in,in+n);

    int count=0;
    int temp=0;

    for(int i=0;i<n;i++){
        temp += in[i];
        if(temp == 4){
            count++;
            temp = 0;
        }else if(temp > 4){
            count++;
            temp = in[i];
        }
    }

    if(temp <= 4)
        count++;

    cout<<count<<endl;
}
