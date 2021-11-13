#include <bits/stdc++.h>
using namespace std;

int main()
{
   char s1[100];

   cin>>s1;

   cout<<strlen(s1)<<endl;

   char find[50];

   cout<<"Enter a string to find in the string"<<endl;
   cin>>find;

   char *p = strstr(s1,find);

   if( p )
        cout<<"yes"<<endl;
   else
        cout<<"No"<<endl;
   
    cout<<*p<<endl;

    p = p + 8 + 1;

    char dm[100];

    int i=0;

    while( *p != '&')
    {
        dm[i] = *p;
        i++;
        p++;
    }

    dm[i] = '\0';

    cout<<dm<<endl;



   
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



*/