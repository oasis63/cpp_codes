#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;

    while(testCases--){

         int i,n=0;

        string infix,postfix;

        cin>>infix;

        n=infix.length();

        stack<char> S;

       infix+= ')';

        S.push('(');



        for(i=0;i<=n;i++){

          if(infix[i]=='(')
          {
            S.push('(');
          }
          else if(infix[i]==')')
          {
             while(S.top()!='(')
             {
              postfix+=S.top();
              S.pop();
             }
             if(S.top()=='(')
              S.pop();
          }
          else if(infix[i]=='+' || infix[i]=='-')
          {
            while(S.top()=='+' || S.top()=='-' || S.top()=='*' || S.top()=='/')
            {
              postfix+=S.top();
              S.pop();
            }
            S.push(infix[i]);
         }
         else if(infix[i]=='*' || infix[i] == '/')
         {
           while(S.top()=='/' || S.top()=='*')
           {
             postfix+=S.top();
             S.pop();
           }
           S.push(infix[i]);
         }
         else if(infix[i]=='^')
         {
           while(S.top()=='^')
           {
             postfix+=S.top();
             S.pop();
           }
           S.push(infix[i]);
         }
         else
         {
           postfix+=infix[i];
         }
        }

        cout<<postfix<<endl;

    }
}
