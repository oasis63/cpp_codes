#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;cin>>n>>sum;
    int num[n];

    for(int i=0;i<n;i++)
        num[i]=rand()%10;

    for(int i=0;i<n;i++)
        cout<<num[i]<<" ";


    int hash[10] = {0};

    cout<<endl;

    for(int i=0;i<n;i++)  // time complexity is O(n)
        hash[num[i]]++;

    for(int i=0;i<10;i++)
        cout<<hash[i]<<"  ";

    cout<<endl;

    int count=0;

    for(int i=0;i<n;i++){
        int temp = sum-num[i];  // other number
        if(hash[temp]!=0 && temp<n ){
            count++;
            hash[temp]--;

            cout<<num[i]<<" "<<temp<<endl;
        }
        hash[num[i]]--;
    }

    cout<<count<<endl;

}
