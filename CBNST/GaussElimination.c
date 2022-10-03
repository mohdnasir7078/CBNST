#include <stdio.h>
int main()
{
   float m[10][10] = {{1, 1, -1, 0}, {-1, 3, 0, 2}, {1, 0, -2, 3}};
    int size = 3, k = 0;
    float div, mul, sum = 0;
    // scanf("%d", &size);
    // for (int i = 0; i < size; i++)
    //     for (int j = 0; j <= size; j++)
    //         scanf("%f", &m[i][j]);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            div = m[j][i] / m[i][i];
            for (int k = 0; k <= size; k++)
                m[j][k] = m[j][k] - (div * m[i][k]);
        }
    }
    float ans[size];
    for (int i = size - 1; i >= 0; i--)
    {
        sum = 0;
        for (int k = 0; k < size; k++)
            if (k != i)
                sum += m[i][k];
        m[i][size] -= sum;
        mul = m[i][size] / m[i][i];
        m[i][size] = mul;
        ans[i] = mul;
        for (int j = i - 1; j >= 0; j--)
            m[j][i] *= mul;
    }
    for (int i = 0; i < size; i++)
        printf("x%d = %0.2f\n", i+1,ans[i]);
    /*  for (int i = 0; i < size; i++)
      {
          for (int j = 0; j <= size; j++)
              printf("%0.1f ", m[i][j]);
          printf("\n");
      }*/
    return 0;
}