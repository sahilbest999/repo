#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
	int gm,gd=DETECT;
	int i;
	int xmid,ymid,x1,x2,y1,y2,x,y,x3,y3;
	initgraph(&gd,&gm,"c:\\turboc3\\BGI");
           printf("Enter first points");
	scanf("%d%d",&x1,&y1);
	printf("Enter second points");
	scanf("%d%d",&x2,&y2);
	printf("Enter third points");
	scanf("%d%d",&x3,&y3);
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;
	line(0,ymid,getmaxx(),ymid);
	line(xmid,0,xmid,getmaxy());
	delay(1500);
          line(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
	line(x2+xmid,ymid-y2,x3+xmid,ymid-y3);
	line(x3+xmid,ymid-y3,x1+xmid,ymid-y1);
 x1=-x1;x2=-x2;x3=-x3;
           line(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
	line(x2+xmid,ymid-y2,x3+xmid,ymid-y3);
	line(x3+xmid,ymid-y3,x1+xmid,ymid-y1);
              getch();
	closegraph();
}