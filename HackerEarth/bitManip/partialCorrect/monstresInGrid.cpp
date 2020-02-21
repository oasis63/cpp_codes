#include <bits/stdc++.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k,i,j;
    cin>>n>>m>>k;

    int mat[n][m]={0};

    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cin>>mat[i][j];
    }

//    cout<<endl;
//
//    for(i=0;i<n;i++){
//        for(j=0;j<m;j++)
//            cout<<mat[i][j]<<" ";
//        cout<<endl;
//    }
//
//    cout<<endl;

    // sorting elements row wise

    for(i=0;i<n;i++){
        vector<int>v;
        for(j=0;j<m;j++){
            v.push_back(mat[i][j]);
        }

        sort(v.rbegin(),v.rend());

        for(j=0;j<m;j++){
            mat[i][j]=v[j];
        }
    }


     for(j=0;j<m;j++){
        vector<int>v;
        for(i=0;i<n;i++){
            v.push_back(mat[i][j]);
        }

        sort(v.rbegin(),v.rend());

        for(i=0;i<n;i++){
            mat[i][j]=v[i];
        }
    }


//    cout<<endl;
//
//    for(i=0;i<n;i++){
//        for(j=0;j<m;j++)
//            cout<<mat[i][j]<<" ";
//        cout<<endl;
//    }
//
//    cout<<endl;

    int lasers=1;

    //cout<<"\t k  " << k <<endl;

    int row=0,column=0;


    while(lasers <= k ){

        //cout<<"\t Lasers count  " <<lasers<<endl;

        // deleting monsters row wise

        for(int temp = 0 ; temp < m ; temp++)
            mat[row][temp]--;

        lasers++;

        if(lasers > k)
            break;

        // deleting monsters column wise

         for(int temp = 0 ; temp < n ; temp++)
            mat[temp][column]--;

        row++;
        column++;

        lasers ++;

    }

    int ans=0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j]==-1)
                ans++;
        }

    }

    cout<<ans<<endl;
}
