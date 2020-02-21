#include<bits/stdc++.h>
using namespace std;

int main(){


	int na,nb;
	cin>>na>>nb;

	int A[na],B[nb];
    int k,m;
    cin>>k>>m;

    for(int i=0;i<na;i++){
		cin>>A[i];
    }
    for(int j=0;j<nb;j++){
		cin>>B[j];
    }

	/*cout<<"\nNumbers are : \t";
    cout<<A[k-1]<<"  "<<B[nb-m]<<endl;*/

    if(A[k-1] < B[nb-m])
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;

}
