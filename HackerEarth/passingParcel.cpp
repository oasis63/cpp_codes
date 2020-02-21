#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string song;
	cin>>n;
	cin>>song;

	vector<int> v;

	for(int i=0;i<n;i++)
	{
		v.push_back(i+1);
	}



	int index = 0;

//	cout<<"Size=:"<<v.size()<<endl;

	while( v.size() != 1)
	{

		for(int i=0;i<song.length();i++)
		{
			if( song[i] == 'a')
			{
				if( v.size() == 1)
				{
					break;
				}

				index = (index + 1)%n;


				//cout<<"SizeA=:"<<v.size()<<endl;
			}
			else if( song[i] == 'b')
			{
				if( v.size() == 1)
				{
				    break;
				}

				v.erase(v.begin()+index);

			//	cout<<"SizeB=:"<<v.size()<<endl;
                n--;
			}
		}

	}

	cout<<v[0]<<endl;


}
