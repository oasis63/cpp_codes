#include<bits/stdc++.h>
using namespace std;

void display(vector<int> vect){

    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

void permutations(vector<int> &vect,int l,int r){
	if(l==r){
		display(vect);
	}else{
		for(int i=l;i<=r;i++){
			swap(vect[l],vect[i]);
			permutations(vect,l+1,r);  // backtrack
			swap(vect[l],vect[i]);
		}
	}
}

int main(){

    vector<int> vect { 1,2,3};
    permutations(vect,0,vect.size()-1);

    return 0;
}
