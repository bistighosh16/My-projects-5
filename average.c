#include <stdio.h>
#include <conin.h>
void main(){
    int physics,chemistry,biology,average;
    average=0;
    clrscr();
    printf("\n enter the value of physics");
    scanf("%d",&physics);
     printf("\n enter the value of chemistry");
    scanf("%d",&chemistry);
     printf("\n enter the value of biology");
    scanf("%d",&biology);
    average=(physics+chemistry+biology)/3;
    printf("\n the result is %d", average);
    getch();
}+


