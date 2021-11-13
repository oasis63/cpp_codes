#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    
    int n = grid.size();
    int c = grid[0].size();


     cout<<"\n\n The Input Grid \n"<<endl;


    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"first column "<<endl;

    for(int i=0;i<grid.size();i++){
        cout<<grid[i][0]<<endl;
    }

    cout<<"-----"<<endl;


    // fill the first  row
    for(int j=1;j<grid[0].size();j++){
        grid[0][j] += grid[0][j-1]; 
    }


     // fill the first  column
    for(int i=1;i<grid.size();i++){
        grid[i][0] += grid[i-1][0]; 
    }



    // fill the all the other cells 

    for(int i=1;i<grid.size();i++){
        for(int j=1;j<grid[i].size();j++){
            if(grid[i-1][j] < grid[i][j-1]){
                grid[i][j] += grid[i-1][j];
            }else{
                grid[i][j] += grid[i][j-1];
            }
        }
    }


    cout<<"\n\n The Final Grid \n"<<endl;


    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


    return grid[n-1][c-1];

}

int main(){
    

    vector<vector<int>> grid {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    vector<vector<int>> grid2 {{1,2,5},{3,2,1}};

    vector<vector<int>> grid3 {{1,2},{5,6},{1,1}};


    int ans = minPathSum(grid3);
        
    cout<<"The final Ans : "<<ans<<endl;

    return 0;
}