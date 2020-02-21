// A Stack based C++ program to find next
// greater element for all array elements.
#include<bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
   elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    stack<int> s;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i=1; i<n; i++)
    {
        int next = arr[i];

        if (s.empty() == false)
        {
            // if stack is not empty, then
            // pop an element from stack
            int element = s.top();
            s.pop();

            /* If the popped element is smaller
               than next, then
               a) print the pair
               b) keep popping while elements are
               smaller and stack is not empty */
            while (element < next)
            {
                cout << element << " --> " << next
                     << endl;
                if (s.empty() == true)
                   break;
                element = s.top();
                s.pop();
            }

            /* If element is greater than next,
               then push the element back */
            if (element > next)
                s.push(element);
        }

        /* push next to stack so that we can find
           next greater for it */
        s.push(next);
    }

    /* After iterating over the loop, the remaining
       elements in stack do not have the next greater
       element, so print -1 for them */
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}
