#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    int a,b;
    
    printf("¾Å¾Å³Ë·¨±í\n");
    
    system("color 0a");
    
    b=1;
    
    for(a=1;a<=9;a=a+1)
    {
        for(b=1;b<=a;b=b+1)
       {
            printf("  %d*%d=%d",b,a,b*a);
            Sleep(200);
            
       }
       
       printf("\n");
       Sleep(250);
        
    }
    return 0;
}
