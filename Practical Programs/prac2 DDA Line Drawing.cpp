#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
int gd=0,gm,i;
 float x,y,x1,y1,x2,y2,length,dx,dy;
 cleardevice();
 cout<<"ENTER X1 : ";cin>>x1;
 cout<<"ENTER Y1 : ";cin>>y1;
 cout<<"ENTER X2 : ";cin>>x2;
 cout<<"ENTER Y2 : ";cin>>y2;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 dx=abs(x2-x1);
 dy=abs(y2-y1);
 if(dx>=dy)
 length=dx;
 else
 length=dy;
 dx=(x2-x1)/length;
 dy=(y2-y1)/length;

 x=x1+0.5;
 y=y1+0.5;
 i=1;
  while(i<=length)
  {
   putpixel(x,y,WHITE);
   x=x+dx;
   y=y+dy;
   i++;
   }
getch();
closegraph();
}
