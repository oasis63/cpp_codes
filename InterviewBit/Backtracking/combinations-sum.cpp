#include<bits/stdc++.h>
using namespace std;

/*
The same repeated number may be chosen from C unlimited number of times.
*/

void combineHelper(vector<int> &numbers, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {

    if(currentSum > target)
        return;

    if(currentSum == target){
        ans.push_back(current);
        return;
    }


    for(int i=index;i<numbers.size();i++){

        current.push_back(numbers[i]);
        currentSum += numbers[i];

        combineHelper(numbers,i,current,currentSum,target,ans);

        current.pop_back();
        currentSum -= numbers[i];

    }

}

vector<vector<int> > combineSum(vector<int> numbers,int target) {

    vector<vector<int> > ans;
    vector<int> current;

    sort(numbers.begin(),numbers.end());
    vector<int> uniqueNumbers;
    for(int i=0;i<numbers.size();i++){

        if(i==0 || numbers[i] != numbers[i-1]){
            uniqueNumbers.push_back(numbers[i]);
        }
    }

    combineHelper(uniqueNumbers,0,current,0,target,ans);


    return ans;
}

int main(){

    /*vector<int> numbers {10,1,2,7,6,1,5};
    int target = 8;*/

    vector<int> numbers{2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combineSum(numbers,target);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
