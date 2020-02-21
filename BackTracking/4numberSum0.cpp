#include <bits/stdc++.h>
using namespace std;

void print(vector<int> vect){

    sort(vect.begin(),vect.end());

    int n = vect.size();
    for(int i=0;i<n;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

void helper(vector<vector<int>> &result,vector<int> vect){
    sort(vect.begin(),vect.end());
    result.push_back(vect);
}


void solveUtil(vector<int> &vect,int index,int sum,vector<int> &ans ,vector<vector<int>> &result){
    if(index >= vect.size()){    // base case of recurrsion 

        if(ans.size() == 4  && sum == 0){
            //sort(ans.begin(),ans.end());
            //print(ans);
            //result.push_back(ans);
            helper(result,ans);
        }

        return;
    }

    if(sum  == 0 && ans.size() == 4){
//            cout<<"yes"<<endl;
        //sort(ans.begin(),ans.end());
        //print(ans);
        //result.push_back(ans);
        helper(result,ans);
        return;
    }

    // ignore
    solveUtil(vect,index+1,sum,ans,result);

    // include
    ans.push_back(vect[index]);
    sum += vect[index];
    solveUtil(vect,index+1,sum,ans,result);
    sum -= vect[index];
    ans.pop_back();

}


vector<vector<int>> solve(vector<int> &vect){
    vector<int> ans;
    vector<vector<int>>result;
    solveUtil(vect,0,0,ans,result);
    sort(result.begin(),result.end());
    return result;
}


int main(){
    vector<int> vect{1,0,-1,0,-2,2};
    vector<vector<int>> ans = solve(vect);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
