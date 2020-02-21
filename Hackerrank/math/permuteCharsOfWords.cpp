#include<bits/stdc++.h>
using namespace std;

void subsets(string str,int n){

    int len = 1<<n;
    set<string> st;

    for(int i=1;i<len;i++){
        string sub = "";
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                sub += str[j];
            }
        }
        //cout<<sub;
        st.insert(sub);
        //cout<<endl;
    }

    //cout<<"\nSorted List"<<endl;

    for(auto i = st.begin();i!=st.end();i++){
        cout<<*i<<endl;
    }

}

int main(){

    int tc;
    cin>>tc;
    while(tc--){
        string str;
        int n;
        cin>>n;
        cin>>str;
        subsets(str,n);
    }

}
