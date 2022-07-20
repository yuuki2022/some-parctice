#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,i;
    
    system("color 0a");
    
    i=0;
    b=2;
    
    scanf("%d",&a);
    
    while(a>b)
    {
        
        
        if(a%b==0)
        {
            i++;
           break;
        }
        
        b=b+1;
    }
  
    if(i==1)
    {
        printf("合数");
    }
    
    else
    {
        printf("质数");
    }
    
    
    
    
    return 0;
}
