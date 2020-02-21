#include<bits/stdc++.h>
using namespace std;

// KMP String Searching Algorithm

// O(n+m)

void printArray(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void prefixTable(char pattern[],int m,int f[]){

    int i=1,j=0;
    f[0]=0;

    while(i<m){

        if(pattern[i]==pattern[j]){
            f[i]=j+1;
            i++;
            j++;
        }else if(j>0){
            j=f[j-1];
        }else{
            f[i]=0;
            i++;
        }
    }

    printArray(f,m);
}

int kmp(char text[],int n,char pattern[],int m){

    int f[m];
    f[0]=0;
    prefixTable(pattern,m,f);

    printArray(f,m);

    int i=0,j=0;

    while(i<n){
        if(text[i]==pattern[j]){

            if(j==m-1){
                return i-j;
            }else{
                i++;
                j++;
            }

        }else if(j>0){
            j=f[j-1];
        }else{
            i++;
        }
    }

    return -1;
}

int main(){

    char text[] = "abxabcabcaby";
    char pattern[] = "abcaby";

   // char text[] = "abcxabcdabxabcdabcdabcy";
    //char pattern[] = "abcdabcy";

    int n = strlen(text);
    int m = strlen(pattern);

    cout<<n<<endl;
    cout<<m<<endl;

    cout<<kmp(text,n,pattern,m)<<endl;
}
