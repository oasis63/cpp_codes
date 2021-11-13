/*
    Minimum characters to be added at front to make string palindrome

    /// Concept ....




*/

#include<bits/stdc++.h>
using namespace std;

void diplayArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void prefixTable(string pattern,int f[]){

    int m = pattern.length();

    int i = 1,j=0;  
    f[0] = 0;

    while(i<m){

        if(pattern[i] == pattern[j]){
            f[i] = j+1;
            i++;
            j++;
        }else if(j>0){
            j=f[j-1];
        }else{
            f[i]=0;
            i++;
        }
    }

    diplayArr(f,m);
}

int minimumCharAddedToFront(string str){

    string revStr = str;
    reverse(revStr.begin(),revStr.end());
    string concat = str + "$" + revStr;

    int n = concat.length();

    int f[n];
    f[0] = 0;
    prefixTable(concat,f);

    return ( str.length() - f[n-1]);
}


int main(){


    string str =  "ABC";
    
    cout<<minimumCharAddedToFront(str)<<endl;


    return 0;
}

/*

Efficient Approach : Start checking the string each time if it is palindrome, 
and if not, then delete the last character and check again. After deleting count 
number of characters from the last i.e., 
the characters to be added to front, there will be a string which will be palindrome.

*/