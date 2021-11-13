#include<bits/stdc++.h>
using namespace std;


int findMinimumInsertions(string str,int beg,int end){
    if(beg > end)
        return INT_MAX;
    if(beg == end)
        return 0;
    if(beg == end-1){
        if(str[beg] == str[end])
            return 0;
        else
            return 1;
    }

    if(str[beg] == str[end])
        return findMinimumInsertions(str,beg+1,end-1);
    else
        return min(findMinimumInsertions(str,beg+1,end),findMinimumInsertions(str,beg,end-1))+1;


}


int main(){

    int tc;
    cin>>tc;

    string str;

    while(tc--){
        cin>>str;
        cout<<findMinimumInsertions(str,0,str.length()-1)<<endl;
    }

    return 0;
}
