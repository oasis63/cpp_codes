/*Name: Rajesh Raman Bosak
Scholar Id: 15-1-5-083
*/
// Quick_Sort
#include <stdio.h>
void swap(long int *a, long int *b)
{
   long int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}
void quicksort(long int a[], long int, long int);
long int partition(long int a[], long int, long int);

int main()
{
   long int i, n;
   printf("Enter the number of elements of the array:\n");
   scanf("%ld", &n);

   long int a[n];

   for (i = 0; i < n; i++)
      scanf("%ld", &a[i]);

   quicksort(a, 0, n - 1);

   for (i = 0; i < n; i++)
      printf("%d ", a[i]);

   return 0;
}

void quicksort(long int a[], long int beg, long int end)
{
   long int q;

   if (beg < end)
   {
      q = partition(a, beg, end);
      quicksort(a, beg, q - 1);
      quicksort(a, q + 1, end);
   }
}

long int partition(long int a[], long int beg, long int end){
   long int left, right, temp, loc, flag = 0;
   loc = left = beg;
   right = end;

   while (flag != 1){
      while (a[loc] <= a[right] && loc != right)
         right--;

      if (loc == right)
         flag = 1;
      else if (a[loc] > a[right]){
         swap(&a[loc], &a[right]);
         loc = right;
      }

      if (flag != 1){
         while (a[loc] >= a[left] && loc != left)
            left++;

         if (loc == left)
            flag == 1;
         else if (a[loc] < a[left]){
            swap(&a[loc], &a[left]);
            loc = left;
         }
      }
   }
   return loc;
}
