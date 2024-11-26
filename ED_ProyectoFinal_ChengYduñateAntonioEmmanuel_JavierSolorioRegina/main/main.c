#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "headers.h"

void infixToPostfix(const char* infix, char* postfix) {
	int i;
    Stack stack;
    Queue queue;
    initStack(&stack);
    initQueue(&queue);

    for (i=0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            enqueue(&queue, c); // Operandos van a la cola
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isStackEmpty(&stack) && peek(&stack) != '(') {
                enqueue(&queue, pop(&stack));
            }
            pop(&stack); // Quitar '('
        } else if (isOperator(c)) {
            while (!isStackEmpty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                enqueue(&queue, pop(&stack));
            }
            push(&stack, c);
        }
    }

    while (!isStackEmpty(&stack)) {
        enqueue(&queue, pop(&stack));
    }

    // Pasar de la cola al arreglo de postfija
    int j = 0;
    while (!isQueueEmpty(&queue)) {
        postfix[j++] = dequeue(&queue);
        
    }
    postfix[j] = '\0'; // Terminar la cadena
}

void infixToPrefix(const char* infix, char* prefix) {
	
    char reversed[MAX];
    strcpy(reversed, infix);
    reverseString(reversed);
    int i=0;

    for (i=0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(') {
            reversed[i] = ')';
        } else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(reversed, postfix);
    reverseString(postfix);
    strcpy(prefix, postfix);
}



int main() {
	setlocale(LC_ALL,"");
	portada();
	int op;
	char infix[MAX], postfix[MAX], prefix[MAX];
	printf("Introduce una expresión infija: ");
    scanf("%s", infix);
    	
    system("cls");
	do{
		
    	
		op=menu();
		
		switch(op){
			case 1:
				infixToPostfix(infix, postfix);
				printf("Notación Postfija: %s\n", postfix);
				break;
			case 2:
				infixToPrefix(infix, prefix);
				printf("Notación Prefija: %s\n", prefix);
				break;
			case 3:
				printf("Introduce una expresión infija: ");
    			scanf("%s", infix);
				break;	
				
			case 4:
				break;
			default:
			printf("Introduce una opción valida");
		}
		printf("\n\n\n");
		system("pause");
		system("cls");
		
	}while(op!=4); 
    return 0;
}

