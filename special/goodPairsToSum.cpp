#include <bits/stdc++.h>
using namespace std;

int max(int a[],int n){
    int m = a[0];
    for(int i=0;i<n;i++){
        if(m<a[i])
            m=a[i];
    }
    return m;
}

int main()
{
    int n,sum;cin>>n>>sum;
    int num[n];

    for(int i=0;i<n;i++)
        num[i]=rand()%10;

    for(int i=0;i<n;i++) cout<<num[i]<<" ";

    int mx = max(num,n)+1;

    cout<<endl;

    cout<<mx<<endl;

    int hash[mx] = {0};

    for(int i=0;i<n;i++)  // time complexity is O(n)
        hash[num[i]]++;


    for(int i=0;i<n;i++)
        cout<<hash[i]<<" ";

    cout<<endl;

    int count=0;

    for(int i=0;i<n;i++){
        int temp = sum-num[i];  // other number
        if(hash[temp]!=0 && temp!=sum){
            count++;
            hash[temp]--;
            cout<<num[i]<<" "<<temp<<endl;
        }
        hash[num[i]]--;
    }

    cout<<count<<endl;
}
