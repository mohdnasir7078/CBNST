#include <stdio.h>
#include <math.h>
/*float m[10][10] = {{9, 2, 4, 20}, {1, -1, 4, 6}, {2, -4, 10, -15}};*/
int main()
{
    // float m[10][10] = {{8, 1, 1, 8}, {2, 4, 1, 4}, {1, 3, 5, 5}};
    // float m[10][10] = {{8, -3, 2, 20}, {4, 11, -1, 33}, {6, 3, 12, 36}};
    // float m[10][10] = {{1, 1, -1, 0}, {-1, 3, 0, 2}, {1, 0, -2, 3}};
    // float m[10][10] = {{9, 2, 4, 20}, {1, 10, 4, 6}, {2, -4, 10, -15}};
    float val[10] = {0, 0, 0, 0, 0, 0};
    int size = 3, k = 0, count = 0, it = 0;
    float x, y;
    for (int i = 0; i < size; i++)
    {
        it++;
        x = m[i][size];
        for (int j = 0; j < size; j++)
        {
            if (i != j)
                x -= val[j] * m[i][j];
        }
        x = (1.0 / m[i][i]) * x;
        y = fabs(x - val[i]);
        val[i] = x;
        if (y < 0.0001)
            count++;
        if (count == size - 1 && i == size - 1)
            break;
        else if (i == size - 1 && count != 3)
        {
            count = 0;
            i = -1;
        }
    }
    printf("No of Iterations is :%d\n", it);
    for (int i = 0; i < size; i++)
        printf("x%d = %0.2f\n", i + 1, val[i]);
    return 0;
}