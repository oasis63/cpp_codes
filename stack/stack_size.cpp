#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int>s;

    for(int i=0;i<5;i++){
        int t;cin>>t;
        s.push(t);
    }

    int height = s.size(); //keeping the size of the stack
    // after every pop statement size of the stack decreases

    for(int i=0;i<height;i++){
        cout<<s.top()<< " ";
        s.pop();
    }

}
