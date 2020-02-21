#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    while(getline(cin,text)){
    //cout<<text<<endl;
        int len = text.length();
        
        string s;
        
        int i=0;
        
        for(i=0;i<len-1;i++){
            if(text[i]=='-' && text[i+1]=='>'){
                //text[i]='.';
                //text[i+1]='\0';
                s+='.';
                i+=1;
                continue;
            }
            
            if(text[i]=='/' && text[i+1]=='/')
               break;
            
            s+=text[i];
        }
        
        for(;i<len;i++)
            s+=text[i];
        
        
        cout<<s<<endl;
    }
    
}
