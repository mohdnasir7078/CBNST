#include <stdio.h>
#include <math.h>
double f(double x)
{
    return x*log10(x)-1.2;
}
int main()
{
    printf("**************BISECTION METHOD***********\n");
    double a, b, c, pre;
    int i = 0;
    printf("Please Input A and B :");
    scanf("%lf%lf", &a, &b);
    if ((f(a) * f(b)) > 0)
    {
        printf("Wrong A and B.\n");
        printf("Try Again.");
        return 0;
    }
    do
    {
        i++;
        c = (a + b) / 2.0;
        pre = c;
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        printf("Iterations = %d || Root = %.5lf || Value = %lf\n", i, c, f(c));
        c = (a + b) / 2.0;
    } while (fabs(pre - c) > 0.00001);
    return 0;
}