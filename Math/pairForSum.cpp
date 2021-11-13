    #include <iostream>
using namespace std;

// any pair(i,j) having sum as given number X.

bool pairExist(int A[],int n,int sum) {
    int l = 0, r = n - 1; //two pointers
    while ( l < r ) {
       if ( A[l] + A[r] == sum )
        return 1;
       else if ( A[l] + A[r] > sum )
            r--;
       else
        l++;
    }
    return 0;
}


int main()
{
    int arr[] = {1,3,4,5,6};

    int n = 5;
    int sum = 8;

    if(pairExist(arr,n,sum)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
