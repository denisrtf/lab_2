#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void Dump(double S,double Fault,int n )
{
    printf("S = %lf\n",S);
    printf("fault = %lf\n",Fault);
    printf("Count of steps = %d\n",n);
}
double Funct(double x)
{
    return pow(x,2)*sqrt(1+pow(x,3));
}
double Rectangles(int n,double a,double b)
{
    double h,S,x;
    h=(b-a)/n;
    for(x = a; x <= b ;x = x + h)
    {
     S=S+Funct(x);
    }
    S=S*h;
    return S;
}
double Trapezoidal(int n,double a,double b)
{
   double h,S = 0,x;
   h=(b-a)/n;
   S=Funct(a)+Funct(b);
    for(x = a; x <= b ;x = x + h)
    {
    S=S+Funct(x);
    }
    S=S*h;
    return S;
}
double Simpson(int n,double a,double b)
{
    double h,S = 0,SS = 0;
    int i = 0;
    h=((b-a)/n);
        for(i = 0; i <= n;i++)
        {
            if(i%2 != 0)
            {
              S=S+Funct(a+h*i);
            }
            if(i%2 == 0)
            {
              SS=SS+Funct(a+h*i);
            }
        }

        S=((b-a)/(3*n))*(Funct(a)+4*S+2*SS+Funct(b));
   return S;
}
int main()
{

    int var,n,i,j=1;
    double h,d,x,S=0.0,SS=0.0,a,b;
   while(1)
   {
    printf("Choise method: \n");
    printf("1 - Method of rectangles\n2 - Method of trapezoidal\n3 - Simpson method\n4 - Usual method\n5 - EXIT");
    scanf("%d",&var);
    switch(var)
    {
    case 1:
        printf("Count of steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Rectangles(n,a,b);
               n=n+2;
              }
            SS = Rectangles(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
    case 2:
        printf("Count of steps: \n");
        scanf("%d",&n);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Trapezoidal(n,a,b);
               n=n+2;
              }
            SS = Trapezoidal(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
 case 3:
        do
        {
            printf("Count of steps: \n");
            scanf("%d",&n);
        }
        while(n%2!=0);
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
for(j; j<=2;j++)
        {
              if(j==1)
              {
               S = Simpson(n,a,b);
               n=n+2;
              }
            SS = Simpson(n,a,b);
            if(fabs(S-SS)>0.00001 && fabs(S-SS)<0.001)
            {
                SS = fabs(S-SS);
                Dump(S,SS,n);
                break;
            }
            else
            {
                j=0;
            }
        }
        break;
    case 4:
        printf("lower limit: \n");
        scanf("%lf",&a);
        printf("upper border: \n");
        scanf("%lf",&b);
        S=((2*pow(a,2)*sqrt(2*a))/5)+((2*a*sqrt(a))/3);
        SS=((2*pow(b,2)*sqrt(2*b))/5)+((2*b*sqrt(b))/3);
        S=SS-S;
        printf("S : %lf\n\n",S);
        break;
    case 5:
        return 0;
        break;
    default:
        printf("No one variant\n");
        break;
    }
   }
    return 0;
}
