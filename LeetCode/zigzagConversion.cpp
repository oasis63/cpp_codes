#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long


string solve(string s,int numRows){

    if(numRows == 1)
        return s;

    vector<string> rows(min(numRows,int(s.size())));

    int curRow = 0;
    bool goingDown = false;

    for(char c : s){
        rows[curRow] += c;
        if(curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string ret;
    for(string row : rows)
        ret += row;
    

    return ret;
}


int main(){

    string s = "PAYPALISHIRING";
    int  numRows = 4;

    cout<<solve(s,numRows)<<endl;

    return 0;
}


/*

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I




Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR





*/



