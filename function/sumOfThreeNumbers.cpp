#include <iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	
	int a[n];
	
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int sum;
	cout<<"Enter the sum of the numbers"<<endl;
	cin>>sum;
	
	int num1=0,num2=0,num3=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				int temp = a[i] + a[j] + a[k];
				
				if( temp == sum)
				{
					num1 = a[i];
					num2 = a[j];
					num3 = a[k];
				}
			}
		}
	}
	
	cout<<endl;
	cout<<num1<<endl;
	cout<<num2<<endl;
	cout<<num3<<endl;
	
}


