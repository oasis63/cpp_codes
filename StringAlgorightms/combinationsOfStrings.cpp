#include<bits/stdc++.h>
using namespace std;

/*
    Combinations  of Strings

    It is similar to finding .. subsets for the given string

    .. it is not working correctly

*/

void findCombinations(int depth,char *combination,int start,char* original){

    int len = strlen(original);

    for(int i=start;i<len;i++){
        combination[depth]  = original[i];
        combination[depth+1] = '\0';
        cout<<combination<<endl;
        if(i<len-1)
            findCombinations(depth+1,combination,start+1,original);
    }

}

int main(){

    char* orig = "abc";
    char *combination;
    int depth = 0;
    int start=0;

    int len = strlen(orig);

    combination = new char[len];

    findCombinations(depth,combination,start,orig);



    return 0;
}

