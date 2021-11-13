#include<bits/stdc++.h>
using namespace std;

int main(){

    string input;
    cin>>input;

    transform(input.begin(), input.end(), input.begin(), ::toupper);

    cout<<input<<endl;


     transform(input.begin(), input.end(), input.begin(), ::tolower);

    cout<<input<<endl;

}
