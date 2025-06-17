#include <bits/stdc++.h>
using namespace std;


void solve(vector<vector<int>> &ans, vector<int> &vect, vector<int> A , int  ind, int n, int k){
    if( ind > n ){ 
        return;
    }
    if(vect.size() == k ){
        if(find(ans.begin(), ans.end(), vect) == ans.end())
            ans.push_back(vect);
        return;
    }
    for(int i=ind;i<n;i++){
        vect.push_back(A[i]);
        solve(ans, vect, A , i+1, n, k );
        vect.pop_back();
    }
}

vector<vector<int> > combine(int n, int B) {
    
    vector<int> A;
    for(int i = 1;i<=n;i++){
        A.push_back(i);
    }

    vector<vector<int>> ans;
    vector<int> vect;
    
    solve(ans, vect, A , 0, n, B);
    
    return ans;
}



int main(){

    // vector<string> A = {"ab", "cd"};

   int A = 4;
   int b = 2;

    vector<vector<int>> ans = combine(A,b);

    // cout << endl;
    for (auto t : ans){
        // cout<<"size : " << t.size() <<endl;
        for (auto i : t){
            cout << i << "  ";
        }
        cout << endl;
    }

    return 0;
}