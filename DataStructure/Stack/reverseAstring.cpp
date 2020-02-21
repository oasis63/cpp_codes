#include<bits/stdc++.h>
using namespace std;

void reverseString(char *c , int len){
    stack<char>s;

    for(int i=0;i<len;i++)
        s.push(c[i]);

    for(int i=0;i<len;i++){
        c[i]=s.top();
        s.pop();
    }


}

int main(){
    char c[100];
    cout<<"Enter a String"<<endl;
    gets(c);
    reverseString(c,strlen(c));
    cout<<c<<endl;
}
