#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
     * r is the number of rotations
     * n is the number of elements
    */

     int n,r,i,j,p,temp;
     cin>>n>>r;

     int num[n];

     for(i=0;i<n;i++)
      cin>>num[i];

    int helper[n];

    // storing the changed rotated indices of the old indices
    for(int i=0;i<n;i++){
        helper[(i+r)%n]=i;
    }

    // dynamic programming

    cout<<"\nPrinting the array after "<<r<<" rotations "<<endl;

    for(int i=0;i<n;i++){
        cout<<num[helper[i]]<<" ";
    }

    cout<<endl;


}
