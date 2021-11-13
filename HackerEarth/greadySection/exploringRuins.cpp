#include<bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin>>str;
    int len = str.length();
    string ans="";

    if(len==1){
        if(str[0]=='?'){
            cout<<'a'<<endl;
        }else{
            cout<<str[0]<<endl;
        }

        return 0;
    }


    if(str[0] == '?' && str[1]!='a'){
        ans+='a';
    }else if(str[0] == '?' && str[1]!='b'){
        ans+='b';
    }else{
        ans+=str[0];
    }

    int i=0;

    for(i=1;i<len-1;i++){
        if(ans[i-1]=='a' && str[i] == '?' ){
            ans+='b';
        }else if(ans[i-1]!='a' && str[i] == '?' && str[i+1]!='a' ){
            ans+='a';
        }else if(ans[i-1]!='a' && str[i] == '?' && str[i+1]=='a' ){
            ans+='b';
        }else{
            ans += str[i];
        }
    }

	if(str[i]=='?'){
	    if(ans[i-1] == 'a'){
	        ans+='b';
	    }else{
	        ans+='a';
	    }
	}else{
	    ans += str[i];
	}

	cout<<ans<<endl;

	return 0;
}
