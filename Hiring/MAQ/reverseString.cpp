#include<bits/stdc++.h>
using namespace std;


// Do not reverse the special character

int check(char ch){

    if(ch >= 'a' && ch <= 'z')
        return 1;

    if(ch >= 'A'  && ch <= 'Z')
        return 1;

    return 0;
}

void solve(string str){

    int len = str.length();
    int i = 0;
    int j = len-1;


    while(i<=j){
        if(check(str[i]) && check(str[j])){
            char ch = str[j];
            str[j] = str[i];
            str[i] = ch;
            i++;
            j--;
        }else if(check(str[i]) == 0 && str[j] == 0){
            i++;
            j--;
        }else if(check(str[i]) == 0){
            i++;
        }else if(check(str[j]) == 0){
            j--;
        }
    }

    cout<<str<<endl;
}

int main(){

    string str;
    cin>>str;
    solve(str);
}
