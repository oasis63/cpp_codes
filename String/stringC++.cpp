#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
 string s1,s;
 s1="hello";

 cout<<s1<<endl;

 s.assign("Assign");

 s1.append("World");

 s.insert(2,"insert");

 s.replace(2,3,"Rajesh");

 s1.erase();

 cout<<s1<<endl<<s<<endl;

 string s3 = "Never loose your hope";

 cout<<s3.find("loose")<<endl;

 string s4 = "Never loose loose your hope";

 cout<<s4.rfind("loose")<<endl;  // searches from end

 s3 = "amit";
 s4 = "raue";

 cout<<s3.compare(s4)<<endl;

 string s5 = "Hello";

 char str[20];

 strcpy(str,s5.c_str());

 cout<<str<<endl;



}