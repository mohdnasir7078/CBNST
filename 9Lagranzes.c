#include <stdio.h>
#include <math.h>
int main()
{
    int n = 4;
    printf("Input no of terms :");
    scanf("%d", &n);
    float x[n], y[n], mul = 1, u = 1, d = 1, fx = 10, ans = 0;
    printf("input values for X and  F(X)\n.");
    printf("X         f(X)\n");
    for (int i = 0; i < n; i++)
        scanf("%f%f", &x[i], &y[i]);
    printf("input point :");
    scanf("%f", &fx);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                mul = y[j];
                continue;
            }
            u *= (fx - x[j]);
            d *= (x[i] - x[j]);
        }
        ans += (u / d) * mul;
        u = 1, d = 1;
    }
    printf("f(x) value is at value %f:%0.05f ", ans, fx);
    return 0;
}