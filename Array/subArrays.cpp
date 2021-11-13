#include <bits/stdc++.h>
using namespace std;


void printSubArray(int arr[], int n)
{
 
 for (int i=0; i <n; i++) //select the starting element
 {
 
    for (int j=i; j<n; j++)   //select the ending element
    {
        for (int k=i; k<=j; k++)
 
        {
            cout << arr[k] << " "; //print all elements between start and end element.
        }
        
        cout << endl;
    }
  }
}

int main()
{
   int a[] = { 1,3,2,4};

   printSubArray(a,4);
}