#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    system("color 0a");
    
  int a[20],i,j,n,t;
  
  for(i=1;i<=20;i++)
  {
      a[i]=0;
  }
  i=0;
  j=0;
  
  puts("这是一个数据排序程序");
  puts("你想读入几个数");
  
  scanf("%d",&n);
  
  puts("请输入数据");
  
  for(i=1;i<=n;i++)
 {
    scanf("%d",&a[i]);
 }
  
  
  for(i=1;i<=n;i++)
  {
     for(j=i+1;j<=n;j++)
         if(a[j]<a[i])
         {
             t=a[i];
             a[i]=a[j];
             a[j]=t;
         }
     printf("%d ",a[i]);
  }
}
