#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;
int main()
{
   int a,b,i;
   
   
    i=0;                               //初始
   
   printf("求出两个整数之间所有整数之和\n");
   
   scanf("%d%d",&a,&b);
   
   if(a>b)
   {a=a+b,b=a-b;a=a-b;}
   
   while(a<=b)
 {
     i=i+a;
     a=a+1;
     
 }
  Sleep(1500);
  printf("答案即将揭晓\n");
  
  Sleep(1800);
  printf("3\n");
  Sleep(2000);
  printf("2\n");
  Sleep(2000);
  printf("1\n");
  Sleep(2000);
  
  
  
  printf("------------------------------\n%d",i);
 
  return 0;
}
   
   
   
  
