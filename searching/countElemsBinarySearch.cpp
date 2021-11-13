#include<bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &A, int B,bool firstSearch) {
    
    int n = A.size();
    int beg = 0,end = n-1,mid;
    int result = -1;
    while(beg<=end){
        mid = (beg+end)/2;
        if(A[mid] == B){
            result = mid;
            if(firstSearch){
                end = mid-1;
            }else{
                beg = mid + 1;
            }

        }else if(B > A[mid]){
            beg = mid+1;
        }else{
            end = mid-1;
        }
    }

    return result;
}

int findCount(const vector<int> &A, int B) {

    bool firstSearch = true;
   int firstOccurrence = binarySearch(A,B,firstSearch);
    firstSearch = false;
   int lastOccurrence = binarySearch(A,B,firstSearch);

   if(firstOccurrence == -1 || lastOccurrence == -1)
    return lastOccurrence-firstOccurrence;

   return lastOccurrence-firstOccurrence+1;
}



int main(){
    
    vector<int> vect{5,7,7,8,8,10};
    //cout<<vect.size()<<endl;

    cout<<findCount(vect,7)<<endl;

    return 0;
}