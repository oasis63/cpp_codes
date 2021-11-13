#include<bits/stdc++.h>
using namespace std;

void removeAdjacent(string str){
     int len = str.length();
    stack<char>stk;
    for(int i=0;i<len;i++){

        if(stk.empty() == true){
            stk.push(str[i]);
        }else if(stk.top() == str[i]){
            stk.pop();
        }else if(str[i] != str[i-1])
             stk.push(str[i]);
    }
    string ans;
    while(!stk.empty()){
        ans = stk.top() + ans;
        stk.pop();
    }
    cout<<ans<<endl;
}

int main(){

    string str = "acaaabbbacdddd";
    removeAdjacent(str);

}
