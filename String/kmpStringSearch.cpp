#include<bits/stdc++.h>
using namespace std;

/*
KMP algorithm application to search a string in another string 
*/

void prefixTable(string pattern,int f[]){
    int m = pattern.length();
    f[0]=0;
    
    int j=0,i=1;
    
    while(i<m){
        
        if(pattern[i] == pattern[j]){
            f[i]=j+1;
            i++;
            j++;
        }else if(j>0){
            j=f[j-1];
        }else{
            f[i]=0;
            i++;
        }
        
    }
}

int strStr(const string text, const string pattern) {
    
    int n = text.length();
    int m = pattern.length();
    
    int f[m];
    f[0];
    
    prefixTable(pattern,f);
    
    int i=0,j=0;
    
    while(i<n){
        if(text[i] == pattern[j]){
            if(j==m-1){
                return i-j;
            }else{
                i++;
                j++;
            }
        }else if(j>0){
            j=f[j-1];
        }else{
            i++;
        }
    }
    
    return -1;
}


int main(){


    string text = "abadjfazamanatykjfa";
    string pattern = "zamana";

    int loc = strStr(text,pattern);
    cout<<loc<<endl;

    pattern = "notpresent";

    cout<<strStr(text,pattern)<<endl;
}
