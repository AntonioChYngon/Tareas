#define MAX 100


typedef struct {
    char arr[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

int isStackFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char c) {
    if (!isStackFull(s)) {
        s->arr[++s->top] = c;
    }
}

char pop(Stack* s) {
    if (!isStackEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

char peek(Stack* s) {
    if (!isStackEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}
