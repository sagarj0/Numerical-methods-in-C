#include<stdio.h>
#include<math.h>
int productsum(int x[],int y[],int n )
{
    int i, sum=0;
    for(i=0;i<n;i++)
    {
       sum+=x[i]*y[i];
    }
    return sum;
}
int main()
{
    int x[100], y[100], z[100],n,i=0;
    float b,a;
    printf("enter the number of data points: ");
    scanf("%d",&n);
    printf("Enter data points x and y successively: ");
    for(;i<n;i++)
    {
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
        z[i]=1;
    }
    b= ((n*productsum(x,y,n))-(productsum(x,z,n)*productsum(y,z,n)))/((n*productsum(x,x,n))-pow(productsum(x,z,n),2));
    a= (productsum(y,z,n) - (b*productsum(x,z,n)))/n;
    printf("Required linear regression eqaution is : y = %.2fx + %.2f",b,a);
}