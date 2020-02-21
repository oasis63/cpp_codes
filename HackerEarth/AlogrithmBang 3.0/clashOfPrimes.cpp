// Program to print all prime factors
# include <bits/stdc++.h>
using namespace std;

set<int> primeFactors(int n)
{
    set<int> v;

    while (n%2 == 0)
    {
        //printf("%d ", 2);
        v.insert(2);
        n = n/2;
    }


    for (int i = 3; i <= sqrt(n); i = i+2)
    {

        while (n%i == 0)
        {
            //printf("%d ", i);
            v.insert(i);
            n = n/i;
        }
    }
    if (n > 2){
       // printf ("%d ", n);
        v.insert(n);
    }

    return v;
}

void displayArr(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void solve(int n){


    set<int> vf;

   vf =  primeFactors(n);

   set<int>::iterator itr = vf.begin();

   int factors[100];

   int lenth=0;

    while( itr != vf.end())
    {
       // cout<<*itr<<" ";
        factors[lenth] = *itr;
        itr ++;
        lenth++;
    }


    int ans = INT_MAX;

    //sort(factors,factors+lenth);

    //displayArr(factors,lenth);

    for(int i=0;i<lenth;i++){
        for(int j=i+1;j<lenth;j++){
            int temp = factors[j]-factors[i];
            if(temp < ans){
                ans = temp;
            }
        }
    }

    if(ans==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
}

/* Driver program to test above function */
int main()
{
    int tc,n;
    cin>>tc;
    while(tc--){
        cin>>n;
        solve(n);
    }
}
