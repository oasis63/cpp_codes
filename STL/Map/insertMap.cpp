#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<int,int> m{{1,2} , {2,3} , {3,4} };
  
  m.insert( pair<int,int> (4,5));
  /* inserts a new entry of key = 4 and value = 5 in map m */
  
  /* make_pair() can also be used for creating a pair */
  m.insert( make_pair(5, 6));
  /* inserts a new entry of key = 5 and value = 6 */


  map::iterator i , j;
  i = m.find(2);    // points to entry having key =2
  j = m.find(5);    // points to entry having key =5

  map<int,int> new_m;
  
  new_m.insert(i,j);
   /* insert all the entries which are pointed 
     by iterator i to iterator j*/ 

  m.insert( make_pair(3,6));  
   // do not insert the pair as map m already contain key = 3 */ 
  
  m.insert_or_assign( make_pair(3,6));  // assign value = 6 to key =3   
}