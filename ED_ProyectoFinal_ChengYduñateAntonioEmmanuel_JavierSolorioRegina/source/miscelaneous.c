//Portada//
void portada(){
	printf("::Conversión de expresiones infijas a postfija/infija::\n\n");
	printf("Chenge Yduñate Antonio Emmanuel\t- 423101700\n");
	printf("Javier Soloria Regina\t\t- 321296810\n\n\n");
	system("pause");
	system("cls");
}

int menu(){
	int op;
	printf("¿Que deseas hacer?\n");
	printf("1.-Convertir de infija a postfija.\n");
	printf("2.-Convertir de infija a prefijafija.\n");
	printf("3.-Introducir nueva expresión infija\n");
	printf("4.-Salir\n\n");
	
	scanf("%d",&op);
	return op;
}


//Precedencia de operadores//
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

//Verificar si el caracter == operador//
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

//Invertir cadena//
void reverseString(char* str) {
    int len = strlen(str);
    int i;
    for (i=0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
