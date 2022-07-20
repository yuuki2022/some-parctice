#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,i,t,e,m,c,d;
    
 
    
    t=0;
    m=0;
    a=9;
    b=1;
    
    system("color 0a");
    
    for(b=1;a>=b;b+1)
    {
        
        for(e=(a-b)/2;e>m;m=m+1)
        {
            printf(" ");   //前空
        }
        
        
        for(i=1;t<i;t=t+1)
        {
            printf("*");   //中点
        }
        
        i=2i+1;
        
        for(c=(a-b)/2;d<c;d=c+1)
        {
            printf(" ");    //后空
        }
        
    
        printf("\n");
    }
    
    return 0;
}
