#include<bits/stdc++.h>
using namespace std;

bool totalMatrix[1001][1001] = {false};

void printVectors(vector<vector<int>> obstacles){
     for(int i=0;i<obstacles.size();i++){
        totalMatrix[obstacles[i][0]][obstacles[i][1]]=true;
    }
}


int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int ans = 0;
    int possiblePlaces = 0;
    printVectors(obstacles);
    // right->top
    for(int r=r_q+1,c=c_q+1;r<=n&&c<=n;r++,c++){
        if(totalMatrix[r][c])
            break;
        possiblePlaces++;
    }
    // right -> bottom
    for(int r=r_q-1,c=c_q+1;r>=1&&c<=n;r--,c++){
        if(totalMatrix[r][c])
            break;
        possiblePlaces++;
    }
     // left -> top
    for(int r=r_q+1,c=c_q-1;r<=n&&c>=1;r++,c--){
        if(totalMatrix[r][c])
            break;
        possiblePlaces++;
    }
    // left-> bottom
    for(int r=r_q-1,c=c_q-1;r>=1&&c>=1;r--,c--){
        if(totalMatrix[r][c])
            break;
        possiblePlaces++;
    }
    // fixed rq
    for(int c=c_q+1;c<=n;c++){
        //fixed rq
        if(totalMatrix[r_q][c])
            break;
        possiblePlaces++;
    }

     // backward left
    for(int c=c_q-1;c>=1;c--){
        //fixed rq
        if(totalMatrix[r_q][c])
            break;
        possiblePlaces++;
    }

    // column top
    for(int r=r_q+1;r<=n;r++){
        //fixed cq
        if(totalMatrix[r][c_q])
            break;
        possiblePlaces++;
    }
    // fixed cq
    for(int r=r_q-1;r>=1;r--){
        //fixed cq
        if(totalMatrix[r][c_q])
            break;
        possiblePlaces++;
    }

    return possiblePlaces;
}


int main(){
    int n = 5;
    int k = 3;
    int r_q = 4;
    int c_q = 3;
    vector<vector<int>> obstacles{
        {
            5,5
        },
        {
            4,2
        },
        {
            2,3
        }
    };



   cout<<"possible attack places : " <<queensAttack(n,k,r_q,c_q,obstacles)<<endl;

    return 0;
}


/*
5 3
4 3
5 5
4 2
2 3

*/
