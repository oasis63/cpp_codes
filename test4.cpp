#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long 

int solve(string A) {
    int len = A.length();
    stack<char> stk;
    for(int i=0;i<len;i++){
        char par = A[i];
        if(par == '('){
            stk.push(par);
        }else{
            if(stk.size() != 0){
              char tpChar = stk.top();
              if(tpChar == '(')
                  stk.pop();
            }else
              stk.push(')');
        }
    }
    if(stk.size() == 0)
        return 1;
    return 0;
}


int main(){

    string testStr = ")((";

    cout<<solve(testStr)<<endl;

    vector<int> vect;
    int len = vect.size();

    


    return 0;
}