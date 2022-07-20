#include <stdio.h>
#include <stdlib.h>

#define N 10

static int a=1; 

void hb(void){
	int a=0;
	static int i;
	a++;
	printf("%d",a);
}

int main(){


	hb();
	hb();
	
	printf("%d",a);
	
	return 0;
}
