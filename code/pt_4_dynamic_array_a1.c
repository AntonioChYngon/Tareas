#include <stdio.h>
#include <stdlib.h>

int main(){
	int *pPares;
	int size=10, i;
	//Número de cuenta 423101700
	int lastDigit=0;
	pPares = calloc(size, sizeof(int));
	
	for(i=0; i<size; i++){
		
		*(pPares+i)=(i+1)*2;
	}
	
	for(i=size-1; i>=0; i--){
		printf("%d ",*(pPares+i));
	}
	
	printf("\n");
	*(pPares+lastDigit)=-1;
	
	for(i=0; i<size; i++){
		printf("%d ",*(pPares+i));
	}
	
	free(pPares);
	
	
	
	return 0;
}
