#include<bits/stdc++.h>
using namespace std;

/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons)

*/


void generateResult(string &str,int index,string &current,vector<string> &ans,vector<string> &mapings){

    if(index > str.length() || current.length() > str.length()){
        return;
    }

    if(current.length() == str.length()){
        ans.push_back(current);
        return;
    }

    int idx = (int)(str[index]-'0');

     for(int i=0;i<mapings[idx].size();i++){

        current.push_back(mapings[idx][i]);

        generateResult(str,index+1,current,ans,mapings);

        current.pop_back();

    }
}

vector<string> letterCombinations(string str) {
    vector<string> mapings{"0","1","abc"
                ,"def","ghi","jkl","mno",
                "pqrs","tuv","wxyz" };

    vector<string>ans;
    string current;
    generateResult(str,0,current,ans,mapings);

    return ans;
}

int main(){

    string str = "23";

    vector<string> ans = letterCombinations(str);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
