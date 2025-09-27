#include<studio.h>
#include<conin.h>
void main()
{
int l,b,area,perimeter;
area=0;
perimeter=0;
clrscr();
printf("\n enter the value of l");
scanf("%d",&l);
printf("enter the value of b");
scanf("%d", &b);
area=l*b;
printf("\n the result is #%d", area);
perimeter=2*(l+b);
printf("\n the result id %d", perimeter);
getch();
}
