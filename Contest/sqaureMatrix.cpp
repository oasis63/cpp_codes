#include<bits/stdc++.h>
using namespace std;

void solveLeft(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(j-1 < 0 )
        return;

    for(j=j-1;j>=0;j--){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}

void solveRight(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(j+1 >= n )
        return;

    for(j=j+1;j<n;j++){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}

void solveUp(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(i-1 < 0 )
        return;

    for(i=i-1;i>=0;i--){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}

void solveDown(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(i+1 >= n )
        return;

    for(i=i+1;i<n;i++){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}


void solveTopLeftCorner(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(i-1 < 0 || j-1<0)
        return;

    for(i=i-1,j=j-1;i>=0,j>=0;i--,j--){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}

void solveBottomLeftCorner(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(i+1 >= n || j-1<0)
        return;

    for(i=i+1,j=j-1;i<n,j>=0;i++,j--){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}

void solveTopRightCorner(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
    int len = target.length();

    if(i-1 < 0 || j+1 >= n)
        return;

    for(i=i-1,j=j+1;i>=0,j<n;i--,j++){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}

void solveBottomRightCorner(vector<vector<char>>vect,int n,int i,int j,string target,int idx,int &ans){
     int len = target.length();

     if(i+1 >= n || j+1>=n)
        return;

    for(i=i+1,j=j+1;i<n,j<n;i++,j++){
        if(vect[i][j] == target[idx]){
            idx++;
            if(idx==len){
                ans++;
                return;
            }
        }else{
            return;
        }
    }
}


void solve(vector<vector<char>> vect,int n,string target){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vect[i][j] == target[0]){
                // go towards left
                solveLeft(vect,n,i,j,target,1,ans);

                // go towards right
                solveRight(vect,n,i,j,target,1,ans);

                // go towards up
                solveUp(vect,n,i,j,target,1,ans);

                // go towards down
                solveDown(vect,n,i,j,target,1,ans);

                // go towards top left corner
                solveTopLeftCorner(vect,n,i,j,target,1,ans);

                // go towards bottom left corner
                solveBottomLeftCorner(vect,n,i,j,target,1,ans);

                 // go towards top right corner
                solveTopRightCorner(vect,n,i,j,target,1,ans);

                // go towards bottom right corner
                solveBottomRightCorner(vect,n,i,j,target,1,ans);
            }
        }
    }

    cout<<ans;
}


int main(){

    int n;
    cin>>n;

    vector<vector<char>> vect(n);

    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        for(int k=0;k<temp.length();k++){
            if(temp[k] != '#'){
                    vect[i].push_back(temp[k]);
            }
        }
    }

    string target;
    cin>>target;

    solve(vect,n,target);
}




/*

Square Matrix (100 Marks)
Given is a square matrix of alphabets which contains English letters in an arbitrary manner. While searching a word in it, you can go left to right horizontally, vertically downwards or diagonally towards left (both upwards and downwards).
You have to find the number of matches of a given word in the matrix.

For example, In the given square matrix {A#A#K,A#S#K,A#K#K},

The word "ASK" is matched four times in the input matrix. So the output will be 4.

*/
