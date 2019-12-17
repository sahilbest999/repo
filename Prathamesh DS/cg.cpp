#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int bx=319,by=239,r=20,tx=5,ty=5,color=1,hit=0,pattern=1;

void check_hit()
{
if((bx-r) <= 0)
{
tx=5;
hit=1;
}

if((by-r) <= 0)
{
ty=5;
hit=1;
}

if((bx+r) >= getmaxx())
{
tx=-5;
hit=1;
}

if((by+r) >= getmaxy())
{
ty=-5;
hit=1;
}

}

void box()
{
setcolor(WHITE);
rectangle(0,0,getmaxx(),getmaxy());
}
void ball()
{
srand(time(0));
check_hit();
bx+=tx;
by+=ty;
circle(bx,by,r);
if(hit==1)
{
color=1+rand()%16;
hit=0;
Beep(2000,75);
}
if(r>0)
{
setfillstyle(pattern,color);
floodfill(bx,by,WHITE);
}
}

void update()
{
cleardevice();
box();
ball();
}

int main()
{
int gd=0,gm;
char key;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI\\");
update();
getch();

while(key!=27)
{
update();
if(kbhit())
{
key=getch();
}
if(key=='g')
{
r++;
Beep(2000,75);
key=1;
}

if(key=='h')
{
r--;
Beep(2000,75);
key=1;
if(r<0)
r=0;

}
if(key=='j')
{
pattern++;
Beep(2000,75);
key=1;

if(pattern==11)
pattern=1;

}
Sleep(30);
}
exit(0);
return 0;
}
