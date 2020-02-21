#include<iostream>
using namespace std;


int sum = 0,rem;

int recFunc(int n){

    if(n){
        rem = n%10;
        sum=sum*10+rem;
        recFunc(n/10);
    }else{
        return sum;
    }

    return sum;
}


int main()
 {
	int tc;cin>>tc;
	while(tc-- > 0){
	    int n;cin>>n;
	    sum=0;
	    cout<<recFunc(n);
	    cout<<endl;
	}
	return 0;
}
