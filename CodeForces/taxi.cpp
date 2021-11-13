#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,t;
    cin>>n;

    int hasCount[5] = {0};
    int groups[n];

    for(int i=0;i<n;i++){

        cin>>t;
        groups[i]=t;
        hasCount[t]++;
    }

    int vehicles = 0;

    sort(groups,groups+n);

    int tempSum = 0;
    bool found = true;

    for(int i=0;i<n;i++){

        int t1 = groups[i];

        if(found){

            tempSum = groups[i];
            found=false;

        }

        if( hasCount[t1] > 0 ){

            int t2 = 4 - t1;

            hasCount[t1]--;

            if( t2==0 ){   // this means t1 = 4

                vehicles++;
                found=true;
                tempSum=0;

            }else{

                if(hasCount[t2] > 0){

                    vehicles++;
                    hasCount[t2]--;

                    found=true;
                    tempSum=0;

                }else{

                     int j = t2;

                     while( tempSum <= 4 && j>= 0){

                            if(tempSum%4==0){
                                vehicles += tempSum/4;
                                tempSum=0;
                                found=true;
                                break;
                            }

                            if(hasCount[j] > 0  && (tempSum+j) <= 4){
                                tempSum += j;
                                hasCount[j]--;
                            }else{
                                j--;
                            }

                     }



                    if(!found){
                        vehicles++;
                        tempSum=0;
                        found=true;
                    }


                }

            }

        }

    }

    cout<<vehicles<<endl;
}
