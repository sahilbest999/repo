#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void flood_fill4(int x,int y,int newcolor,int oldcolor)
{
int c;
delay(10);
c=getpixel(x,y);
if(c==oldcolor)
{
setcolor(newcolor);
putpixel(x,y,newcolor);
flood_fill4(x+1,y,newcolor,oldcolor);
flood_fill4(x,y+1,newcolor,oldcolor);
flood_fill4(x-1,y,newcolor,oldcolor);
flood_fill4(x,y-1,newcolor,oldcolor);
}
}
int main()
{
int gd=DETECT,gm;
cleardevice();
initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
rectangle(250,200,300,250);
flood_fill4(251,201,4,0);
getch();
closegraph();
}


