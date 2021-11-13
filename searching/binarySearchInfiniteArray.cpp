//  binary search in sorted array of infinite numbers
#include<bits/stdc++.h>
using namespace std;

int binarySearchRec(int arr[],int low,int high,int key){

    if(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binarySearchRec(arr,low,mid-1,key);
        else
            return binarySearchRec(arr,mid+1,high,key);
    }
    return -1;
}


int findPos(int arr[],int key){

    int low = 0,high=1;
    int val = arr[high];

    while(val < key){
        low = high;
        high = high*2;
        val = arr[high];
    }

    return binarySearchRec(arr,low,high,key);
}


int main() {

    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,140, 160, 170};

    int ans = findPos(arr, 10);


    if (ans==-1)
        cout << "Element 10 not found"<<endl;
    else
        cout << "Element 10 found at index " << ans <<endl;


    ans = findPos(arr, 20);

    if (ans==-1)
        cout << "Element 20 not found"<<endl;
    else
        cout << "Element 20 found at index " << ans<<endl;


    return 0;
}
