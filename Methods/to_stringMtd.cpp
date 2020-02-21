#include<bits/stdc++.h>
using namespace std;

void subarray(int arr[],int n){

    vector<string> vect;

    for(int i=0;i<n;i++){

        string sub1 = to_string(arr[i]);
        //cout<<"--------"<<sub1<<endl;
        vect.push_back(sub1);

        for(int j=i+1;j<n;j++){
           // cout<<arr[j]<<" "<<endl;
           sub1 += " " + to_string(arr[j]);
            string temp = to_string(arr[j])+" " + to_string(arr[i]);
            //cout<<"--------"<<temp<<endl;
            vect.push_back(temp);
        }
    }


    int len = vect.size();
    for(int i=0;i<len;i++){
        cout<<vect[i]<<endl;
    }
    cout<<endl;

}

int main(){

    int arr[] = {1,2,3,4};

    int n = sizeof(arr)/sizeof(arr[0]);

    subarray(arr,n);

    return 0;
}
