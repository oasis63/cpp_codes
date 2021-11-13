#include<bits/stdc++.h>
using namespace std;

#define MX_LEN 100001

int funnySubArr(int arr[],int n){

    int ans = 0;
    int j;
            //pair<len,index>
    vector<pair<int,int>> vect;

    for(int i=0;i<MX_LEN;i++){
        vect.push_back(make_pair(0,0));
    }


    for(int i=0;i<n;i++){
        int prev_index = vect[arr[i]].second;
        int prev_len = vect[arr[i]].first;

        if(prev_len==0){

            vect[arr[i]].first = 1;   // len
            vect[arr[i]].second=i;   // index

        }else{

            int new_index = i;
            int new_len = prev_len + abs(new_index-prev_index);
            //vect.erase(vect.begin()+arr[i]);
            vect[arr[i]].first = new_len;
            vect[arr[i]].second = new_index;
            //vect.push_back(make_pair(new_len,new_index));
        }
    }


//    for(int i=0;i<10;i++){
//        cout<<vect[i].first<<" "<<vect[i].second<<" "<<i<<endl;
//    }

    int len;

    for(int i=0;i<MX_LEN;i++){
        len = vect[i].first;
        if(len > ans)
            ans = len;
    }



//    for(int i=0;i<n;i++){
//        for(j=n-1;j>i;j--){
//            if(arr[j]==arr[i])
//                break;
//        }
//
//        int temp = j-i+1;
//        if(temp > ans)
//            ans = temp;
//    }

    return ans;
}

int main(){

    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = funnySubArr(arr,n);

    cout<<ans<<endl;
}


/* Sample Test Case

9
2 2 3 1 2 2 3 1 1

*/
