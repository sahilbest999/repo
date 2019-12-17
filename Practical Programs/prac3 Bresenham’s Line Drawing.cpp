#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;
int main()
{
int gd=0,gm;
 float x,y,x1,y1,x2,y2,Pk,dx,dy,i;
 
 cout<<"ENTER X1 : ";cin>>x1;
 cout<<"ENTER Y1 : ";cin>>y1;
 cout<<"ENTER X2 : ";cin>>x2;
 cout<<"ENTER Y2 : ";cin>>y2;

 dx=(x2-x1);
 dy=(y2-y1);
 
 x=x1;
 y=y1;
 
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 
 putpixel(x,y,WHITE);
 Pk=(2*dy)-dx;
 
 for(i=0;i<dx;i++)
 {
 	
 if(Pk<0)			//THIS IS DECISION SECTION
  {
  x=x+1;
  y=y;
  Pk=Pk+(2*dy);
  }
  else if(Pk>=0)
  {
  x=x+1;
  y=y+1;
  Pk=Pk+2*dy-2*dx;
  }
  
  putpixel(x,y,WHITE);
  }
  
  getch();
closegraph();
}

