#include<bits/stdc++.h>
using namespace std;

int isVowel(char c){

    switch(c){
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 'Y':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return 1;
    }

    return 0;
}




int main(){
    string in,out;
    cin>>in;
    int n = in.length();

    for(int i=0;i<n;i++){

        if(!isVowel(in[i])){  //not vowel
            out += ".";
            if(isupper(in[i])){
                out += tolower(in[i]);
            }else{
                out += in[i];
            }
        }

    }

    cout<<out<<endl;

    return 0;
}
