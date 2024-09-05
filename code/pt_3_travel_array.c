#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int x, int y){
	int **Matriz;
	/*/ malloc devuelve un puntero sin tipo, al multiplicarlo por float** se convierte
	en un puntero que apunta a punteros de flotantes /*/
	Matriz=(int**)malloc(x*sizeof(int*));//<-Reservamos "x" espacios de punteros que apuntan a punteros de flotantes (Filas de la Matriz)
	int i;
	for(i=0; i<x; i++){
		*(Matriz+i)=(int*)malloc(y*sizeof(int)); //<-Reservamos "y" espacios de apuntadores de flotantes (Columnas de la Matriz)
	}
	return Matriz;//<-Devolvemos un puntero que apunta a punteros de flotantes.
}

void lecturaMatriz(int x, int y, int **Matriz){
	int i, j;
	for (i=0; i<x; i++){
	
		for (j=0; j<y; j++){//Doble ciclo que recorre la matriz fila x fila
			printf("[%d][%d]: ", i+1,j+1);
			scanf("%d", *(Matriz+i)+j); /*/<-Matriz+i apunta al puntero de flotantes de la i-th posición, al agregar "*", estamos
			obteniendo esa direccion, "+j" queda fuera pues queremos obtener la direccion del elemento flotante en la j-th posición/*/
		}
	}
}


void escribirMatriz(int x, int y, int **Matriz){
	int i, j;
	for (i=0; i<x; i++){
	
		for (j=0; j<y; j++){
			printf("[%d][%d] = %d \t", i+1,j+1,*(*(Matriz+i)+j));
			
		}
		printf("\n");
	}
	
}
void snakePrint(int x, int y, int **Matriz){
	int i, j;
	for (i=0; i<x; i++){
		if(i%2==0){
			for (j=0; j<y; j++){//Doble ciclo que recorre la matriz fila x fila
				printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			}	
		}else{
			for (j=y-1; j>=0; j--){//Doble ciclo que recorre la matriz fila x fila
				printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			}
		}
		
		
	}
}

void zPrint(int x, int y, int **Matriz){
	int i, j;
	for (i=0; i<x; i++){
		if(i==0 || i==x-1){
			for (j=0; j<y; j++){//Doble ciclo que recorre la matriz fila x fila
				printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			}	
		}else{
			j=x-(i+1);
			
			
				printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			
		}
		
		
	}
}

void bckZPrint(int x, int y, int **Matriz){
	int i, j;
	for (i=x-1; i>=0; i--){
		if(i==0 || i==x-1){
			for (j=y-1; j>=0; j--){//Doble ciclo que recorre la matriz fila x fila
				printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			}	
		}else{
			j=x-(i+1);
			
			
				printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			
		}
		
		
	}
}

void RightLeft_downUp(int x, int y, int **Matriz){
	int i, j;
	for (i=x-1; i>=0; i--){
	
		for (j=y-1; j>=0; j--){
			printf("[%d][%d] = %d \n", i+1,j+1,*(*(Matriz+i)+j));
			
		}
	}
	
}

void freeMatrix(int x, int **Matriz){
	int i;
	for(i=0; i<x; i++){
		free(*(Matriz+i));
	}
}

int main(){
	int **Matriz1=createMatrix(4,6);
	int **Matriz2=createMatrix(6,6);
	int **Matriz3=createMatrix(4,3);
	
	printf("\n--------RECORRIDO DE SERPIENTE-----------\n");
	lecturaMatriz(4,6,Matriz1);
	system("cls");
	printf("\n--------MATRIZ ORIGINAL-----------\n");
	escribirMatriz(4,6,Matriz1);
	printf("\n--------RECORRIDO DE SERPIENTE-----------\n");
	snakePrint(4,6, Matriz1);
	system("pause");
	system("cls");
	
	printf("\n--------RECORRIDO DE Z-----------\n");
	lecturaMatriz(6,6,Matriz2);
	system("cls");
	printf("\n--------MATRIZ ORIGINAL-----------\n");
	escribirMatriz(6,6,Matriz2);
	printf("\n---------RECORRIDO Z----------\n");
	zPrint(6,6,Matriz2);
	system("pause");
	printf("\n-------RECORRIDO Z AL REVES----------\n");
	bckZPrint(6,6,Matriz2);
	system("pause");
	system("cls");
	
	printf("\n--------RECORRIDO INVERSO-----------\n");
	lecturaMatriz(4,6,Matriz3);
	printf("\n--------MATRIZ ORIGINAL-----------\n");
	escribirMatriz(6,6,Matriz3);
	printf("\n---------RECORRIDO Inverso----------\n");
	RightLeft_downUp(4,3,Matriz3);
	
	system("pause");
	
	
	
	freeMatrix(4, Matriz1);
	free(Matriz1);
	
	freeMatrix(6, Matriz2);
	free(Matriz2);
	
	freeMatrix(4, Matriz3);
	free(Matriz3);
}
