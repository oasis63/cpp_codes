#include<bits/stdc++.h>
using namespace std;

int main(){
   int n = 54;

   char t='a';

   if(isalnum(n))
        cout<<n<<" is a Alpha or number "<<endl;

    if(isalnum(t))
        cout<<t<<" is a Alpha or  number "<<endl;
    else
        cout<<t<<" is not a Alpha or  number "<<endl;


    t='$';

    if(isalnum(t))
        cout<<t<<" is a Alpha or  number "<<endl;
    else
        cout<<t<<" is not a Alpha or  number "<<endl;

    char s[] = "123deg";


    if(isdigit(s[0])){
        //cout<<s<<endl;
        int sn = atoi(s);

        cout<<sn<<endl;
    }

    char s2[] = "f343ad34df";

    if(isalpha(s2[0]))
        cout<<"first Character of "<<s2<<" is alphabet "<<endl;
    else
        cout<<"first Character of "<<s2<<" is not alphabet "<<endl;

}
