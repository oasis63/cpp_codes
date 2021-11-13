#include<bits/stdc++.h>
using namespace std;

// Maximum train for which stoppage can be provided

int maxStop(vector<int> arr[],int n){


    vector<pair<int,int>> vect[n+1];   // platform vise stoppage for trains


    for(int i=0;i<n;i++){
       vect[arr[i][2]].push_back(make_pair(arr[i][1],arr[i][0]));  // departure time, arrival time
    }


    // sorting in ascending order of their departure time
    for(int i=0;i<n;i++){
        sort(vect[i].begin(),vect[i].end());
    }


    cout<<"\n Departure and Arrival times of trains in each platform "<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j].first<<" "<<vect[i][j].second<<" ";
        }
        cout<<endl;
    }


    int count=0;
    int prevDept = -1;
    int currentArrival = -1;

    for(int i=0;i<=n;i++){
        for(int j=0;j<vect[i].size();j++){
            if(count == 0){
                count++;
                prevDept=vect[i][j].first;
            }else{

                currentArrival = vect[i][j].second;

                if(currentArrival > prevDept ){
                    prevDept = vect[i][j].first;
                    count++;
                }

            }
        }
    }





    return count;
}




// driver function
int main(){
    vector<int> arr[] = {{ 1000, 1030, 1}
                      ,{1010, 1020, 1},
                      {1025, 1040, 1},
                      {1130, 1145, 2},
                      {1130, 1140, 2 }};
    cout << "Maximum Stopped Trains = "<< maxStop(arr,5)<<endl;
    return 0;
}
