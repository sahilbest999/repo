#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
int gd=DETECT,gm;
int x1,y1,x2,y2,a,b,c,d,tx,ty,sx,sy;
clrscr();
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
printf("Enter the x co-ordinate of the lower left bottom corner of rectangle=\n");
scanf("%d",&x1);
printf("Enter the y co-ordinate of the lower left bottom corner of rectangle=\n");
scanf("%d",&y1);
printf("Enter the x co-ordinate of the upper right corner of rectangle=\n");
scanf("%d",&x2);
printf("Enter the y co-ordinate of the upper right corner of rectangle=\n");
scanf("%d",&y2);
printf("The rectangle before the transalation=\n");
rectangle(x1,y1,x2,y2);
printf("Enter the translation factor towords x direction=\n");
scanf("%d",&tx);
printf("Enter the translation factor towords y direction=\n");
scanf("%d",&ty);
a=x1+tx;
b=y1+ty;
c=x2+tx;
d=y2+ty;
printf("The rectangle after the transalation=\n");
rectangle(a,b,c,d);

printf("Enter the x co-ordinate of the lower left bottom corner of rectangle=\n");
scanf("%d",&x1);
printf("Enter the y co-ordinate of the lower left bottom corner of rectangle=\n");
scanf("%d",&y1);
printf("Enter the x co-ordinate of the upper right corner of rectangle=\n");
scanf("%d",&x2);
printf("Enter the y co-ordinate of the upper right corner of rectangle=\n");
scanf("%d",&y2);
printf("The rectangle before the scaling=\n");
rectangle(x1,y1,x2,y2);
printf("Enter the scaling factor towords x direction=\n");
scanf("%d",&sx);
printf("Enter the scaling factor towords y direction=\n");
scanf("%d",&sy);
a=x1*sx;
b=y1*sy;
c=x2*sx;
d=y2*sy;
printf("The rectangle after the scaling=\n");
rectangle(a,b,c,d);
getch();
closegraph();
}