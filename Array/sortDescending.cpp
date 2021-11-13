#include <bits/stdc++.h>
using namespace std;

bool myfunc(int i,int j)
{
    return(i>j);
}

int main() 
{
    int n;
    cin>>n;

    int array[n];

    for(int i=0;i<n;i++)
        cin>>array[i];

    /*  sort(array,array+n-4);
     // it won't sort the last 4 elements 
    */

    sort(array,array+n,myfunc);     // sort the elements descendingly

    for (int i = 0; i < n; ++i)
    {
        /* code */
        cout<<array[i]<<" ";
    }
}
