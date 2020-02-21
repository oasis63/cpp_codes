#include <bits/stdc++.h> 
using namespace std; 

//Maximum product of contiguos subsequence  subsequence 
  
int maxProduct(int* arr, int n) 
{ 
   
    int minVal = arr[0]; 
    int maxVal = arr[0]; 
  
    int maxProduct = arr[0]; 
  
    for (int i = 1; i < n; i++) { 
  
     
        if (arr[i] < 0) 
            swap(maxVal, minVal); 
   
        maxVal = max(arr[i], maxVal * arr[i]); 
        minVal = min(arr[i], minVal * arr[i]); 
   
        maxProduct = max(maxProduct, maxVal); 
    } 
  
    return maxProduct; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 2,0,-3,8,-4,-9}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Maximum Subarray product is "
         << maxProduct(arr, n) << endl; 
  
    return 0; 
} 