#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> &vect, vector<int> A , int  ind, int n, int sum , int curr_sum){
    if( ind > n || curr_sum > sum ){ 
        return;
    }
    if(curr_sum == sum ){
        if(find(ans.begin(), ans.end(), vect) == ans.end())
            ans.push_back(vect);
        return;
    }
    for(int i=ind;i<n;i++){
        curr_sum += A[i];
        vect.push_back(A[i]);
        solve(ans, vect, A , i, n, sum ,  curr_sum);
        vect.pop_back();
        curr_sum -= A[i];

    }
}

vector<vector<int> > combinationSum(vector<int> &A, int sum) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> vect;
    int curr_sum = 0;
    int n = A.size();
    
    solve(ans, vect, A , 0, n, sum ,  curr_sum);
    
    return ans;
}


int main(){

    // vector<string> A = {"ab", "cd"};

    vector<int> A = {8, 10, 6, 11, 1, 16, 8, 2 , 3,5, 6 };
    int b = 40;

    vector<vector<int>> ans = combinationSum(A,b);

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