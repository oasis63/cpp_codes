#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int seatNo=1;
	cin>>n;

	while( seatNo <= n )
	{
		int  temp = seatNo;

		int key = temp%12;

		switch(key)
		{
			case 1:
				temp += 11;
				cout<<temp<<" "<<"WS"<<endl;
				break;
			case 2:
				temp += 9;
				cout<<temp<<" "<<"MS"<<endl;
				break;
			case 3:
				temp += 7;
				cout<<temp<<" "<<"AS"<<endl;
				break;
			case 4:
				temp += 5;
				cout<<temp<<" "<<"AS"<<endl;
				break;
			case 5:
				temp += 3;
				cout<<temp<<" "<<"MS"<<endl;
				break;
			case 6:
				temp += 1;
				cout<<temp<<" "<<"WS"<<endl;
				break;

			case 7:
				temp -= 1;
				cout<<temp<<" "<<"WS"<<endl;
				break;
			case 8:
				temp -= 3;
				cout<<temp<<" "<<"MS"<<endl;
				break;
			case 9:
				temp -= 5;
				cout<<temp<<" "<<"AS"<<endl;
				break;
			case 10:
				temp -= 7;
				cout<<temp<<" "<<"AS"<<endl;
				break;
			case 11:
				temp -= 9;
				cout<<temp<<" "<<"MS"<<endl;
				break;
			case 0:
				temp -= 11;
				cout<<temp<<" "<<"WS"<<endl;
				break;
			default:
				cout<<"\nSome problem is seating Plane\n";
				break;
		}


		seatNo ++;
	}
}
