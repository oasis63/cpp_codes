#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }

    int q,t;
    cin>>q;
    while(q--){
        cin>>t;

        if(t<=arr[0]){
            cout<<1<<endl;
        }else{

            int last = n-1;
            int first = 0;
            int mid;

            while(first<=last){
                mid = (last + first)/2;

                if(arr[mid]==t){
                    cout<<(mid+1)<<endl;
                    break;
                }else if(t > arr[mid]){
                    /*if((mid+1) < n && t<= arr[mid+1]){
                        cout<<"\t f3 \t"<<(mid+1)<<endl;
                        break;
                    }else{*/
                        first = mid + 1;
                    //}
                }else if(t<arr[mid]){
                    if((mid-1)>=0 && t>arr[mid-1]){
                        cout<<(mid+1)<<endl;
                        break;
                    }else{
                        last = mid - 1;
                    }
                }

            }
        }

    }

}
