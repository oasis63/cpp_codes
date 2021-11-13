#include<bits/stdc++.h>
using namespace std;

int main(){

    int tc,n,m;cin>>tc;

    while(tc-- > 0){
        cin>>n>>m;

        char mat[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cout<<mat[i][j];
//            }
//            cout<<endl;
//        }

         string str;
         cin>>str;

         int len = str.length();

         int count=0;

         for(int s=0;s<len;s++){


            int get = 0;
            for(int j=0;j<m;j++){
                if(mat[s%n][j] == str[s]){
                    get=1;
                    mat[s%n][j]='-';
                    count++;
                    break;
                }
            }
            if(!get){
               count=0;
               break;
            }


         }

         if(count==len)
            cout<<"Yes"<<endl;
         else
            cout<<"No"<<endl;

    }

}
