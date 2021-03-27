#include<bits/stdc++.h>
using namespace std;

void segragate012(int);

void segragate012(int a[], int n){

    int low = 0, high = n-1, mid = 0;

    while(mid <= high){
        if(a[mid]==0)
            swap(a[mid++], a[low++]);
        else if(a[mid]==1)
             mid++;
        else
            swap(a[mid], a[high--]);
    }    
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        segragate012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }

}
