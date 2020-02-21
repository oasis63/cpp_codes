#include<bits/stdc++.h>
using namespace std;

int castleStones(int cap,int a[],int n){
        int m  = cap;
        sort(a,a+n);
    	int j=0;
    	int k=n-1;
    	int ans = 0;

    	while(j!=k+1)
    	{
    		if(j==k)
    		{
    			ans++;
    			k--;
    		}
    		else if(a[k]>m)
    		k--;
    		else if(a[j]+a[k]<=m)
    		{
    			j++;
    			k--;
    			ans++;
    		}
    		else
    		{
    			k--;
    			ans++;
    		}
    	}

    	if(j==n-1)
    	ans++;


    return ans;

}

int main(){

   int cap = 95;
   int stones[] = {66,12,83,10};
   int n = 4;

    cout<<castleStones(cap,stones,n)<<endl;
}
