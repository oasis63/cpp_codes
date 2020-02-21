#include<bits/stdc++.h>
using namespace std;

bool isBalancedParenthesis(string str){

    int len = str.length();
    stack<char> stk;

    for(int i=0;i<len;i++){
        if(str[i] == ')'){
            if(stk.empty() || stk.top() != '(')
               return false;
            stk.pop();
        }else{
            stk.push(str[i]);
        }
    }

    if(stk.empty())
        return true;

    return false;
}
void parenthesisUtil(int &n,string &current,vector<string> &ans){

    if(current.length() == 2*n){
        if(isBalancedParenthesis(current))
            ans.push_back(current);
        return;
    }

    current.push_back('(');
    parenthesisUtil(n,current,ans);
    current.pop_back();

    current.push_back(')');
    parenthesisUtil(n,current,ans);
    current.pop_back();
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string current;
    parenthesisUtil(n,current,ans);

    sort(ans.begin(),ans.end());
    return ans;
}



int main(){

    int n = 3;

    vector<string> ans = generateParenthesis(n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}

/*
Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/
