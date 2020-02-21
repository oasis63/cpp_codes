#include<bits/stdc++.h>
using namespace std;

/*
Each number from the collection may only be used once in the combination
*/

void solveUtil(vector<int> numbers,vector<int> current,vector<vector<int>> &ans,int currentSum,int index,int target){

    if(currentSum > target)
        return;
    if(currentSum == target){
        ans.push_back(current);
        return;
    }

    for(int i=index;i<numbers.size();i++){
        current.push_back(numbers[i]);
        currentSum += numbers[i];

        solveUtil(numbers,current,ans,currentSum,i+1,target);

        current.pop_back();
        currentSum -= numbers[i];
    }

}


vector<vector<int> > combinationSum(vector<int> &numbers, int target) {

    vector<vector<int>> ans;
    vector<int> current;
    sort(numbers.begin(),numbers.end());

    solveUtil(numbers,current,ans,0,0,target);

    sort(ans.begin(),ans.end());

    vector<vector<int>> ret;

    for(int i=0;i<ans.size();i++){
        if(i==0 || ans[i] != ans[i-1]){
            ret.push_back(ans[i]);
        }
    }

    return ret;
}

int main(){

    vector<int> numbers {10,1,2,7,6,1,5};
    int target = 8;


    /*vector<int> numbers{2,3,6,7};
    int target = 7;*/

    vector<vector<int>> ans = combinationSum(numbers,target);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
