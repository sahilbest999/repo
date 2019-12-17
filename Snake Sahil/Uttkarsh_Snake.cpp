#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

using namespace std;

int x1=100,y1=200,x2=200,y2=200,length=100,dflag=1;
char input,lastinput;

void border()
{
int bx1=getmaxx(),by1=getmaxy();
setcolor(WHITE);
rectangle(2,2,bx1-2,by1-2);
}

void up()
{
 --y2;
 --y1;
}

void left()
{
  --x2;
  --x1;
}

void down()
{
   ++y2;
   ++y1;
}
void turn_down()
{  if(dflag==1)
  {
  int tx2=x2,tx1=x1,i;
  int ty_2=y2,ty2=y2;

   for(i=0;i<length-1;i++)
      {
	   tx1=tx1+1;
	  line(tx1,y1,tx2,ty2);
	  
	   ty_2=ty_2+1;
	
	  line(tx2,ty2,tx2,ty_2);
	  
	  delay(30);
	  
	 cleardevice();
      }
   x1=tx2;
   y1=y2;
   y2=ty_2;
   dflag=0;
   down();
  }
  else
  {down();}
}

void right()
{
   ++x2;
   ++x1;
}

void player()
{
	line(x1,y1,x2,y2);
}

void refresh()
{
cleardevice();
player();
delay(30);
border();
}

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
length=100;
border();
setcolor(GREEN);ine(x1,y1,x2,y2);
input = getch();
lastinput=input;

while(input!=27) //27=ESC
{
if(kbhit())
{
input=getch();
if(input=='w'||input=='a'||input=='s'||input=='d')
{
lastinput=input;
}
}

 if(lastinput=='w')
 {
 dflag=1;
 up();
 refresh();
 }

 if(lastinput=='a')
 {
 dflag=1;
 left();
 refresh();
 }

 if(lastinput=='s')
 {
 turn_down();
 refresh();
 }

 if(lastinput=='d')
 {
 dflag=1;
 right();
 refresh();
 }

 if(input==27)
 {
 exit(-1);
 }
}
}
