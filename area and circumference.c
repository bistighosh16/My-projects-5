#include<stdio.h>
#include<conin.h>
void main()
{
    float r,pi,area,cir;
    pi=3.14;
    area=0.0;
    cir=0.0;
    clrscr();
    printf("\n enter the value of r");
    scanf("%f", r);
    area=pi*r^2;
    printf("\n the result is %f", area);
    cir=2*pi*r;
    printf("\n the reslut is %f", cir);
    getch();
}