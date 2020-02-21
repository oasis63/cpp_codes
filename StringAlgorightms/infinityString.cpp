#include<bits/stdc++.h>
using namespace std;

void append(char *str,int i){
    int j=2*i+1;  // 1
    int s=0,t=0;
    cout<<str<<endl;
    for(t=i+1;t<=j;t++){
        str[t] = str[s];
        s++;
    }
    str[t]='\0';
}

int main(){

    char *str;
    int i=0;
    str[i]='1';
    str[i+1]='\0';
    append(str,strlen(str)-1);
    append(str,strlen(str)-1);
    append(str,strlen(str)-1);


    cout<<str<<endl;
}
