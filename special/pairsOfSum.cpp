#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin>>n>>m;
    int num[n];



    for(int i=0;i<n;i++)
        num[i]=rand()%10;

    int count=0;

    double t1 = clock();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(num[i]+num[j]==m)
                count++;
        }

    }

    double t2=clock();

    cout<<count<<endl;

    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;
}
