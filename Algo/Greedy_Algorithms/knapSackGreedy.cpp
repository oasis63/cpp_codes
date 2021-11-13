// Greedy Algorithm For knap sack
// Greedy Approach for maximum profit
#include<bits/stdc++.h>
using namespace std;


void merge(pair<double,int> arr[],int beg,int mid,int end){
    int i=beg,j=mid+1;
    pair<double,int> temp[100];
    int index=0;

    while(i<=mid && j<=end){

        if(arr[i].first > arr[j].first){
            temp[index] = arr[i];
            i++;
        }else{
            temp[index]=arr[j];
            j++;
        }

        index++;
    }

    if(i>mid){
        while(j<=end){
            temp[index]=arr[j];
            j++;
            index++;
        }
    }else{
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }

    j=beg;

    for(int i=0;i<index;i++){
        arr[j]=temp[i];
        j++;
    }

}


void mergeSort(pair<double,int> arr[],int beg,int end){
    int mid;

    if(beg<end){
        mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }


}



// driver method

int main(){

    int maxWeight;
    cout<<"Enter the maximum Weight of the Sack"<<endl;
    cin>>maxWeight;

    int numObj;
    cout<<"Enter the number of objects"<<endl;
    cin>>numObj;

    int profit[numObj];
    int weight[numObj];

    cout<<"Enter the profits and the weights  of the objects"<<endl;
    for(int i=0;i<numObj;i++){
        cin>>profit[i];
        cin>>weight[i];
    }

    // Greedy Approach for maximum profit
    //double profitRatio[numObj];  // ratio of profit and weight
    // calculating the average weight of an object of each type

    pair<double,int>ratioPair[numObj];  // contains both the object number and the ratio of profit type


    for(int i=0;i<numObj;i++){
        //profitRatio[i] = profit[i]/(double)weight[i];
        ratioPair[i] = make_pair(profit[i]/(double)weight[i],i);

    }

    // sorting objects according to their profits in decreasing order


//    for(int i=0;i<(numObj-1);i++){
//        for(int j=0;j<(numObj-i-1);j++){
//            if(ratioPair[j].first < ratioPair[j+1].first){
//                pair<double,int>temp = ratioPair[j];
//                ratioPair[j]=ratioPair[j+1];
//                ratioPair[j+1] = temp;
//
//            }
//        }
//    }

    // shorting the elements in the decreasing order

    mergeSort(ratioPair,0,numObj-1);

    // ratio pair after sorting the ratioPair<double,int>

    for(int i=0;i<numObj;i++){
        cout<<ratioPair[i].first<<" "<<ratioPair[i].second<<endl;
    }

    cout<<endl;

    double  profitMoney = 0;

    int i;

    for(i=0;i<numObj;i++){
        if(maxWeight>0 && weight[ratioPair[i].second] <= maxWeight){
                maxWeight = maxWeight - weight[ratioPair[i].second];
                profitMoney = profitMoney + profit[ratioPair[i].second];
        }
        else
            break;
    }

    if(maxWeight > 0){
        profitMoney = profitMoney +  (profit[ratioPair[i].second]*maxWeight)/(double)weight[ratioPair[i].second];
    }


    cout<<"\n--Maximum Profit Earned is " << profitMoney<<endl;

}
