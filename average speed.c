#include<stdio.h>
#include<conin.h>
void main()
{
    float dist,time,avespeed;
    avespeed=0;
    clrscr();
    printf("\n enter the value of dist");
    scanf("%f", dist);
    printf("\n enter the value of time");
    scanf("%f", time);
    avespeed=dist/time;
    printf("\n the result is %f", avespeed);
    getch();
}