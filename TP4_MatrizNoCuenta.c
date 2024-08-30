#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int **matriz;
	char noCuenta[9];
	
	gets(noCuenta);
	//423101700
	matriz=(int**)malloc(9*sizeof(int*));
	int i;
	int j;
	
	for(i=0; i<9; i++){
		noCuenta[i]-=48;
		*(matriz+i)=(int*)malloc(noCuenta[i]*sizeof(int));
		
		for(j=0; j<noCuenta[i]; j++){
			*(*(matriz+i)+j)=noCuenta[i];
			//printf("[%d][%d]=%d\n",i,j,noCuenta[i]);
		}
		
	}
	
	for(i=0; i<9; i++){
		for(j=0; j<noCuenta[i]; j++){
			printf("|%d| ",*(*(matriz+i)+j));
		}
		if(noCuenta[i]!=0){
			printf("\n");	
		}
		
	}
	
}
