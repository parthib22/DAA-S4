#include <stdio.h>

int find(int set[], int u)
{
    return set[u];
}
int dounion(int set[], int n, int s1, int s2)
{
    int i, t1, t2;
    if (s1 < s2)
    {
        t1 = s1;
        t2 = s2;
    }
    else
    {
        t1 = s2;
        t2 = s1;
    }

    for (i = 0; i < n; i++)
    {
        if (set[i] == t2)
            set[i] == t1;
    }
}
int main()
{
    int G[5][5] = {{0, 1, 1, 0, 1}, {1, 0, 0, 1, 1}, {0, 1, 1, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 1, 1, 0}};
    int set[5] = {0, 1, 2, 3, 4};
    int i, j, n = 5, s1, s2;
    int cycleflag = 0;

    for (i = 0; i < n && cycleflag == 0; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (G[i][j] > 0)
            {
                s1 = find(set, i);
                s2 = find(set, j);

                if (s1 == s2)
                {
                    cycleflag = 1;
                    break;
                }
                else
                {
                    dounion(set, n, s1, s2);
                }
            }
        }
    }
    if (cycleflag == 1)
    {
        printf("Cycle found\n");
    }
    else
    {
        printf("Cycle not found");
    }
}