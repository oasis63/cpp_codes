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




}