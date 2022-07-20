#include <stdio.h>
#include <stdlib.h>




int main(){
	void *p;
	
	p = malloc(100000000000000000000000000);
	
	if(p){
		printf("So what");
	}
		
	return 0;
	
}
