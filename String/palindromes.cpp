#include<bits/stdc++.h>
using namespace std;

void solve(string str){

    int i=0;
    int j = str.length()-1;
    int get = 1;
    while(i<j){
        if(str[i]!=str[j]){
            get=0;
            break;
        }
        i++;
        j--;
    }

    if(get)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}

int main(){
    
    solve("a");

    return 0;
}