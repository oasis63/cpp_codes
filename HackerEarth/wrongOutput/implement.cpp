#include <bits/stdc++.h>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int counOnes(int a[],int n){
    int count=0;
    for(int i=0;i<=n;i++){
        if(a[i]==1)
            count++;
    }
    return count;
}

int main(){

    int n,k,x;
    cin>>n>>k>>x;

    int a[n+1];

    for(int i=0;i<=n;i++){
        a[i]=1;
    }

    a[0]=0;

    //print(a,n);

    //cout<<counOnes(a,n)<<endl;

    while(1){
        int j=x;

        int rem = x%k;

        cout<<"Guns : "<<counOnes(a,n)<<endl;

        if(counOnes(a,n) <= rem){
            cout<<a[j]<<endl;
            break;
        }

        int count=0;

        for(j=(x+1)%(n+1);j<=n;j = (j+1)%(n+1)){
            if(a[j%(n+1)]==1){
                a[j%(n+1)]=0;
                count++;
            }

            if(count==rem)
                break;
        }

        x=(j+1)%(n+1);
        //x=j;

        cout<<"Executed"<<endl;
        cout<<x<<endl;
    }

}
