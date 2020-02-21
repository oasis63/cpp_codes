#include <bits/stdc++.h>

using namespace std;

bool checkPrime(int n){

    if(n==0 || n==1){
        return false;
    }else if(n==2){
        return true;
    }

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
}


int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(checkPrime(n)){
            cout<<"Prime"<<endl;
        }else{
            cout<<"Not prime"<<endl;
        }
    }

    return 0;
}
