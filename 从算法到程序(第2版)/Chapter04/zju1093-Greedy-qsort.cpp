#include <stdio.h>
#include <stdlib.h>
#define NUM 100

struct block {
    int x, y, z;
} box[2 * NUM];

void oriente(int k, int x, int y, int z)
{
    box[k].x = x;
    box[k].y = y;
    box[k].z = z;
}

int cmp(const void * a, const void * b)
{
    return ((block*)b)->x - ((block*)a)->x;
}

int main()
{
    int i, j;
    int n;
    int x, y, z;
    int height[2 * NUM];
    int Case = 1;

    while (scanf("%d", &n) && n) {
        int number = 0;

        for (j = 0; j < n; j++) {
            scanf("%d%d%d", &x, &y, &z);
            oriente(number++, x, y, z);
            oriente(number++, x, z, y);
            oriente(number++, y, z, x);
            oriente(number++, y, x, z);
            oriente(number++, z, x, y);
            oriente(number++, z, y, x);
        }

        n *= 6;
        qsort(box, n, sizeof(block), cmp);

        for (i = 0; i < n; i++)
            height[i] = box[i].z;

        int max;
        int answer = 0;

        for (i = 0; i < n; i++) {
            max = 0;

            for (j = i - 1; j >= 0; j--)
                if (box[i].x < box[j].x && box[i].y < box[j].y && max < height[j])
                    max = height[j];

            height[i] += max;

            if (answer < height[i]) answer = height[i];
        }

        printf("Case %d: maximum height = %d\n", Case++, answer);
    }

    return 0;
}
