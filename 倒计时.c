#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    system("color 0a");
    
    int a,b,c,d,t;          //a=�� b=��
    
    scanf("%d%d",&a,&b);
    
    c=1;
    d=0;
    t=c;
    
    while(a>d)
{
    while(t%b!=0) 
 {  
     printf("  *");   //1��b����ʱ����
     t=c;
     c=c+1;
     
 }
 
    printf("\n");
    d=d+1;
    t=1;
    
     
        
}
    
    
    
    
    
    return 0;
  
}