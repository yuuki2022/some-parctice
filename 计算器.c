#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    int a,b,i;
    char c,Y;
    
    system("color 0a");
    
    printf("���ã�����һ��������\n");
    
    while(1)
   {
       scanf("%d%c%d",&a,&c,&b);
       
       if(c=='+'){printf("%d+%d=%d\n",a,b,a+b);}
       if(c=='-'){printf("%d-%d=%d\n",a,b,a-b);}
       if(c=='*'){printf("%d*%d=%d\n",a,b,a*b);}
       if(c=='/'){printf("%d/%d=%d\n",a,b,a/b);}
       
       printf("������1��������0\n");
       
       Y=getchar();
       
      
      if(i==1)
       {
           system("cls");
           printf("���¿�ʼ\n");
           continue;
       }
       
     if(i==0)
     {
         break;
     }
     
   }
    return 0;
}
