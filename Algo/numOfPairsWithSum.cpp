#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;cin>>n>>sum;
    int num[n];

    clock_t start = clock() ;

    for(int i=0;i<n;i++)
        cin>>num[i];

    int hash[1000] = {0};

    for(int i=0;i<n;i++)  // time complexity is O(n)
        hash[num[i]]++;

    int count=0;

    for(int i=0;i<n;i++){
        int temp = sum-num[i];  // other number
        if(hash[temp]!=0){
            count++;
            hash[temp]--;
        }
        hash[num[i]]--;
    }

    cout<<count<<endl;

    clock_t stop = clock() ;

    cout<<(stop-start)/CLOCKS_PER_SEC<<endl;
}
