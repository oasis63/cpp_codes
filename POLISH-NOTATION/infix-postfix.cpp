#include<bits/stdc++.h>
using namespace std;

int main()
{

     int i,n=0,t=0;

  char infix[100],postfix[100];
    cout<<"Enter the infix "<<endl;
    scanf("%s",infix);

  while(infix[n]!='\0')
    n++;

  stack<char> S;

   infix[n]= ')';

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
          postfix[t]=S.top();
          S.pop();
          t++;
         }
         if(S.top()=='(')
          S.pop();
      }
      else if(infix[i]=='+' || infix[i]=='-')
      {
        while(S.top()=='+' || S.top()=='-' || S.top()=='*' || S.top()=='/')
        {
          postfix[t]=S.top();
          S.pop();
          t++;
        }
        S.push(infix[i]);
     }
     else if(infix[i]=='*' || infix[i] == '/')
     {
       while(S.top()=='/' || S.top()=='*')
       {
         postfix[t]=S.top();
         S.pop();
         t++;
       }
       S.push(infix[i]);
     }
     else if(infix[i]=='^')
     {
       while(S.top()=='^')
       {
         postfix[t]=S.top();
         S.pop();
         t++;
       }
       S.push(infix[i]);
     }
     else
     {
       postfix[t]=infix[i];
       t++;
     }
    }

   postfix[t]='\0';

   printf("%s\n",postfix);





}



