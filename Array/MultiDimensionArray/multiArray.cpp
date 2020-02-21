#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10][20][30] = {0};
    a[5][2][1] = 2;
    printf("%d",*(*(*(a+5)+2)+1));


    cout<<"\n--- 1D array ----"<<endl;

    int b[4] = {0};
    b[3] = 3;

    cout<<*(b+3)<<endl;

    return 0;
}
