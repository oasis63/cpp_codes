#include<bits/stdc++.h>
using namespace std;


int **transpose(int **matrix,int row,int column){

    int **tran;
    tran = new int*[column];
    for(int i=0;i<column;i++){
        tran[i] = new int[row];
    }

    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            tran[i][j]=0;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            tran[j][i]=matrix[i][j];
        }
    }


    return tran;
}

int main(){

    int row = 3 ;
    int column = 4;

    int **matrix;
    matrix = new int*[row];
    
    for(int i=0;i<row;i++){
        matrix[i]=new int[column];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            matrix[i][j]=i*j+1;
        }
    }

    cout<<"\nOriginal Matrix : "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    int **tran = transpose(matrix,row,column);

    cout<<"\nTranspose Matrix : "<<endl;
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            cout<<tran[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
