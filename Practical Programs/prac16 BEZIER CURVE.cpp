#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int gd=DETECT,gm,maxx,maxy,i;
float a[4][2];
void d_line(float x2,float y2)
{
line(a[0][0],a[0][1],x2,y2);
a[0][0]=x2;
a[0][1]=y2;
}
bezier(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
float xab,yab,xbc,ybc,xcd,ycd;
float xabc,yabc,xbcd,ybcd;
float xabcd,yabcd;
if(n==0)
{
d_line(xb,yb);
d_line(xc,yc);
d_line(xd,yd);
}
else
{
xab=(a[0][0]+xb)/2;
yab=(a[0][1]+yb)/2;
xbc=(xb+xc)/2;
ybc=(yb+yc)/2;
xcd=(xc+xd)/2;
ycd=(yc+yd)/2;
xabc=(xab+xbc)/2;
yabc=(yab+ybc)/2;
xbcd=(xbc+xcd)/2;
ybcd=(ybc+ycd)/2;
xabcd=(xabc+xbcd)/2;
yabcd=(yabc+ybcd)/2;
n=n-1;
bezier(xab,yab,xabc,yabc,xabcd,yabcd,n);
bezier(xbcd,ybcd,xcd,ycd,xd,yd,n);
}
}
int main()
{
float x,y;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

for(i=0;i<4;i++)
{
printf("Enter the x,y co-ordinates of point %d : ",i+1);
scanf("%f %f",&x,&y);
a[i][0]=x;
a[i][1]=y;
}
bezier(a[1][0],a[1][1],a[2][0],a[2][1],a[3][0],a[3][1],8);
getch();
}