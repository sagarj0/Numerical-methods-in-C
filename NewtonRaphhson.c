#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float xi, yxi = 0, ydxi = 0, xi1, e, error;
    int a[5], n, i, itr = 1;
    printf("Enter the no of terms in expression: ");
    scanf("%d", &n);
    printf("Enter the coefficients of each term with decreasing order of variable: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Now enter initial guess and also enter approx error: ");
    scanf("%f%f", &xi, &e);
    printf("\nIterations\txi\tf(xi)\tf(xi+1)\txi+1\terror\n");
    while (1)
    {
        for (i = 0; i < n; i++)
        {
            yxi += a[i] * pow(xi, n - i - 1);
        }

        for (i = 0; i < n - 1; i++)
        {
            ydxi += (n - i - 1) * a[i] * pow(xi, n - i - 2);
        }
        xi1 = xi - (yxi / ydxi);
        error = fabs((xi1 - xi) / xi1);
        printf("%d\t\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n", itr, xi, yxi, ydxi, xi1, error);
        itr++;
        if (error <= e || itr == 50)
        {
            break;
        }
        xi = xi1;
        yxi = ydxi = 0;
    }
    printf("\n So %.3f is root", xi1);
    return 0;
}