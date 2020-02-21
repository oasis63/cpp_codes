// erasing from set
#include <bits/stdc++.h>
using namespace std;

int main ()
{
  set<int> myset;
  set<int>::iterator it;

  // insert some values:
  for (int i=1; i<10; i++)
  	myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

  it = myset.begin();
  ++it;                                         // "it" points now to 20

  myset.erase (it);

  myset.erase (40);

  it = myset.find (60);
  myset.erase (it, myset.end());

  cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
/*
set erases its elements by using the element's address or the value of the element to be deleted */
