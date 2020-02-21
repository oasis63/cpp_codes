#include <bits/stdc++.h>
using namespace std;

int main()
{
   char url[101];

   cin>>url;

   int len = strlen(url);

   url[len] = '&';

   char find[5][100] = { "username","pwd","profile","role","key"};

   for(int i=0;i<5;i++)
   {
      char *p = strstr(url,find[i]);

      char str[100];

      strcpy(str,find[i]);

       if( p )
       {    // cout<<"yes"<<endl;

          char dm[100];

          p = p + strlen(find[i]) + 1;

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
       
        //cout<<*p<<endl;

    //    p = p + 8 + 1;

        

   }

   
}

/*
    char dm[100];

    int i=0;

    while( *p != '=')
    {
        dm[i] = *p;
        i++;
        p++;
    }

    dm[i] = '\0';


    for(int i=0;i<5;i++)
      find[i];



*/