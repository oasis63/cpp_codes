#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int money = 20;
	int price = 3;
	int wrap = 5;
	int choco = 0;

	choco = money/price;
	int ans = choco;

	int wrappers = choco;


	while(1){
		choco = wrappers/wrap;
		ans += choco;
		// after eating ,,, we will be having 
		// wrappers of chocolates
		wrappers = wrappers%wrap + choco;

		if(wrappers < wrap)
			break;
	}

	cout<<ans<<endl;

}