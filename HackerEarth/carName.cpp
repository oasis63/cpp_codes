#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while( t-- )   
	{
		string s;
		cin>>s;

		if( s.length()%3 == 0)
		{
            set<char> mySet;
    
            for(int i=0;i<s.length();i++)
            {
                char c = s[i];
                mySet.insert(c);
            }
            
            if( mySet.size() != 3)
            {
                cout<<"Not OK1"<<endl;
            }
            else
            {
                //cout<<"OK"<<endl;

            	int len[3] = {0};

            	int index = 0;

            	int get = 0;

            	cout<<"executed1"<<endl;

            	for(int i=0;i<s.length();i++)
            	{
            		len[index] = 1;

            		while(s[i] == s[i+1] && (i+1) < s.length())
            		{
            			len[index] ++;
            			i++;
            		}

            		index ++;

            		if( index > 3)
            		{
            			cout<<"Not OK"<<endl;
            			get=1;
            			break;
            		}

            		//cout<<"executed2"<<endl;
            	} 

            	if( get == 0)
            	{
            		int set = 1;

	            	int length = len[0];

	            	for(int i=0;i<3;i++)           	
	            	{
	            		if(len[i] != length)
	            			set = 0;

	            		cout<<len[i]<<" ";
	            	}

	            	if( set )
	            		cout<<"OK"<<endl;
	            	else
	            		cout<<"Not OK2"<<endl;

	            	cout<<"executed3"<<endl;
            	}


            }


		}
		else
		{
			cout<<"Not OK3"<<endl;
		}
	}

}