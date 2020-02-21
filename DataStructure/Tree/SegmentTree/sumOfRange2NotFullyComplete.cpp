#include<bits/stdc++.h>
using namespace std;

/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.

    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range */

int getSum(int *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment


    if (qs <= ss && qe >= se)
        return st[si];

    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;

    // If a part of this segment overlaps with the given range
    int mid = (ss+se)/2;
    return getSum(st, ss, mid, qs, qe, 2*si+1) +
           getSum(st, mid+1, se, qs, qe, 2*si+2);
}

//int getSum(int *st, int n, int qs, int qe)
//{
//    // Check for erroneous input values
//    if (qs < 0 || qe > n-1 || qs > qe)
//    {
//        printf("Invalid Input");
//        return -1;
//    }
//
//    return getSumUtil(st, 0, n-1, qs, qe, 0);
//}


void constructSegTree(int input[],int segTree[],int low,int high,int pos)
{

    if (low == high)
    {
        segTree[pos] = input[low];
        return;
    }

    int mid = (low+high)/2;

    constructSegTree(input,segTree,low,mid,2*pos+1);  // left child
    constructSegTree(input,segTree,mid+1,high,2*pos+2);  // right child

    segTree[pos] = segTree[2*pos+1]+segTree[2*pos+2];  // taking the sum of left and right  children
}



int main()
{
        int n=6;

        int input[] =  {1, 3, 5, 7, 9, 11};


        // Build segment tree from given array

        double p = log2(n);
        p = ceil(p);

        int k = pow(2,p)*2-1;  // size of segment tree

        int segTree[k] = {INT_MIN};

        constructSegTree(input,segTree,0,n-1,0);

        // Print sum of values in array from index 1 to 3

        cout<<getSum(segTree,0,n-1,1,3,0)<<endl;
        cout<<getSum(segTree,0,n-1,8,10,0)<<endl;

        int get=0;

        int x=50;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(getSum(segTree,0,n-1,i,j,0)==x){
                    cout<<"YES"<<endl;
                    get=1;
                    break;
                }
            }

            if(get)
                break;
        }

        if(get==0)
            cout<<"NO"<<endl;





    return 0;
}
