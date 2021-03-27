#include<bits/stdc++.h>
using namespace std;

int main(){

 char s[100];

 cout<<"Enter a lower-cased letter sentence "<<endl;
 scanf("%[^\n]",s);

 for(int i=0;i<strlen(s);i++){
    s[i] = toupper(s[i]);`
 }

 cout<<s<<endl;

 fflush(stdin);   // to empty the input buffer


cout<<"Enter a Upper-cased letter sentence "<<endl;
 scanf("%[^\n]",s);

 for(int i=0;i<strlen(s);i++){
    s[i] = tolower(s[i]);
 }

 cout<<s<<endl;


}
