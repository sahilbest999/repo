#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <iostream>
using namespace std;

int loc_x,loc_y;
int main()
{
int gd=DETECT,gm;
int x,y,r;
float pi=3.14;
cleardevice();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
cout<<"Enter the X-Coordinate : ";cin>>loc_x;
cout<<"Enter the Y-Coordinate : ";cin>>loc_y;
cout<<"Enter the value of the radius : ";cin>>r;
x=0;
y=r;
pi=3-2*r;

do
{
putpixel(loc_x+x,loc_y+y,15);
putpixel(loc_y+y,loc_x+x,15);
putpixel(loc_x+x,loc_y-y,15);
putpixel(loc_y+y,loc_x-x,15);
putpixel(loc_x-x,loc_y-y,15);
putpixel(loc_x-x,loc_y+y,15);
putpixel(loc_y-y,loc_x+x,15);
putpixel(loc_y-y,loc_x-x,15);
if(pi<0)
{
x=x+1;
pi=pi+4*x+6;
}
else if(pi>=0)
{
x=x+1;
pi=pi+4*(x-y)+10;
y=y-1;
}
}
while(x<y);
getch();
closegraph();
}