#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,i,j,k;
    
    for(a=1;a<=6;a++)
    {
        for(b=1;b<=6;b++)
        {
            for(c=1;c<=6;c++)
            {
                for(i=1;i<=6;i++)
                {
                    for(j=1;j<=6;j++)
                    {
                        for(k=1;k<=6;k++)
                        
                        {
                            if(a!=b && a!=c && a!=i && a!=j && a!=k
                                    && b!=c && b!=i && b!=j && b!=k
                                            && c!=i && c!=j && c!=k
                                                    && i!=j && j!=k
                                                            && j!=k)
                            {
                                if(a+b+c==12&&a+k+j==12&&c+i+j==12)
                             {
                                printf("  %d  \n",a);
                                printf(" %d %d \n",b,k);
                                printf("%d %d %d\n",c,i,j);
                                printf("----------\n");
                            }
                        
                    }
                }
            }
        }
    }
  }
  }
    return 0;
}

