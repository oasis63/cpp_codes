#include <bits/stdc++.h>
using namespace std;
int main()
{
    double count=0;
    double expectedCodeSize=90;
    double maxAllowedSize = 100;
    double maxMarks = 100;
    char ch;
    while (scanf("%c",&ch)!=EOF)
        count++;    
    double score = 0.0;
    if (count <= expectedCodeSize)
        score = 100;
    else
    {
        maxAllowedSize /= 2;
        score = maxMarks * exp(-1*pow(((count-expectedCodeSize)/maxAllowedSize),2)/2);
    }
    cout<<score;    
    return 0;
}