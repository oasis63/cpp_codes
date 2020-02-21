#include<bits/stdc++.h>
using namespace std;


bool isEven(int n){
    return n%2==0?true:false;
}

void solve(string str){
    
    int len = str.length();
    
    int counts[len];
    
    if(isEven(str[len-1]-'0')){
        counts[len-1]=1;
    }else{
        counts[len-1]=0;
    }
    
    for(int i=len-2;i>=0;i--){
        
        if(isEven(str[i]-'0')){
            counts[i]=counts[i+1]+1;
        }else{
            counts[i]=counts[i+1];
        }
    }
    
    for(int i=0;i<len;i++){
        cout<<counts[i]<<" ";
    }
    
    cout<<endl;
    
}


int main() {
	
	string str;
	cin>>str;
	solve(str);
	
	return 0;
}


/*
    
    Sample I/O

    I:   574674546476

    O:   7 7 7 6 5 5 4 4 3 2 1 1

*/