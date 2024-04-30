#include <stdio.h>

int main() {
    int jumsu[10][3] = { {1, 88, 83}, {2, 98, 77}, {3, 85, 88}, {4, 75, 85}, {5, 86, 97}, {6, 89, 95}, {7, 87, 99}, {8, 65, 88},
        {9, 45, 70}, {10, 96, 80} };
    int total[10] = { 0 };
    int i, j, k, tot, temp = 0;

    for (i = 0; i < 10; i++)
    {
        tot = 0;
        for (j = 1; j < 3; j++)
            tot += jumsu[i][j];
        total[i] = tot;
    }

    for (i = 9; i > 0; i--)
        for (j = 0; j < i; j++)
            if (total[j] < total[j + 1])
            {
                temp = total[j];
                total[j] = total[j + 1];
                total[j + 1] = temp;
            }
    
    printf("번호 영어 일어 합계 평균 순위 \n");

    for (i = 0; i < 10; i++)
    {
        printf("   %d ", jumsu[i][0]);
        for (j = 1; j < 3; j++)
            printf("%d ", jumsu[i][j]);
        printf("%d %.2lf ", jumsu[i][1] + jumsu[i][2], (jumsu[i][1] + jumsu[i][2]) / 2.0);
        for (k = 0; k < 10; k++)
            if (total[k] == jumsu[i][1] + jumsu[i][2])
                printf("%d \n", k + 1);
        }
    }