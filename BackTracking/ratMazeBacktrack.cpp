// C++ program for Knight Tour problem
#include<bits/stdc++.h>
using namespace std;

#define N 4


void printSolution(int sol[N][N]){

	for (int x = 0; x < N; x++){

		for (int y = 0; y < N; y++)
			cout<<sol[x][y]<<" ";
        cout<<endl;
	}
	cout<<endl;
}

bool isSafe(int x, int y, int maze[N][N]){

	return ( x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaxeUtil(int maze[N][N],int x,int y,int sol[N][N]){

    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }

    if(isSafe(x,y,maze) == true){
        sol[x][y] = 1;

        if(solveMaxeUtil(maze,x+1,y,sol) == true)
            return true;
        if(solveMaxeUtil(maze,x,y+1,sol) == true)
            return true;

        // backtrack the value to 0
        sol[x][y]=0;
        return false;
    }

    return false;
}

bool solveMaxe(int maze[N][N]){

    int sol[N][N] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };

    if(solveMaxeUtil(maze,0,0,sol) == false){
        cout<<"Solution doesn't exist"<<endl;
        return false;
    }
    printSolution(sol);
    return true;
}

int main(){

    int maze[N][N] = { {1,0,0,0},{1,1,0,0},{0,1,0,0},{1,1,1,1}};

    cout<<solveMaxe(maze)<<endl;

    return 0;
}
