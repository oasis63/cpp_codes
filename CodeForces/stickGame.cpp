#include<bits/stdc++.h>
using namespace std;

string solve(int n,int m,string name){

    if(n<=0 || m<=0){
        if(name == "M")
            return "Akshat";
        else if(name == "A")
            return "Malvika";
    }

    if(name=="A")
        return solve(n-1,m-1,"M");
    else if(name=="M")
        return solve(n-1,m-1,"A");

}

int main(){
   
   int n,m;
   cin>>n>>m; 
    
   string str = solve(n,m,"A");

   cout<<str<<endl;
}