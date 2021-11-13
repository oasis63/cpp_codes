#include <bits/stdc++.h>
using namespace std;


int main()
{
  int a[] = {1, 2, 3, 4, 5, 6};
  int *ptr = (int*)(&a+1);
  printf("%d ", *(ptr-1) );
  return 0;
}

/*

&a is address of the whole array a[ ] .
If we add 1 to &a, we get base address of a[ ] + sizeof(a).
And this value is typecasted to int *.
So ptr points the memory just after 6 is stored.
ptr is typecasted to "int *" and value of *(ptr-1) is printed.
Since ptr points to memory after 6, ptr-1 points to 6.

*/
