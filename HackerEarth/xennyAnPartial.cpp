#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;cin>>t;
    while(t--){
       int n,k,m;
       cin>>n>>k>>m;

       string srr[n];
       string sb[n];

       for(int i=0;i<n;i++){
            cin>>srr[i];
       }

       // sorting the strings in increasing order

       for(int i=1;i<n;i++)
       {
           string s1 = srr[i].substr(0,m);
            for(int j=0;j<i;j++){
                string s2 = srr[j].substr(0,m);
                 if(s2>s1){
                   //swap(&a[j],&a[i]);
                   string s = srr[i];
                   srr[i] = srr[j];
                   srr[j] = s;
                }
         }

       }


        for(int i=0;i<n;i++)
            cout<<srr[i]<<endl;





    }
}
