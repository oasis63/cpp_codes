#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;

    string str;
    int x=0;

   while(n--){
        cin>>str;
        if(str[1]=='+'){
            x++;
        }else{
            x--;
        }
   }

   cout<<x<<endl;
}
