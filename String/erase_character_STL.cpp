#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long

int main(){
    
    string str = "chemical";

    str.erase(str.begin());

    cout<<"After erasing the first element : "<<str<<endl;

    // str.erase(str.begin()+str.length()-1);

    // give the index of the char to be delete

    str.erase(str.length()-1);

    cout<<str<<endl;

    return 0;
}