// tree data structure

#include<bits/stdc++.h>
using namespace std;


int main(){


    int num,col;
    cin>>num>>col;

    int parents[num-1];
    int colors[num];

    for(int i=0;i<(num-1);i++)
        cin>>parents[i];

    for(int i=0;i<num;i++){
        cin>>colors[i];
    }


    for(int i=0;i<num;i++){

        if(i==0){
            cout<<-1<<" ";
            continue;
        }


        bool get = false;

        int currentColor = colors[i];
        int par = parents[i-1];

        while(!get){

            if(colors[par-1] == currentColor){
                cout<<par<<" ";
                get=true;
                break;
            }
            else if( par == 1){
                break;
            }
            else{
                par=parents[par-2];
            }
        }

        if(!get){
            cout<<-1<<" ";
        }
    }

}
