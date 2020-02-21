#include <bits/stdc++.h>
using namespace std;

int main()
{
   char url[105];

   cin>>url;

   int len = strlen(url);

   url[len] = '&';

   char title[5][100] = { "username","pwd","profile","role","key"};

   for(int i=0;i<5;i++)
   {
	  char *p = strstr(url,title[i]);

	  char str[100];

	  strcpy(str,title[i]);


	  p = p + strlen(title[i]) + 1;

	  if( i < 4)       
	  {
		int j=0;

		char dm[100];

		while( *p != '&' || (p+1) != strstr(url,title[i+1]) )
		{
			dm[j] = *p;
			j++;
			p++;
		}

		dm[j] = '\0';

		cout<<str<<": "<<dm<<endl;


	  }
	  else
	  {
	  	 char dm[100];

	  	  int j=0;

	      while( *p != '&')
	      {
	          dm[j] = *p;
	          j++;
	          p++;
	      }

	      dm[j] = '\0';

	      cout<<str<<": "<<dm<<endl;


	  }

   }

   
}
