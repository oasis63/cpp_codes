#include <bits/stdc++.h>
using namespace std;
 
int main () {

   string str ("software");
   regex str_expr ("[a-z");
    
   smatch sm;
   regex_match (str,sm,str_expr);
   
   cout << "the matches are: "<<endl;
   for (unsigned i=0; i<sm.size(); ++i) {
      cout<<sm[i]<<endl;
   }
 
   cout << endl;

   string data = "boost libraryAFDLFLJ is simple.";

   // for_each(data.begin(),data.end(),[](char &c){
   //    c=tolower(c);
   // });

   cout<<data<<endl;

   cout<<tolower('A')<<endl;
 
   return 0;
}