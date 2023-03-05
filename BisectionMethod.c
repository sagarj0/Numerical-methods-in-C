#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float xl, xu, xm, yl = 0, yu = 0, ym = 0, e, error;
    int a[5], n, i, itr = 1;
    printf("Enter the no of terms in expression: ");
    scanf("%d", &n);
    printf("Enter the coefficients of each term with decreasing degree of variable: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Now enter two initial guesses such that in between two there exists root and also enter approx error: ");
    scanf("%f%f%f", &xl, &xu, &e);
    while (1)
    {
        xm = (xl + xu) / 2;
        for (i = 0; i < n; i++)
        {
            yl += a[i] * pow(xl, n - i - 1);
            yu += a[i] * pow(xu, n - i - 1);
            ym += a[i] * pow(xm, n - i - 1);
        }
        error = fabs((xl - xu) / xu);
        printf("%d\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", itr, xl, xu, xm, yl, yu, ym, error);
        itr++;
        if (error <= e)
        {
            break;
        }
        else if (yl < 0 && yu > 0)
        {
            if (ym < 0)
            {
                xl = xm;
            }
            else
            {
                xu = xm;
            }
        }
        else if (yl > 0 && yu < 0)
        {
            if (ym < 0)
            {
                xu = xm;
            }
            else
            {
                xl = xm;
            }
        }
        else
        {
            printf("Invalid guesses:");
            break;
        }
        yl = yu = ym = 0;
    }
    printf("%.2f is root of the equation.", xm);
    return 0;
}
