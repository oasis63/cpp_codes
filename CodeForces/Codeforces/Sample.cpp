#include<bits/stdc++.h>
using namespace std;

int main(){
   string str;
   cin>>str;

   string out ;
   out = "";

   int len = str.length();

   for(int i=0;i<len;i++){
        if(str[i]!='+'){
            out += str[i];
        }
   }


   sort(out.begin(),out.end());
   len = out.length();
   for(int i=0;i<len-1;i++)
        cout<<out[i]<<"+";

    cout<<out[len-1]<<endl;

}
