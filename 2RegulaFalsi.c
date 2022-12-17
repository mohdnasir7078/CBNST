#include <stdio.h>
#include <math.h>
double f(double x)
{
    return x * x - 10;
}
int main()
{
    double x0, x1, temp, temp1;
    int i = 0;
    printf("**************REGULA FALSI METHOD***********\n");
    printf("Please Enter Root Range :");
    scanf("%lf %lf", &x0, &x1);
    if ((f(x0) * f(x1)) > 0)
    {
        printf("Wrong A and B.\n");
        printf("Try Again.");
        return 0;
    }
    if (x0 > x1)
    {
        double temp = x0;
        x1 = x0;
        x0 = temp;
    }
    do
    {
        temp = x0 - (((x1 - x0) / (f(x1) - f(x0))) * f(x0));
        if (f(temp) < 0)
            x0 = temp;
        else
            x1 = temp;
        temp1 = x0 - (((x1 - x0) / (f(x1) - f(x0))) * f(x0));
        i++;
        printf("Iterations = %d || Root = %.5lf || Value = %lf\n", i, temp, f(temp));
    } while ((fabs(temp1) - (temp)) > 0.00001);

    return 0;
}