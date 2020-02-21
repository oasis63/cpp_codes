#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int sumArray[t] = {0};

    int index = 0;
    
    while( t-- )
    {
        int n;
        cin>>n;
        
        int sum=0;
        
        for(int i=1;i<n;i++)
        {
            if( i%3==0 || i%5==0)
            {    sum += i;
            }
        }
        
        sumArray[index] = sum;
        index ++;
    }

    for(int i=0;i<index;i++)
    {
        cout<<sumArray[i]<<" ";
    }



}