#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int t=0,a[100]={0},n=0,i=0,sum=0;
  
  scanf("%d",&t);
  
  for(n=0;n<t;n++)
  {
  	scanf("%d",&a[n]);
  }

  for(n=0;n<t;n++)
  {
  	sum=0;
	for(i=1;i<=a[n];i++)
  	{
  		if(a[n]%i==0)
  		{
  			sum=sum+i;
  		}
  	}
    printf("%d",sum);
  	printf("\n");
  }
  
  system("pause");
  
  return 0;
}
