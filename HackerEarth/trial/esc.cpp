#include <stdio.h>

int main()
{
	char a[1440];
	int n,i,j,max=0,count=0,counts=0,max1=0,k=0,l;
	scanf("%d",&n);
	
	for(j=0;j<n;j++)
	{
		scanf("%s",a);
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]=='C')
			{
				count++;//1440
				counts++;
			}
			else
			{
				if(max<=count)
				{
					max=count;
				}
				
				if(max1<=counts)
				 max1=counts;
				 
				counts=0;
				count=0;
					k++;
			}
		}
		
		if(max<=count)
			max=count;
			
		l=count;
		count=0;
	}
	
	if(k==0)
	printf("%d %d",l,counts);
	else if(k>=1)
	printf("%d %d",max,max1);
	return 0;
}


