#include<bits/stdc++.h>
using namespace std;

int main(){

    cout<<"Count The Number of dots in the given Grid\n"<<endl;

    string grid[] = {  ".#...#.#",
                       "....##..",
                       "##..#..#",
                       ".#.#.#.#",
                       "#.#.#.#.",
                       ".##.##.#"
                    };

    int r = 6;
    int c = 8;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


    int dp[r][c];

    dp[0][0] = 0;
 
    if(grid[0][0] == '.')
        dp[0][0] = 1;

    // first fill the first row
    for(int i=1;i<c;i++){
        if(grid[0][i]=='.'){
            dp[0][i]=dp[0][i-1]+1;
        }else{
            dp[0][i]=dp[0][i-1];
        }
    }

    cout<<endl;
    for(int i=0;i<c;i++){
        cout<<dp[0][i]<<" ";
    }


    // next fill the first column
    for(int i=1;i<r;i++){
        if(grid[i][0]=='.'){
            dp[i][0]=dp[i-1][0]+1;
        }else{
            dp[i][0]=dp[i-1][0];
        }
    }

    cout<<"\n\n";
    for(int i=0;i<r;i++){
        cout<<dp[i][0]<<endl;
    }


    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(grid[i][j]=='.'){
                dp[i][j] = dp[i-1][j] +   dp[i][j-1] - dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = dp[i-1][j] +   dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }


    cout<<"\n\n....---Final DP grid.....----\n"<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    int r1 = 1;
    int c1=3;
    int r2=3;
    int c2=5;

    cout<<"\n\n"<<endl;

    cout<<dp[r2][c2]-dp[0][c2]-dp[r2][c1-1] + dp[0][c1-1];


    cout<<endl;
    return 0;
}
