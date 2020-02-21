#include<bits/stdc++.h>
using namespace std;

void displayChess(vector<int> chess[] ,int n){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}


bool solve(vector<int>chess[],int n,int bx,int by,int cx,int cy){

    //bool ans1 = ans2=ans3=ans4=ans5=ans6=ans7=ans8=false;

    bool ans1 = false;

    if(bx==cx && by==cy){
        return true;
    }

   if(bx < cx){

        //if(by > cy){
            if(chess[bx+1][by-1]!=1 && bx < n && by > 1){
                ans1 = solve(chess,n,bx+1,by-1,cx,cy);
            }else if(chess[bx][by-1]!=1 &&  by > 1){
                ans1 = solve(chess,n,bx,by-1,cx,cy);
            }else if(chess[bx+1][by]!=1 && bx < n){
                ans1 = solve(chess,n,bx+1,by,cx,cy);
            }else if(chess[bx+1][by+1]!=1 && bx < n && by < n){
                ans1 = solve(chess,n,bx+1,by+1,cx,cy);
            }else if(chess[bx][by+1]!=1  && by < n){
                ans1 = solve(chess,n,bx,by+1,cx,cy);
            }else if(chess[bx-1][by+1]!=1 && bx > 1 && by < n){
                ans1 = solve(chess,n,bx-1,by+1,cx,cy);
            }else if(chess[bx-1][by]!=1 && bx > 1){
                ans1 = solve(chess,n,bx-1,by,cx,cy);
            }else if(chess[bx-1][by-1]!=1 && bx > 1 && by > 1){
                ans1 = solve(chess,n,bx-1,by-1,cx,cy);
            }else{
                return false;
            }
        //}

    }else if(bx > cx){

        //if(by > cy){

            if(chess[bx-1][by+1]!=1 && bx > 1 && by < n){
                ans1 = solve(chess,n,bx-1,by+1,cx,cy);
            }else if(chess[bx-1][by]!=1 && bx > 1){
                ans1 = solve(chess,n,bx-1,by,cx,cy);
            }else if(chess[bx-1][by-1]!=1 && bx > 1 && by > 1){
                ans1 = solve(chess,n,bx-1,by-1,cx,cy);
            }else if(chess[bx][by+1]!=1  && by < n){
                ans1 = solve(chess,n,bx,by+1,cx,cy);
            }else if(chess[bx+1][by-1]!=1 && bx < n && by > 1){
                ans1 = solve(chess,n,bx+1,by-1,cx,cy);
            }else if(chess[bx][by-1]!=1 && by > 1){
                ans1 = solve(chess,n,bx,by-1,cx,cy);
            }else if(chess[bx+1][by]!=1 && bx < n){
                ans1 = solve(chess,n,bx+1,by,cx,cy);
            }else if(chess[bx+1][by+1]!=1 && bx < n && by < n){
                ans1 = solve(chess,n,bx+1,by+1,cx,cy);
            }else{
                return false;
            }
        //}
    }
   




   /*if(ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8)
        return true;
    return false;*/

    if(ans1)
        return true;
    else
        return false;

}


int main(){
    
    int n;      // dimensions
    int ax,ay;  // queen
    int bx,by;  // king
    int cx,cy;  // final

    cin>>n;
    cin>>ax>>ay;
    cin>>bx>>by;
    cin>>cx>>cy;

    vector<int> chess[n+1];

    int i=0,j=0;

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            chess[i].push_back(0);
        }
    }

    // around the queen

    chess[ax][ay] = 1;

    if(ax > 1 ){
        chess[ax-1][ay]=1;

        if(ay > 1){
            chess[ax-1][ay-1] = 1;
        }

        if(ay < n){
            chess[ax-1][ay+1] = 1;
        }
    }

    if(ay > 1){
        chess[ax][ay-1] = 1;
    }

    if( ay < n){
        chess[ax][ay+1] = 1;
    }



    if(ax < n){
        chess[ax+1][ay]=1;

        if(ay > 1){
            chess[ax+1][ay-1] = 1;
        }

        if(ay < n){
            chess[ax+1][ay+1] = 1;
        }
    }




    int qb1=0,qb2=0,qb3=0,qb4=0;
    int qc1=0,qc2=0,qc3=0,qc4=0;


    if(bx < ax && by < ay){
        qb1 = 1;
    }else if(bx > ax && by < ay){
        qb2 = 1;
    }else if(bx > ax && by > ay){
        qb3 = 1;
    }else if(bx < ax && by > ay){
        qb4 = 1;
    }

    if(cx < ax && cy < ay){
        qc1 = 1;
    }else if(cx > ax && cy < ay){
        qc2 = 1;
    }else if(cx > ax && cy > ay){
        qc3 = 1;
    }else if(cx < ax && cy > ay){
        qc4 = 1;
    }

    // Diagonals 
    
    i = ax,j=ay;

    while(i>0 && j>0){
        chess[i][j]=1;
        i--;
        j--;
    }    


    i = ax,j=ay;

    while(i>0 && j<=n){
        chess[i][j]=1;
        i--;
        j++;
    }   



    i = ax,j=ay;

    while(i<=n && j<=n){
        chess[i][j]=1;
        i++;
        j++;
    }   


    i = ax,j=ay;

    while(i<=n && j>0){
        chess[i][j]=1;
        i++;
        j--;
    }   


   // displayChess(chess,n);


    // solve the problem 

    if(qb1 != qc1 || qb2 != qc2 || qb3 != qc3 || qb4 != qc4){
        cout<<"NO"<<endl;
    }else{
        //cout<<"YES"<<endl;

        bool res = solve(chess,n,bx,by,cx,cy);

        if(res){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}