/* memset example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  memset (str,'-',2);
  puts (str);
  return 0;
}

/* memset() is used to set some value to the specified array */
