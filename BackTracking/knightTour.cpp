// C++ program for Knight Tour problem
#include<bits/stdc++.h>
using namespace std;

#define N 8

void printSolution(int sol[N][N]){

	for (int x = 0; x < N; x++){

		for (int y = 0; y < N; y++)
			cout<<sol[x][y]<<" ";
        cout<<endl;
	}
}

bool isSafe(int x, int y, int sol[N][N]){

	return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}



int solveKTUtil(int x, int y, int move, int sol[N][N],int xMove[N], int yMove[N]){

    int next_x, next_y;

    if (move == N*N)
        return true;

    for (int k = 0; k < 8; k++){

        next_x = x + xMove[k];
        next_y = y + yMove[k];

        if (isSafe(next_x, next_y, sol)){

            sol[next_x][next_y] = move;

            if (solveKTUtil(next_x, next_y, move+1, sol,xMove, yMove) == true)
                return true;
            else
                sol[next_x][next_y] = -1;// backtracking
        }
    }

    return false;
}

bool solveKT(){

	int sol[N][N];

	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			sol[x][y] = -1;
		}
	}

	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };  // along x-axis
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };  // along y-axis

	sol[0][0] = 0;  // starting position in the chess

	if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false){
		cout<<"Solution does not exist"<<endl;
		return false;
	}
	else
		printSolution(sol);

	return true;
}


int main(){

	solveKT();


	return 0;
}
