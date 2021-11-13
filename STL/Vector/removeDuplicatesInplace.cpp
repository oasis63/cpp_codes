#include<bits/stdc++.h>
using namespace std;

/*
Remove Duplicates without using any extra space
*/

int removeDuplicates2(vector<int> &A) {
    int n = A.size();
    if(n==0 || n==1)
        return n;

    int ans = 1;
    int t = 1;
    for(int i=1;i<n;i++){
        if(A[i] == A[i-1])
            continue;
        A[t]=A[i];
        t++;
        ans++;
    }
    A.resize(t);
    return ans;
}

// more - Efficient Code

int removeDuplicates(vector<int> &A) {
    int n = A.size();

    int t = 0;
    for(int i=0;i<n;i++){
        if(i<n-1 && A[i] == A[i+1])
            continue;
        else{
            A[t]=A[i];
            t++;
        }
    }

    A.resize(t);
    return t;
}



int main(){

    vector<int> vect { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

//    vector<int> vect{1,2,3,4};

    cout<<removeDuplicates(vect)<<endl;

    cout<<"--Vector after removing the duplicates---"<<endl;
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }

    return 0;
}
