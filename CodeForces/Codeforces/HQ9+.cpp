#include<bits/stdc++.h>
using namespace std;

int main(){
   string str;
   cin>>str;

    bool get = false;
    for(int i=0;i<str.length();i++){
        if(str[i]=='H' || str[i] == 'Q' || str[i] == '+'){
            get=true;
        }
    }

    if(get)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
