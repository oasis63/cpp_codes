#include <bits/stdc++.h>
using namespace std;

int main()
{

		cout<<"Enter the seat Number\n"<<endl;
		int seatNo;	
		cin>>seatNo;

		string side = "";

		if( seatNo%6 == 0 || seatNo%6 == 1)
		{
			side = "WS";
		}

		else if( seatNo%3 == 2)
		{
			side = "MS";
		}
		else
		{
			side = "AS";
		}


		if( seatNo%12 )
		{
			int ratio = seatNo / 12 ;
		    int prevEndSeat = 12*ratio; 

		    int posInCabin = seatNo - prevEndSeat;  // position in the cabin
	        int diff = 6 - posInCabin;
		    int add = diff + (diff + 1);   // number to be added to find the front Seat

			int frontSeat = seatNo + add;
			cout<<"Front Seat: "<<frontSeat<<"\n"<<"Side: "<<side<<endl;
		}

		else
		{
			cout<<"Front seat: "<<(seatNo - 11)<<"\n"<<"Side: "<<side<<endl;
		}


}

/**
*Select the compartment in which the seat lies;  seatNo. / 12
*the the previous end seat 
*find the position of the seat in the compartment  by subtracting 
	previous end seat from the current seat  i.e., seatNo. - preveEndSeat
*find the difference by subtracting the position value from 6 
* to find the number to be added , find sum of diff + (diff + 1)

*/


