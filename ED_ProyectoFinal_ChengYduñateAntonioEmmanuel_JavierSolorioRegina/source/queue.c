#define MAX 100

typedef struct {
    char arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

int isQueueFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, char c) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q)) {
            q->front = 0;
        }
        q->arr[++q->rear] = c;
    }
}

char dequeue(Queue* q) {
    if (!isQueueEmpty(q)) {
        char val = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // Cola vacía
        } else {
            q->front++;
        }
        return val;
    }
    return '\0';
}
