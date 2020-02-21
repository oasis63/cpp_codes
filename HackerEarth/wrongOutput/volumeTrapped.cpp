#include<bits/stdc++.h>
using namespace std;

int volume_trapped (vector<string> grid) {
   // Write your code here

   int vol=0;

    for(int i=0;i<grid.size();i++){

            for(int j=0;j<grid[i].length();j++){
                if(grid[i][j]=='*'){
                int k=j+1;
                int temp=0;

                while(grid[i][k]=='.' && k<grid[i].length()){
                    k++;
                    temp++;
                }

                if(grid[i][k]=='*')
                vol += temp;
            }



            }

        }


   return vol;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<string> grid(N);
    for(int i_grid=0; i_grid<N; i_grid++)
    {
    	cin >> grid[i_grid];
    }

    int out_;
    out_ = volume_trapped(grid);
    cout << out_;
}
