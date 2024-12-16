#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
typedef struct Queue {
    int item[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->item[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->item[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void BFS(int start, int n) {
    Queue q;
    initQueue(&q);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    enqueue(&q, start);
    visited[start] = 1;

    while (!isEmpty(&q)) {
        int current = po(&q);
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}
void DFS(int current, int n) {
    printf("%d ", current); 
    visited[current] = 1;    
    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(i, n);  
        }
    }
}
int main() {
    int n, edges, start;
    printf("Nhap so dinh va so canh cua do thi: ");
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap cac canh (dinh u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;                                              
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    printf("Ket qua BFS: ");
    BFS(start, n);

    return 0;
}

