#include<bits/stdc++.h>
using namespace std;

/*
    Permutations of Strings
*/


void findPermutations(int depth,char *permutation,int *used,string original){
    int len = original.length();

    if(depth == len){
        cout<<permutation<<endl;
    }else{

        for(int i=0;i<len;i++){
            if(!used[i]){
                used[i]=1;
                permutation[depth] = original[i];
                findPermutations(depth+1,permutation,used,original);
                used[i]=0;
            }

        }
    }
}

int main(){

    string orig = "abc";

    int *used;
    int len = orig.length();
    used = new int[len];

    for(int i=0;i<len;i++){
        used[i] = 0;
    }

    char *permutation;
    int depth = 0;

    findPermutations(depth,permutation,used,orig);

    return 0;
}

