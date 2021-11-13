#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n=1000000;
    ll p[n+1],i,j;
    for(i=2;i<=n;i++)
    p[i]=1;
    
    p[0]=p[1]=0;
    
    for(i=2;i<=sqrt(n);i++)
    {
        for(j=i*i;j<=n;j+=i)
        {
            p[j]=0;
        }
    }

    for(i=2;i<=n;i++)
    {
        if(p[i]==1)
            p[i]=i;
    }

    ll tc,N,up,down;
    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld",&N);
        up=down=N;

        if(p[N])
            printf("%lld\n",p[N]);
        else
        {
            while(1)
            {
                down--;

                if(p[down])
                {
                    printf("%lld\n",p[down]);
                    break;
                }

                up++;
                
                if(p[up])
                {
                    printf("%lld\n",p[up]);
                    break;
                }
            }
        }
    }
    return 0;
}