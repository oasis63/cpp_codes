#include<bits/stdc++.h>
using namespace std;

/*  Segment Tree
    1) Minimum and Maximum value in a range
    2) Sum in a range
*/

void constructSegTree(int input[],int segTree[],int low,int high,int pos){

    if(low==high){
        segTree[pos] = input[low];
        return;
    }

    int mid = (low+high)/2;

    constructSegTree(input,segTree,low,mid,2*pos+1);  // left child
    constructSegTree(input,segTree,mid+1,high,2*pos+2);  // right child

    segTree[pos] = max(segTree[2*pos+1],segTree[2*pos+2]);  // taking the max elements
}

// maximum in a range

int maxRangeQuery(int segTree[],int qlow,int qhigh,int low,int high,int pos){

    if(qlow<=low && qhigh>=high){  // total overlap
        return segTree[pos];
    }

    if(qlow > high || qhigh < low)  // no overlap
        return INT_MIN;

    int mid = (low+high)/2;

    return max(maxRangeQuery(segTree,qlow,qhigh,low,mid,2*pos+1),maxRangeQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2));

}

int main(){
    int n;cin>>n;
    int input[n];
    double p = log2(n);
    p = ceil(p);

    int k = pow(2,p)*2-1;  // size of segment tree

    int segTree[k] = {INT_MIN};

    for(int i=0;i<n;i++)
        cin>>input[i];

    int count=0;

    constructSegTree(input,segTree,0,n-1,0);

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            if(input[i]*input[j] <= maxRangeQuery(segTree,i,j,0,n-1,0))
                count++;
        }
    }

    cout<<count<<endl;
}
