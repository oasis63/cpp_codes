#include<bits/stdc++.h>
using namespace std;


int main(){

   char s='a';

   if(islower(s))
        cout<<s<<" is lower case "<<endl;
   else
        cout<<s<<" is not lower case "<<endl;

   char u='G';

   if(islower(s))
        cout<<u<<" is upper case "<<endl;
   else
        cout<<u<<" is not upper case "<<endl;


    cout<<"-- "<<u<<" after case conversion --"<<endl;

   u=tolower(u);

   cout<<"tolower = "<< u<<endl;


    u=tolower(u);

   cout<<"toupper = "<< u<<endl;
}
