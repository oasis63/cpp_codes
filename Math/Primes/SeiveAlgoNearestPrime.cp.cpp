#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

// array to store all primes less than 10^6
vector<int> primes;

// Utility function of Sieve of Sundaram
void Sieve()
{
    int n = MAX;

    // In general Sieve of Sundaram, produces primes
    // smaller than (2*x + 2) for a number given
    // number x
    int nNew = sqrt(n);

    // This array is used to separate numbers of the
    // form i+j+2ij from others where  1 <= i <= j
    int marked[n/2+500] = {0};

    // eliminate indexes which does not produce primes
    for (int i=1; i<=(nNew-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=n/2; j=j+2*i+1)
            marked[j] = 1;

    // Since 2 is a prime number
    primes.push_back(2);

    // Remaining primes are of the form 2*i + 1 such
    // that marked[i] is false.
    for (int i=1; i<=n/2; i++)
        if (marked[i] == 0)
            primes.push_back(2*i + 1);
}

// modified binary search to find nearest prime less than N
int binarySearch(int left,int right,int n)
{
    if (left<=right)
    {
        int mid = (left + right)/2;

        // base condition is, if we are reaching at left
        // corner or right corner of primes[] array then
        // return that corner element because before or
        // after that we don't have any prime number in
        // primes array
        if (mid == 0 || mid == primes.size()-1)
            return primes[mid];

        // now if n is itself a prime so it will be present
        // in primes array and here we have to find nearest
        // prime less than n so we will return primes[mid-1]
        if (primes[mid] == n)
            return primes[mid-1];

        // now if primes[mid]<n and primes[mid+1]>n that
        // mean we reached at nearest prime
        if (primes[mid] < n && primes[mid+1] > n)
            return primes[mid];
        if (n < primes[mid])
            return binarySearch(left, mid-1, n);
        else
            return binarySearch(mid+1, right, n);
    }
    return 0;
}

// Driver program to run the case
int main()
{
    Sieve();
    int n,t;
    scanf("%d",&n);

    t= binarySearch(0, primes.size()-1, n);

    cout<<"Nearest Prime less than n "<<endl;
    cout<<t<<endl;
    return 0;
}
