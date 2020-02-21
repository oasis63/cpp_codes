#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   string str;
   cin>>n;
   cin>>str;

   string out = "";
   int j=0;
   out +=str[0];

   int len = str.length();

   for(int i=1;i<len;i++){
        if(out[j]!=str[i]){
            j++;
            out+=str[i];
        }
   }

    j++;
    //cout<<j<<endl;
    cout<<(n-j)<<endl;

}
