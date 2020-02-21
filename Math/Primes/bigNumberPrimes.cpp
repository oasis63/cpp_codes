#include <bits/stdc++.h> 
using namespace std; 

#define ll unsigned long long

void simpleSieve(ll limit, vector<ll> &prime) 
{ 
    bool mark[limit+1]; 
    memset(mark, true, sizeof(mark)); 
  
    for (ll p=2; p*p<limit; p++) 
    {  
        if (mark[p] == true) 
        { 
            for (ll i=p*2; i<limit; i+=p) 
                mark[i] = false; 
        } 
    } 
  
    for (ll p=2; p<limit; p++) 
    { 
        if (mark[p] == true) 
        { 
            prime.push_back(p); 
            cout << p << " "; 
        } 
    } 
} 
  
// Prlls all prime numbers smaller than 'n' 
void segmentedSieve(ll n) 
{ 

    ll limit = floor(sqrt(n))+1; 
    vector<ll> prime;  
    simpleSieve(limit, prime);  
  

    ll low = limit; 
    ll high = 2*limit; 
  
    while (low < n) 
    { 
        if (high >= n)  
           high = n; 
          
        // To mark primes in current range. A value in mark[i] 
        // will finally be false if 'i-low' is Not a prime, 
        // else true. 
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
  
        // Use the found primes by simpleSieve() to find 
        // primes in current range 
        for (ll i = 0; i < prime.size(); i++) 
        { 
            // Find the minimum number in [low..high] that is 
            // a multiple of prime[i] (divisible by prime[i]) 
            // For example, if low is 31 and prime[i] is 3, 
            // we start with 33. 
            ll loLim = floor(low/prime[i]) * prime[i]; 
            if (loLim < low) 
                loLim += prime[i]; 
  
            /* Mark multiples of prime[i] in [low..high]: 
                We are marking j - low for j, i.e. each number 
                in range [low, high] is mapped to [0, high-low] 
                so if range is [50, 100] marking 50 corresponds 
                to marking 0, marking 51 corresponds to 1 and 
                so on. In this way we need to allocate space only 
                for range */
            for (ll j=loLim; j<high; j+=prime[i]) 
                mark[j-low] = false; 
        } 
  
        // Numbers which are not marked as false are prime 
        for (ll i = low; i<high; i++) 
            if (mark[i - low] == true) 
                cout << i << " "; 
  
        // Update low and high for next segment 
        low = low + limit; 
        high = high + limit; 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    ll n = 1000000001; 
    segmentedSieve(n); 


    return 0; 
} 