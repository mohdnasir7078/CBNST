#include <stdio.h>
#include <math.h>
double f(double x)
{
    return (1.0 / (1 + (x * x)));
}
int main()
{
    double l = 0, u = 6, h;
    int inte = 12, n;
    printf("input range:");
    scanf("%f%f", &l, &u);
    printf("Please input no of subinterval:");
    scanf("%d", &inte);
    h = (u - l) / inte;
    n = (u - l) / h;
    double x[n + 1], y[n + 1];
    for (int i = 0; i <= n; i++)
    {
        x[i] = l + i * h;
        y[i] = f(x[i]);
    }
    double ans = (y[0] + y[n]), mul = 0;
    for (int i = 1; i < n; i++)
        mul += y[i];
    mul *= 2;
    ans += mul;
    ans *= h;
    ans /= 2;

    printf("The ans is :%0.4f", ans);
    return 0;
}