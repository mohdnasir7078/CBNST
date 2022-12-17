#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    printf("Enter no. of records:: ");
    scanf("%d", &n);
    int table[n][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            table[i][j] = 0;
        }
    }
    int year = 0, population = 0;
    printf("Year   Population\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &year);
        scanf("%d", &population);
        table[i][0] = year;
        table[i][1] = population;
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            table[i][j + 1] = table[i][j] - table[i - 1][j];
        }
    }
    int x;
    printf("\nEnter the Population:: ");
    scanf("%d", &x);
    int h = table[1][0] - table[0][0];
    float p = (x - table[n - 1][0]) / (float)h;
    float y = 0;
    int fact = 1;
    float pp = 1.0;
    for (int j = 1; j < n + 1; j++)
    {
        y += (float)pp * table[n - 1][j] / fact;
        pp *= p++;
        fact *= j;
    }
    printf("Population = %0.3f", y);
}
