#include<iostream>
using namespace std;

int firstIndex(int input[],int n,int x){

    int ans = 0;
    if(n==0)
        return -1;
    if(input[0] == x)
        return  0;
    else{
        ans = firstIndex(input+1,n-1,x);
        if(ans == -1)
            return ans;
        else
            return ans+1;
    }
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << firstIndex(input, n, x) << endl;

}

/*

4
9 8 10 8
8

4
9 8 10 8
10

*/




