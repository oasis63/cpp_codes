#include<bits/stdc++.h>
using namespace std;

// Reverse Stack using Recursion

void rev(stack<int> st){

    if(st.empty())
        return;
    int t = st.top();
    st.pop();
    rev(st);
    cout<<t<<" ";
}

int main(){

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    print(st);

    rev(st);
}
