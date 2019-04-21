#include<stdio.h>
#include<stdbool.h>

char memoryArray[25000]={'\0'};
char *head =memoryArray;
char freeblock='f';
char allocate_block='a';

char* search_block(int size){
	char *check;
    check=head;
	
	int n=0;

	
	while(true){
		n=*(int*)(check+1);
		if(*check==freeblock && n>=size+5){
			return(check);
		}
		else if(!check){
			return NULL;
		}
		else{
		
		    check=check+n;
		}
	} 

}

void split_block(char* block,int size){
	char* temp;
	int block_size=*(int*)(block+1);
	block_size = block_size - size-5;
	
	temp = block+size+5;
	*temp=freeblock;
	*(int*)(temp+1)=block_size;
	*(int*)(block+1)=size+5;
	*block=allocate_block;
}

char *Mymalloc(int size){
	
	if(size<=0){
		printf("ERROR! can not allocate");
		return NULL;
	}
   if(size>24999-5){
		printf("memory is not enough");
		return NULL;
		
	}
	if(!*head){
		*head=freeblock;
		*(int*)(head+1)=24999-5;
	}
	

	
	char *block = search_block(size);

	
		if(*(int*)(block+1)>=size){
			split_block(block,size);
		}
	
	else{
		return NULL;
	}
	return(block);

}

void Myfree(char* address){
    char *check,*prev,*next;
	check=head;
	int n=*(int*)(check+1);
	
	while(true){
		n=*(int*)(check+1);
		if(check==address){
			break;
		} 
		else if(!*check){
			break;
		}
		else{
			prev=check;
			check=check+n;
			next=check + *(int*)(check+1);
		}
	}
	if(*next==freeblock){
		*check=freeblock;
		*(int*)(check+1) = *(int*)(check+1) + *(int*)(next+1); 
	}
	if(*prev==freeblock){
	*check=freeblock; 
	*(int*)(prev+1) = *(int*)(check+1) + *(int*)(prev+1);	
   }
    else{
	*address=freeblock;
	
   } 

}





