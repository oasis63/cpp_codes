#include<bits/stdc++.h>
using namespace std;

// Nearest Smaller Element

vector<int> prevSmaller(vector<int> &A) {

    stack<int> stk;
    vector<int> ans;

    int n = A.size();

    for(int i=0;i<n;i++){

        while(!stk.empty() && stk.top() >= A[i])
            stk.pop();

        if(stk.empty())
            ans.push_back(-1);
        else
            ans.push_back(stk.top());

        stk.push(A[i]);
    }
    return ans;
}




int main(){

    vector<int> input{4, 5, 2, 10, 8};

    vector<int> ans = prevSmaller(input);

    cout<<"Nearest Smaller Element"<<endl;

    for(int i=0;i<input.size();i++){
        cout<<input[i]<<"\t";
    }

    cout<<endl;

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\t";
    }

    return 0;
}
