#include <stdio.h>
#include <math.h>
float f(float x, float y)
{
    return (x + y);
}
int main()
{
    float y0 = 1, x0 = 0, x = 0.1, h, y1 = 0, temp, slop;
    int n;
    printf("Enter Initial Condition.\nx0 :");
    scanf("%f", &x0);
    printf("y0 :");
    scanf("%f", &y0);
    printf("Enter calculation point xn :");
    scanf("%f", &x);
    printf("Enter number of steps :");
    scanf("%d", &n);
    h = (x - x0) / n;
    printf("x0      y0      slope   yn\n");
    printf("----------------------------\n");
    int i = 0;
    do
    {
        slop = f(x0, y0);
        y1 = y0 + h * f(x0, y0);
        y0 = y1;
        x0 = x0 + h;
        printf("%.4f\t%.4f\t%0.4f\t%.4f\n", x0, y0, slop, y1);
        i++;
    } while (fabs(x0 - x) > 0.00001);
    printf("Value of y at x = %f :%f", x, y1);
    return 0;
}
