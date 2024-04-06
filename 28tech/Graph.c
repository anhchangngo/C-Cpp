#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
BFS 
10 11
1 2
1 3
1 5
1 10
2 4
3 6 
3 7
3 9
6 7
5 8
8 9
*/

/*
DFS
9 9
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
8 9
*/

#define MAXN 1001

int n, m;
int adj[MAXN][MAXN];
bool visited[MAXN];

void inp() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    memset(visited, false, sizeof(visited));
}

// BFS
void bfs(int u) {
    // Initialization
    int queue[MAXN];
    int front = 0, rear = -1;
    
    queue[++rear] = u;
    visited[u] = true;

    // BFS traversal
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int x = 1; x <= n; x++) {
            if (adj[v][x] == 1 && !visited[x]) {
                queue[++rear] = x;
                visited[x] = true;
            }
        }
    }
}

// DFS
void dfs(int u) {
    printf("%d ", u);
    // Mark u as visited
    visited[u] = true;

    for (int v = 1; v <= n; v++) {
        // If v is adjacent to u and hasn't been visited
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    inp();
    printf("DFS: ");
    dfs(1);

    // Reset visited array for BFS
    memset(visited, false, sizeof(visited));
    printf("\nBFS: ");
    bfs(1);

    return 0;
}

/*
*/