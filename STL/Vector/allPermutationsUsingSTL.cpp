// C++ program to display all permutations
// of an array using STL in C++

#include<bits/stdc++.h>
using namespace std;

void display(vector<int> v){
    int n = v.size();
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void permutations(vector<int> vect){

    sort(vect.begin(),vect.end());   // without sorting it gives error

    do{
        display(vect);
    }while(next_permutation(vect.begin(),vect.end()));


}

int main(){
    vector<int> vect{2,1,3};
    permutations(vect);

    return  0;
}
