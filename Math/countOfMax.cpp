#include<bits/stdc++.h>
using namespace std;

#define range 1000999
int countFact[range];

int factors(int n)
{
    int count =0;

    for(int i=1;i<=sqrt(n);i++)
    {
        if( n%i == 0)
        {
            if( n/i == i)
                count ++;
            else
                count += 2;
        }
    }

    return count;
}

void setCount(){

    countFact[0]=0;

   for(int i=1;i<=range;i++)
   {
        countFact[i] = factors(i);
   }

    //for(int i=0;i<=10000;i++)
      //      cout<<countFact[i]<<" ";


}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    setCount();
    priority_queue<int> pq;

    int t,a,b,temp;cin>>t;
    while(t--){
        cin>>a>>b;

        int mx=INT_MIN;

        int count=0;

        for(int i=a;i<=b;i++){
            temp=countFact[i];
            if(temp>mx){
                mx=temp;
                count=1;
            }
            else if(temp==mx)
                count++;
        }

        cout<<(++count)<<endl;


    }
}
