#include <bits/stdc++.h>

#define li long int

using namespace std;

int main() {
   
    li n,d;cin>>n>>d; li a[n];
    for(li i=0;i<n;i++) cin>>a[i];
    
    li help[d] = {0};
    
    for(int i=0;i<d;i++)
        help[i] = a[i];
    
    for(int i=d;i<n;i++){
            a[i-d] = a[i];
    }
    
    int index=n-d;
    
    for(int i=0;i<d;i++){
        a[index]=help[i];
        index++;
    }
    
    for(li i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}

// time complexity is  O(n)   

