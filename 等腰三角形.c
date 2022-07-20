#include <stdio.h>
#include <stdlib.h>
int main()
{
   system("color 0a");
   
   int a,b,i,j,n,m;
    a=0;
    b=0;
    i=0;
    j=0;
    n=0; 
    m=0;  //³õÊ¼»¯
    
    scanf("%d",&a);
    
    for(i=1;i<a+1;i++)
    {
        n=2i-1;
        
        for(n=a-i-1;n>0;n--)
        {
            printf(" ");
        }                  //×ó¿Õ
        
        
        for(j=0;j<n;j++)
       {
           printf("*");
       
        }
        
        for(n=a-i;n>0;n--)
        {
            printf(" ");  //×ó¿Õ
        }
        
        
        printf("\n");
    }
    return 0;
}
