#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
    
   { 
    system("color 0a");
    
    int a,x,i,t;
    x=0;
    i=0;
    t=0;
    
    scanf("%d",&a);
    
    
    while(a>t)
    {
        while(t>=x)
    { 
             i=i+1;
             Sleep(100);
             printf(" %d",i);
             x=x+1;
            
    }                                                           
    x=0;
    
    
    printf("\n");
    
    t=t+1;
    }
    
    return 0;
   }
     
     
