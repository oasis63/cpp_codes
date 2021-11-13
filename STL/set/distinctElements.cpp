/*

Distinct Count ||

Distinct Elements in an array 

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
   int cases;cin>>cases;
   while(cases--){
       int n,x;cin>>n>>x;
        
        set<int> s;
        
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            s.insert(temp);
        }
        
       
       if(s.size() == x)
        cout<<"Good"<<endl;
       else if( s.size() < x)
        cout<<"Bad"<<endl;
        else
            cout<<"Average"<<endl;
   }
}
