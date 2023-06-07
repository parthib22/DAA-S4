#include <stdio.h>
#include <stdlib.h>

#define inf 9999
#define N 5

int G[N][N] = { {0, 2, 0, 6, 0},
                {2, 0, 3, 8, 5},
                {0, 3, 0, 0, 7},
                {6, 8, 0, 0, 9},
                {0, 5, 7, 9, 0} };

int spanning[N][N];
int n = N;

int prims();

int main() {
    int i, j, tcost;

    tcost = prims();
    printf("\nspanning tree matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", spanning[i][j]);
    }
    printf("\n\nTotal cost of a spanning tree = %d", tcost);
    return 0;
}

int prims() {
    int cost[N][N];
    int u, v, mindist, dist[N], from[N];
    int visited[N], edgeno, i, mincost, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = inf;
            else
                cost[i][j] = G[i][j];
            spanning[i][j] = 0;
        }
    }
    dist[0] = 0;
    visited[0] = 1;
    from[0] = 0;
    for(i = 1; i < n; i++) {
        dist[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    mincost = 0;
    edgeno = 0;
    while (edgeno < n - 1) {
        mindist = inf;
        for (i = 1; i < n; i++) {
            if(visited[i] == 0 && dist[i] < mindist) {
                v = i;
                mindist = dist[i];
            }
        }
        u = from[v];

        spanning[u][v] = dist[v];
        spanning[v][u] = dist[v];

        visited[v] = 1;

        for (i = 1; i < n; i++) {
            if(visited[i] == 0 && cost[i][v] < dist[i]) {
                dist[i] = cost[i][v];
                from[i] = v;
            }
        }
        mincost = mincost + cost[u][v];
        edgeno++;
    }
    return(mincost);
}