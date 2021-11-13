#include<bits/stdc++.h>
using namespace std;
int main()
 {

	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];

	int tc;cin>>tc;
	int a,b;
	while(tc--){
	    cin>>a>>b;
	    int f=INT_MAX;
	    int s=INT_MAX;
	    for(int i=a;i<=b;i++){
	        if(arr[i] < f){
	            f=arr[i];
	        }
	    }

	     for(int i=a;i<=b;i++){
	        if(arr[i] < s && arr[i]!=f){
	            s=arr[i];
	        }
	    }

        if(s==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<s<<endl;

	}



	return 0;
}

/*
    Sample TestCases

4
1 2 2 4
2
1 2
0 1

*/
