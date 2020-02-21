#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int counter=0;
    int curr = 0;
    string str;
    int tc;cin>>tc; // testcases
    while(tc--){
        cin>>str;       // input string
        counter=0;
        curr=0;
        stack<int> st;
        int len = str.length();
        for(int i=0;i<len;i++){
            if(str[i]=='('){
                curr=++counter;
                st.push(curr);
                cout<<counter<<" ";
            }else if(str[i]==')'){
                curr = st.top();
                cout<<curr<<" ";
                st.pop();
            }
        }
        while(!st.empty()){
            st.pop();
        }
        cout<<endl;
       // system("pause");
    }
}
