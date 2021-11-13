#include<bits/stdc++.h>
using namespace std;


void merge2(int counts[],string words[],int beg,int mid,int end){

    int i=beg,j=mid+1;
    int temp[end-beg+1];
    string tempStr[end-beg+1];
    int index=0;


    while(i<=mid && j<=end){
        if(counts[i] < counts[j]){
            temp[index] = counts[i];
            tempStr[index] = words[i];
            i++;
        }else{

            if(counts[i] == counts[j]){
                if(words[i] < words[j]){
                    temp[index]=counts[i];
                    tempStr[index] = words[i];
                    i++;
                }else{
                    tempStr[index] = words[j];
                    temp[index]=counts[j];
                    j++;
                }
            }else{
                temp[index]=counts[j];
                tempStr[index] = words[j];
                j++;
            }
        }
        index++;
    }

    while(i<=mid){
        temp[index] =  counts[i];
         tempStr[index] = words[i];
        i++;
        index++;

    }

    while(j<=mid){
        temp[index] =  counts[j];
         tempStr[index] = words[j];
        j++;
        index++;
    }


    for(i=0;i<index;i++){
        counts[beg] = temp[i];
        words[beg] = tempStr[i];
        beg++;
    }


}




void mergeSort2(string words[],int counts[],int beg,int end){
    int mid;
    if(beg<end){
        mid = (beg+end)/2;
        mergeSort2(words,counts,beg,mid);
        mergeSort2(words,counts,mid+1,end);
        merge2(counts,words,beg,mid,end);
    }


}


void printArr(int counts[],string word[],int n){

    for(int i=0;i<n;i++)
        cout<<counts[i]<<" "<<word[i]<<endl;

    cout<<endl;
}

int main(){

  int tc;cin>>tc;
  while(tc--){
      int n;cin>>n;
      string arr[n];
      for(int i=0;i<n;i++)
        cin>>arr[i];


      map<string,int> mp;

      for(int i=0;i<n;i++){
        if(!mp[arr[i]]){
            mp[arr[i]] = 1;
        }else{
            mp[arr[i]] = mp[arr[i]] + 1;
        }
      }

      map<string,int>::iterator itr = mp.begin();

        int m = mp.size();

      string words[m];
      int counts[m];

     int index=0;

      while(itr!=mp.end()){
       // cout<<itr->first<<" "<<itr->second<<endl;
        words[index] = itr->first;
        counts[index]= itr->second;
        index++;
        itr++;
      }

      mergeSort2(words,counts,0,m-1);
      printArr(counts,words,m);

  }

}


/*

Sample Input #1


1
10
abcd
bcd
abc
abc
abc
bcd
bge
dbaa
bcd
bge



Sample Output  #1

1 abcd
1 dbaa
2 bge
3 abc
3 bcd


*/

