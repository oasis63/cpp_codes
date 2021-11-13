#include <iostream>
using namespace std;
int count=0;

void merge(int a[], int start, int mid, int end)
{
	int p = start, q = mid+1, i,j;

	int arr[end-start+1], k=0;

	while(p<=mid && q<=end)
	{
		if(a[p]<=a[q])
			arr[k++] = a[p++];
		else
		{
			count++;
			arr[k++] = a[q++];
		}
	}

	while(p<=mid)
	{
		arr[k++] = a[p++];
		count++;
	}

	while(q<=end)
	 arr[k++] = a[q++];

		/*for(i=start; i<=end; i++)
		{
		if(p>mid)
		arr[k++] = a[q++];
		else if(q>end)
		arr[k++] = a[p++];
		else if(a[p] < a[q])
		arr[k++] = a[p++];
		else
		arr[k++] = a[q++];
		}*/

		for(i=start,j=0; i<=end; i++,j++)
			a[i] = arr[j];
	}

void mergeSort(int a[], int start, int end)
{
	int mid;

	if(start<end)
	{
		mid = (start+end)/2;
		mergeSort(a, start, mid);
		mergeSort(a, mid+1, end);
		merge(a, start, mid, end);
	}
}

int main()
{
	int i,j,n;
	cin >> n;
	int a[n];

	for(i=0; i<n; i++)
	cin >> a[i];

	//int start=0, end=n-1;
	mergeSort(a,0,n-1);

	cout << count;

	return 0;

}