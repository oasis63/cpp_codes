#include<bits/stdc++.h>
using namespace std;

int main(){
   int n = 54;

   if(isdigit(n))
        cout<<"digit "<<endl;

    char s[] = "123deg";
    char s2[] = "343ad34df";

    if(isdigit(s[0])){
        //cout<<s<<endl;
        int sn = atoi(s);

        cout<<sn<<endl;
    }

    if(isdigit(s2[0])){
        //cout<<s<<endl;
        int sn = atoi(s2);

        cout<<sn<<endl;
    }

    cout<<"\nChecking  characters"<<endl;

    char c='4';

    if(isdigit(c))
        cout<<c<<" is a Digit"<<endl;
    else
        cout<<c<<" is Not a digit"<<endl;


    c='a';

    if(isdigit(c))
        cout<<c<<" is a Digit"<<endl;
    else
        cout<<c<<" is Not a digit"<<endl;




}
