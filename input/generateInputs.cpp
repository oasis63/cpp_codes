#include<bits/stdc++.h>
using namespace std;

int main(){

    //int tc = 1000;

    int tc = rand()%1001;

    ofstream fout;
    fout.open("inputs.txt");

    fout<<tc<<endl;

    while(tc--){

        int n = rand()%100001;
        for(int i=0;i<n;i++){
            fout<<rand()%10000001<<" ";
        }
        fout<<endl;
    }

    return 0;
}
