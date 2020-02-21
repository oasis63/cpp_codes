#include<bits/stdc++.h>
using namespace std;

int main(){
   string str1,str2;
   cin>>str1>>str2;

    int len = str1.length();

    for(int i=0;i<len;i++){
        if(isupper(str1[i])){
            str1[i] = tolower(str1[i]);
        }

        if(isupper(str2[i])){
            str2[i] = tolower(str2[i]);
        }
    }

    if(str1 == str2)
        cout<<0<<endl;
    else if(str1 < str2){
        cout<<-1<<endl;
    }else{
        cout<<1<<endl;
    }

}
