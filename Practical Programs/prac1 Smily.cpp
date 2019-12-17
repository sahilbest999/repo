#include<conio.h>
#include<stdio.h>
#include<graphics.h>

int main()
{
int gd=DETECT,gm;
cleardevice();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setcolor(RED);
settextstyle(3,0,5);
outtextxy(170,1,"WELCOME TO CG");
setcolor(WHITE);
circle(320,185,70);
floodfill(320,185,RED);
circle(300,160,10);
circle(300,160,5);
circle(340,160,10);
circle(340,160,5);
line(315,200,325,200);
line(315,200,320,180);
line(320,180,325,200);
arc(320,200,210,330,30);
getch();
closegraph();
}
Program for vehicle
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
int main()
{
int gd=DETECT,gm;
cleardevice();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setcolor(WHITE);
rectangle(190,270,370,400);
circle(230,433,30);
circle(330,433,30);
getch();
closegraph();
}


