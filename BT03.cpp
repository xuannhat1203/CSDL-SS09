#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX];  
int visited[MAX];     
int recStack[MAX];   
bool isCyclicDirected(int current, int n) {
    visited[current] = 1;
    recStack[current] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1) {
            if (!visited[i]) {
                if (isCyclicDirected(i, n)) {
                    return true;
                }
            } else if (recStack[i]) { 
                return true;
            }
        }
    }

    recStack[current] = 0;  
    return false;
}
int main() {
    int n, edges, isDirected;
    printf("Nhap so luon dinh: ");
    scanf("%d", &n);
    printf("Nhap so luong canh: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Nhap cac canh va cac dinh: \n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
        if (!isDirected) {
            graph[v][u] = 1; 
        }
    }
    bool hasCycle = false;
    if (isDirected) {
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
            recStack[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (isCyclicDirected(i, n)) {
                    hasCycle = true;
                    break;
                }
            }
        }
    }
    if (hasCycle) {
        printf("Ðo thi có chu ki.\n");
    } else {
        printf("Ðo thi không có chu ki.\n");
    }

    return 0;
}

