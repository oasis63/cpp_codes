#include <iostream>
using namespace std;

void findCombinationsUtil(int arr[], int index,int num, int reducedNum)
{

    if (reducedNum < 0)
        return;
    if (reducedNum == 0)
    {
        for (int i = 0; i < index; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    int prev = (index == 0)? 1 : arr[index-1];

    for (int k = prev; k <= num ; k++)
    {
        arr[index] = k;
        findCombinationsUtil(arr, index + 1, num,reducedNum - k);
    }
}

void findCombinations(int n)
{

    int arr[n];
    findCombinationsUtil(arr, 0, n, n);
}

// Driver code
int main()
{
    int n = 3;
    findCombinations(n);
    return 0;
}
