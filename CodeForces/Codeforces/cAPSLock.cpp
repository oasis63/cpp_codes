#include<bits/stdc++.h>
using namespace std;

int main(){
   string str;
   cin>>str;

    if(str.length()==1){
        if(isupper(str[0]))
            cout<<(char)tolower(str[0])<<endl;
        else
           cout<<(char)toupper(str[0])<<endl;
    }
    else if(isupper(str[0]) && islower(str[1]) && str.length()>1){
        cout<<str<<endl;
    }else{
        if(islower(str[0]) && isupper(str[1])){

            // remaining chars should also be upper case
            string ans = "";
            ans += (char)toupper(str[0]);

            bool cb = true;
            for(int i=1;i<str.length();i++){
                if(!isupper(str[i])){
                    cb=false;
                    break;
                }else{
                    ans += (char)tolower(str[i]);
                }
            }

            if(!cb){
                cout<<str<<endl;
            }else{
                cout<<ans<<endl;
            }


        }else if(isupper(str[0]) && isupper(str[1])){
//            cout<<str[0];
//            for(int i=1;i<str.length();i++){
//                cout<<(char)tolower(str[i]);
//            }
//            cout<<endl;
            string ans = "";
            ans += (char)tolower(str[0]);

            bool cb = true;
            for(int i=1;i<str.length();i++){
                if(!isupper(str[i])){
                    cb=false;
                    break;
                }else{
                    ans += (char)tolower(str[i]);
                }
            }

            if(!cb){
                cout<<str<<endl;
            }else{
                cout<<ans<<endl;
            }


        }else{
            cout<<str<<endl;
        }
    }
}
