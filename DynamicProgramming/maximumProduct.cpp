#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Maximum product of an  subsequence  .. not contiguous 

ll lis(ll arr[], ll n)
{
    ll mpis[n];


    for (int i = 0; i < n; i++)
        mpis[i] = arr[i];


    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i]))
                mpis[i] = mpis[j] * arr[i];



    return *max_element(mpis, mpis + n);
}

int main()
{
    ll arr[] = { 3, 100, 4, 5, 150, 6 };
    ll n = sizeof(arr) / sizeof(arr[0]);
    printf("%lld", lis(arr, n));
    return 0;
}
