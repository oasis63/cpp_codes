#include<bits/stdc++.h>
using namespace std;

// spiral sort of the given matrix

int printArray(int a[],int n){

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int sz;cin>>sz;
    int tempArr[sz*sz];
    int a[sz][sz];


    for(int id=0;id<sz;id++){
        for(int jd=0;jd<sz;jd++){
            cin>>a[id][jd];
            tempArr[id*sz+jd] = a[id][jd];
        }
    }

    //printArray(tempArr,n*n);

    sort(tempArr,tempArr+sz*sz);

    int idx=0;

    int i, k = 0, l = 0;

    int m = sz;
    int n=sz;

    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            //printf("%d ", a[k][i]);
            a[k][i] = tempArr[idx];
            idx++;
            //cout<<tempArr[idx]<<" ";

        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            //printf("%d ", a[i][n-1]);
            a[i][n-1] = tempArr[idx];
            idx++;
        }
        n--;

        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                //printf("%d ", a[m-1][i]);
                a[m-1][i] = tempArr[idx];
                idx++;
            }
            m--;
        }

        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                //printf("%d ", a[i][l]);
                a[i][l] = tempArr[idx];
                idx++;
            }
            l++;
        }
    }


    for(int id=0;id<sz;id++){
        for(int jd=0;jd<sz;jd++){
            cout<<a[id][jd]<<" ";
        }
        cout<<endl;
    }



}
