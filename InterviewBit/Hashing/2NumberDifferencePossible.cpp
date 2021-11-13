#include<bits/stdc++.h>
using namespace std;

int diffPossible(const vector<int> &A, int diff) {

    int n = A.size();

     if(n<=1 || diff < 0)
        return 0;

    set<int> st;

    for(int i=0;i<n;i++){
        int d = A[i] - diff;
        int a = A[i] + diff;

        if(st.find(d) != st.end())
            return 1;
        if(st.find(a) != st.end())
            return 1;
        st.insert(A[i]);
    }

    return 0;
}

int main(){

    vector<int> vect {1,5,3};
    int target = 2;

    cout<<"Two number difference Possible : "<<diffPossible(vect,target)<<endl;

    return 0;
}
