#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    system("color 0a");
    
    int a,b,m;
    
    printf("���������С���ܼ�����\n");
    
    
    
    printf("  O\n");
    printf("< H >\n");
    printf(" I I \n");
    
    
       //this is a little man
       
    scanf("%d",&a);
    
    Sleep(1500);
    
    system("cls");
    
    printf("���ܼ�����ʼ\n");
    
    
    
    printf("3\n");
    
    Sleep(1000);
    
    printf("2\n");
    Sleep(1000);
    
    printf("1\n");
    Sleep(1000);
    
    
       
     
    for(b=1;a>=b;b=b+1)
       
   {
       
       system("cls");
       
        for(m=0;m<b;m++)
        {
            
            printf(" ");
        }
        
        Sleep(300);
        printf("  O\n");     //ͷǰ��
        
        
        for(m=0;m<b;m++)
        {
           
            printf(" ");
        }
        Sleep(300);
        printf("< H >\n");  //��ǰ��
        
        for(m=0;m<b;m++)
        {
            printf(" ");
        }
        Sleep(300);
        printf(" I ");
        Sleep(300);
        printf("I");
        
        
    }
        
        return 0;
}
