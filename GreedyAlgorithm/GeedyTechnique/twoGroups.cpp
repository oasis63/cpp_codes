#include<bits/stdc++.h>
using namespace std;

/*
Divide 1 to n into two groups with minimum sum difference
*/

void display(vector<int> vect){

    int len = vect.size();

    for(int i=0;i<len;i++){
        cout<<vect[i]<<" ";
    }

    cout<<endl;
}

// divide 1 to n into two groups so that difference of their sum is minimum
void solve(int n){

    cout<<"---: n =  "<<n<<" :----"<<endl;

    int total = (n*(n+1))/2;
    int sum1=total/2;

    vector<int> group1;
    vector<int> group2;

    for(int i=n;i>0;i--){

        if(sum1-i>=0){
            group1.push_back(i);
            sum1-=i;
        }else{
            group2.push_back(i);
        }

    }

    display(group1);
    display(group2);

}

int main(){

    int n=5;
    solve(n);

    cout<<endl;

    n=10;
    solve(n);

}
