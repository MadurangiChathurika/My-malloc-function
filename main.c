#include<stdio.h>
#include<stdbool.h>
#include"mymalloc.h"


void main(){
	char* addr1=Mymalloc(25000);
	char* addr2=Mymalloc(400);
	char* addr3=Mymalloc(100);
	
	printf("26000  %p\n",addr1);
	printf("400  %p\n",addr2);
    printf("100  %p\n",addr3);

    Myfree( addr3);
	Myfree( addr2);
	printf("%p is %c\n",addr2,*addr2);
	printf("%p is %c\n",addr2,*addr2);
	printf("%p is %c",addr3,*addr3);
}
