#include<bits/stdc++.h>
using namespace std;

int solve (string s) {
   // Write your code here
   stack<char> stk;

   int len = s.length();
   int close = 0;
   int ans = 0;
   int open = 0;

   for(int i=0;i<len;i++){

       if(s[i] == '{'){

//           if(!stk.empty()){
//                stk.push('{');
//                cout<<"push1"<<endl;
//           }else{
                // empty and close is 0
                if(close == 0){
                    stk.push('{');
                    open++;
//                    cout<<"push2"<<endl;
                }else{
                    int temp;
                    if(close%2==0){
                         temp = close/2;
                    }else{
                        temp = (close+1)/2 + 1;
                    }
                    temp-=open;
                    ans += temp;
                    if(!stk.empty())
                    stk.pop();
                    open=0;
                    close=0;
                    stk.push('{');
//                    cout<<"push3"<<endl;
                    open++;
                }



       }else{
           close++;
//           cout<<" close " << close << endl;
           if(close == 2  && !stk.empty()){
               stk.pop();
               close = 0;
//               cout<<"exectued"<< "  " <<i<<endl;
           }else if(close > 2){
                if(close%2==0){
                    ans += close/2;
                }else{
                    ans += (close+1)/2 + 1;
                }
                close=0;
           }
       }
   }

//   cout<<"out close " << close<<endl;
//   cout<<"out open " <<open<<endl;

   if(close%2==0){
        ans += close/2;
    }else{
        ans += (close+1)/2 + 1;
    }

    if(stk.size() != 0){
        ans += stk.size() * 2;
//        cout<<stk.size() <<"   ----  " <<stk.top()<<endl;
    }

   return ans;
}

int main() {
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        string S;
        cin>>S;
        int out_;
        out_ = solve(S);
        cout << out_;
        cout << "\n";
    }
}
