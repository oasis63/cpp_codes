#include <bits/stdc++.h> 
using namespace std; 


vector<int> flip(string A) {
    
    int n = A.length();
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        if(A[i]=='1'){
            vect[i]=-1;
        }else{  // 0 entry
            vect[i]=1;
        }
    }

    pair<int,int> ans = make_pair(INT_MAX,INT_MAX);

    int best_till_now=0,best_ending_here = 0,l=0;
    
    // kadane's algorithm

    for(int i=0;i<n;i++){
        if(best_ending_here+vect[i] < 0){
            l=i+1;
            best_ending_here=0;
        }else{
            best_ending_here += vect[i];
        }

        if(best_ending_here > best_till_now){
            best_till_now = best_ending_here;
            ans.first = l;
            ans.second = i;
        }
    }

    if(ans.first == INT_MAX)
        return vector<int>();

    vector<int> ret;
    ret.push_back(ans.first+1);
    ret.push_back(ans.second+1);

    return ret;
}


int main() { 

    // string s = "010";

    string s = "010111";

    vector<int> vect = flip(s);

    if(vect.size() == 0){
        cout<<"empty"<<endl;
    }else{
        cout<<vect[0]<<" "<<vect[1]<<endl;
    }

    return 0;    
} 
    