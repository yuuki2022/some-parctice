#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define N 6


short saizi_number(void);
bool play_game(void);
	
 int main(void){
 int fail_time=0,success_time=0,hb=0;
 char decision;
 
do{
	
 hb=play_game();
 
 if(hb==true){
 	printf("you win\n");
 	success_time++;
 }
 
 else if(hb==false){
 	printf("you lose\n");
 	fail_time++;
 }
 
 printf("play again(input y or n)?\n");
 
 decision=getchar();
 getchar();
 
 
   }while(decision== 'y');
   
   
    /*the final times of success and failure*/
   printf("FAIL:%d     ",fail_time);
   printf("WIN:%d",success_time);
   
   system("pause");
}



/*********************************************the sum of two dices*/
short saizi_number(void){
	short a(0),b(0);
	
	srand((unsigned)time(NULL));
	a=rand()%N+1;
	b=rand()%N+1;
	
	return a+b;
}
/***************************analyse the result of the two dices and give the comeout of your roll*/
bool play_game(void){
	int result=saizi_number();
	bool comeout=false; 
	
	if(result==7 || result==11){
	printf("you rolled:%hd\n", result);	
	return true;
	}
	
	else if(result== 2 ||result == 3 ||result == 12){
	printf("you rolled:%hd\n", result);
    return false;
    }
    
    else{
	 int goal= 0;
     goal= result;
     
     printf("your point is:%d\n",goal);
     
      while(true){
    	
		result= saizi_number();
	
		if(result==goal){
			printf("you rolled:%hd\n", result);
			return true;
		}
		
		else if(result== 7){
			printf("you rolled:%hd\n", result);
			return false;
		}
		
		else{
			printf("you rolled:%hd\n", result);
			continue;
			}
  		}
}
}
