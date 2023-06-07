#include <stdio.h>
int find(int);
void doUnion(int,int);
struct edge {
    int u;
    int v;
    int w;
};
struct edge e[36];
int n = 6;
int k = 0;
int g[6][6] = { {0, 7, 0, 0, 0, 8},
                {7, 0, 6, 0, 0, 3},
                {0, 6, 0, 5, 2, 4},
                {0, 0, 5, 0, 2, 0},
                {0, 0, 2, 2, 0, 3},
                {8, 3, 4, 0, 3, 0} };
int set[6] = {0, 1, 2, 3, 4, 5};
int t[6][6] = { {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0} };

int main() {
    int i, j, u, v, minIndex, r1, r2, mstWt = 0;
    struct edge tempEdge;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (g[i][j] > 0) {
                e[k].u = i;
                e[k].v = j;
                e[k].w = g[i][j];
                k++;
            }
        }
    }
    for (i = 0; i < k; i++) {
        minIndex = 0;
        for (j = 0; j < k - i; j++) {
            if(e[minIndex].w > e[j].w) {
                minIndex = j;
            }
        }
        u = e[minIndex].u;
        v = e[minIndex].v;
        r1 = find(u);
        r2 = find(v);
        if(r1 != r2) {
            doUnion(r1,r2);
            t[u][v] = e[minIndex].w;
            mstWt += e[minIndex].w;
        }
        tempEdge = e[minIndex];
        e[minIndex] = e[k - 1];
        e[k - 1] = tempEdge;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    printf("MST Cost = %d\n", mstWt);
    return 0;
}

int find(int u) {
    return set[u];
}
void doUnion(int s1, int s2) {
    int t1,t2,i;
    if(s1 > s2) {
        t1 = s2;
        t2 = s1;
    }
    else {
        t1 = s1;
        t2 = s2;
    }
    for (i = 0; i < n; i++) {
        if(set[i] == t2)
            set[i] = t1;
    }
}