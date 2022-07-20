#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    int a,b,i;
    
    system("color 0a");
    
    b=1;
    i=0;
    
    scanf("%d",&a);
    
   
    
    while(a>=b)
 {
    system("cls");
    i=0;
    
     while(b>i)
     {
         printf("  ");
         i=i+1;
     }
     
     printf("H");
    
     Sleep(500);
     b=b+1;
 }
    
    return 0;
}
