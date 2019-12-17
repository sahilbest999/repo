#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
int gd=DETECT,gm;
int x1,y1,x2,y2,shx,shy,ch;
cleardevice();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
printf("Enter x1 = ");
scanf("%d",&x1);
printf("Enter y1 = ");
scanf("%d",&y1);
printf("Enter x2 = ");
scanf("%d",&x2);
printf("Enter y2 = ");
scanf("%d",&y2);
printf("The rectangle before shearing\n");
rectangle(x1,y1,x2,y2);
printf("Enter value for X-Shear = ");
scanf("%d",&shx);
printf("Enter value for Y-Shear = ");
scanf("%d",&shy);
a:printf("1.X-Shear\n2.Y-Shear\n3.Exit\n");
printf("Enter your choice = ");
scanf("%d",&ch);
switch(ch)
{
case 1:
rectangle(x1,y1,x2*shx,y2);
goto a;
break;
case 2:
rectangle(x1,y1,x2,y2*shy);
break;
case 3:
exit(0);
break;
}
getch();
}