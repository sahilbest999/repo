#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
int gd = DETECT,gm;
int i;
int x2,y2,x1,y1,x,y,xn,yn;
double r11,r12,r21,r22,th;
cleardevice();
printf("Enter the x,y coordinates of 2 line end points:");
printf("\n x1,y1,x2,y2 =");
scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
printf("Original line Before Rotation:");
line(x1,y1,x2,y2);
printf("\n\n\n[ Enter the angle of rotation:");
scanf("%lf",&th);
r11=cos((th*3.1428)/180);
r12=sin((th*3.1428)/180);
xn=((x2*r11)-(y2*r12));
yn=((x2*r12)+(y2*r11));
printf("\n Line after rotation = ");
line(x1,y1,xn,yn);
getch();
closegraph();
}
