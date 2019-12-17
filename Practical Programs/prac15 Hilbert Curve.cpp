#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
int color=1;
using namespace std;
void move(int &x,int &y,int j,int h)
{
if(j==1)
y=y-h;
else if(j==2)
x=x+h;
else if(j==3)
y=y+h;
else if(j==4)
x=x-h;
lineto(x,y);


if(color==16)
color=1;

setcolor(color);
color++;
}

void hilbert(int &x,int &y,int r,int d,int l,int u,int i,int h)
{
if(i>0)
{
i--;
hilbert(x,y,d,r,u,l,i,h);
move(x,y,r,h);
hilbert(x,y,r,d,l,u,i,h);
move(x,y,d,h);
hilbert(x,y,r,d,l,u,i,h);
move(x,y,l,h);
hilbert(x,y,u,l,d,r,i,h);
}
}
int main()
{
int n,x1,y1;
int x=10,y=10,h=2,r=2,d=3,l=4,u=1;
cout<<"ENTER VALUE OF N : ";cin>>n;
int gm,gd=DETECT;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
moveto(x,y);
hilbert(x,y,r,d,l,u,n,h);
getch();
}