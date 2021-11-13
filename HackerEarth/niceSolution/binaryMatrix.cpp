#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,n1,n2,k;
    
    char str[1000][1000];
    scanf("%d",&t);
    
    for(i=0;i<=t-1;i++)
    {
        int count=0;
        scanf("%d %d",&n1,&n2); 
        
        for(j=0;j<=n1-1;j++)
        {
            scanf("%s",str[j]);
            for(k=0;k<=j-1;k++)
            {
                if(strcmp(str[j],str[k])==0)
                {
                    count++;
                }
            }
        }
        
        if(count>0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    
}