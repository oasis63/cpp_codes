#include <bits/stdc++.h>
using namespace std;

int main()
{
   
   map<int,int>m;

   m[1]=100;
   m[2]=300;
   m[3]=300;
   m[5]=500;

   m.insert(pair<int,int>(2,200));
   m.insert(make_pair(4,100));

   map<int,int>::iterator itr = m.begin();


   while( itr != m.end())
   {
    cout<<itr->first<<" "<<itr->second<<endl;
    itr ++;
   }

   map<int,int>m2(m); // copy of map m

   itr = m2.begin();


   cout<<"Second map copied from the first map\n"<<endl;
   while( itr != m2.end())
   {
        cout<<itr->first<<" "<<itr->second<<endl;
        itr++;
   }

   map<int,int> m3 (m2.begin(),m2.end());

   cout<<"\nElements of the map m3 copied from m2,  map<int,int> m3 (m2.begin(),m2.end());";

   itr = m3.begin();

   while( itr != m3.end())
   {
        cout<<itr->first <<" " << itr->second<<endl;
        itr ++;
   }


   return 0;

}