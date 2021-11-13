#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<int,string> m{ {1,”nikhilesh”} , {2,”shrikant”} , {3,”ashish”} };

  
  cout << m.at(1) ;  // prints value associated with key 1 ,i.e nikhilesh
  cout << m.at(2) ;  // prints value associated with key 2 ,i.e shrikant
  
  /* note that the parameters in the above at() are the keys not the index */

  cout << m[3] ; // prints value associated with key 3 , i.e ashish

  

  m.at(1) = "vikas";   // changes the value associated with key 1 to “vikas”
  m[2] = "navneet";   // changes the value associated with key 2 to “navneet”

  m[4] = "doodrah";   
  /* since there is no key with value 4 in the map, 
        it insert a key-value pair in map with key=4 and value = “doodrah” */
  
  m.at(5) = "umeshwa"; 
  /* since there is no key with value 5 in the map , 
     it throws an exception  */  
}