#include<stdio.h>
#include<math.h>
double productsum(float x[],float y[],int n )
{
    int  i;
    double sum=0;
    for(i=0;i<n;i++)
    {
       sum+=x[i]*log(y[i]);
    }
    return sum;
}
int main()
{
    float x[100], y[100], z[100];
    int i=0,n;
    double b,a;
    printf("enter the number of data points: ");
    scanf("%d",&n);
    printf("Enter data points x and y successively: ");
    for(;i<n;i++)
    {
        scanf("%f",&x[i]);
        scanf("%f",&y[i]);
        z[i]=exp(1);
    }
    b= ((n*productsum(x,y,n))-(productsum(x,z,n)*productsum(z,y,n)))/((n*productsum(x,x,n))-pow(productsum(x,z,n),2));
    a= exp( (productsum(z,y,n) - (b*productsum(x,z,n)))/n);
    printf("Required linear regression eqaution is : y = %.2lf, %.2lf",a,b);
}
// this is not executing.