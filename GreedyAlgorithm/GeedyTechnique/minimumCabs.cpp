#include <bits/stdc++.h>
using namespace std;

/*
    Minimum Number of Platforms Required for a Railway/Bus Station
*/

void print(int arr[],int n){

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

int findPlatform(int arr[],int dep[],int n){

    sort(arr,arr+n);
    sort(dep,dep+n);


   // print(arr,n);
  //  print(dep,n);

    int ans=0;
    int platform_needed=0;

    int i=0;
    int j=0;


    while(i<n && j<n){

        if(arr[i] <= dep[j]){

          //  cout<<"Arrival Time : "<< arr[i]<<" "<<endl;

            platform_needed++;
            i++;

            if(platform_needed > ans)
                ans = platform_needed;

        }else if( arr[i] > dep[j]){
            
         //   cout<<"Departure Time : "<< dep[j]<<" "<<endl;

            platform_needed--;
             if(platform_needed > ans)
                ans = platform_needed;
            j++;

        }
    }


   // cout<<i<<endl;
    //cout<<j<<endl;

    return ans; 

}


int main(){
    
    /*int arr[] = {100, 1600, 930, 2130,2130, 1200};
    int dep[] = {200, 2130, 1300, 2230,2230, 1230};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n);
*/    
    int n;cin>>n;
    int arr[n];
    int dep[n];
    
    int a,b,c,d;
    int arrival;
    int departure;
    
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cin>>c>>d;
        
        arrival = a*100+b;
        departure = c*100+d;
        
        arr[i] = arrival;
        dep[i] = departure;
        
    }
    
    
    cout<<findPlatform(arr, dep, n)<<endl;
    
    return 0;
}