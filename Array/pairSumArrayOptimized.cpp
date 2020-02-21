#include<bits/stdc++.h>
using namespace std;

void hasPairSum(int arr[],int n,int sum){

    bool found = false;
    
    std::set<int> visited;

    for(int i=0;i<n;i++){
        int temp = sum-arr[i];
        if(visited.find(temp) != visited.end()){    // set find   method 
            found=true;
            break;
        }
        visited.insert(arr[i]);
    }


    if(found)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}

int main(){
    
    // input numbers can be sorted or unsorted 
    
    int arr[] = {1,2,3,9};
    int arr2[] = {1,2,4,4};
    int sum = 8;
    int n=4;


    hasPairSum(arr,n,sum);
    hasPairSum(arr2,n,sum);
    return 0;
}