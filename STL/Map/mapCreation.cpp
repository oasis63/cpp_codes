#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<int,int> m{ {1,2} , {2,3} , {3,4} };
  /* creates a map m with keys 1,2,3 and 
        their corresponding values 2,3,4 */  

  map<string,int> map1; 
  /*  creates a map with keys of type character and 
      values of type integer */

  map1["abc"]=100;    // inserts key = "abc" with value = 100
  map1["b"]=200;      // inserts key = "b" with value = 200
  map1["c"]=300;      // inserts key = "c" with value = 300
  map1["def"]=400;    // inserts key = "def" with value = 400

  map<char,int> map2 (map1.begin(), map1.end());
  /* creates a map map2 which have entries copied 
        from map1.begin() to map1.end() */ 

  map<char,int> map3 (m);
  /* creates map map3 which is a copy of map m */
}