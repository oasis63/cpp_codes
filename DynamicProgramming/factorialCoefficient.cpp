#include<bits/stdc++.h>
using namespace std;

int factorialCoeff(int n, int k)
{
    int P[n+1][k+1];
    int i, j;

    for (i = 0; i <= n; i++){

        for (j = 0; j <= min(i, k); j++){

            if (j == 0 )
                P[i][j] = 1;
            else
                P[i][j] = P[i-1][j] + j*P[i-1][j-1];

            P[i][j+1] = 0;
        }
    }

    return P[n][k];
}


int main()
{
    int n = 5, k = 2;
    cout<<n<<"P"<<k<<" : "<<factorialCoeff(n,k)<<endl;
    return 0;
}
