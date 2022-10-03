#include <stdio.h>
int main()
{
    float m[10][10] = {{2, 4, 1, 3}, {3, 2, -2, -2}, {1, -1, 1, 6}};
    float div, sum = 0, mul = 0;
    int size = 3, k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && m[i][i] != 0)
            {
                div = m[j][i] / m[i][i];
                for (int k = 0; k <= size; k++)
                    m[j][k] = m[j][k] - (div * m[i][k]);
            }
        }
    }
    for (int i = 0; i < size; i++)
        printf("x%d = %0.2f\n", i + 1, m[i][size] / m[i][i]);
    return 0;
}