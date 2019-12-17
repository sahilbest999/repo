#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int box_x1=0,box_y1=0,box_x2=450,box_y2=479;
int p_dx=1,p_dy=1,p_x1=222 , p_y1=237,p_x2=227 , p_y2=237 ,p_xsize=p_x2-p_x1,p_ysize=p_y2-p_y1;
int f_x=100,f_y=100; float f_r=3.8,fruitt=1;
int start=0,snake_direction; //snake_direction [1=UP , 2=DOWN , 3=LEFT , 4=RIGHT] //snake direction is a non-used variable means it is has no function to do
int lastkey,snakespeed=60,debug=1,prevkey;  //LESSER THE SNAKE SPEED VALUE FASTER THE SNAKE
int temp_x1,temp_x2,temp_x3,temp_x4,temp_y1,temp_y2,temp_y3,temp_y4;
int f_color=YELLOW;

void player_up();
void player_down();
void player_left();
void player_right();
void box();
void check_snake_eaten_food();
void fruit();
void player();
void update();
void gameover();


void box()
{
setcolor(WHITE);
rectangle(box_x1,box_y1,box_x2,box_y2);
}

void check_snake_eaten_food()
{
if((getpixel(p_x2+1,p_y2)==f_color)&&snake_direction==4)
{
//
p_x1=p_x1-p_xsize;
fruitt=0;
cleardevice();
}

if((getpixel(p_x2+1,p_y2)==f_color)&&snake_direction==3)
{
//
p_x1=p_x1+p_xsize;
fruitt=0;
cleardevice();
}

if((getpixel(p_x2,p_y2+1)==f_color)&&snake_direction==2)
{
//
p_y1=p_y1-p_xsize;
fruitt=0;
cleardevice();
}

if((getpixel(p_x2,p_y2+1)==f_color)&&snake_direction==1)
{
//
p_y1=p_y1+p_xsize;
fruitt=0;
cleardevice();
}
}
void fruit()
{
if(start==1&&fruitt==1)
{
setcolor(f_color);
setfillstyle(SOLID_FILL,f_color);
circle(f_x,f_y,f_r);
floodfill(f_x,f_y,f_color);
start=0;
}
}
void player()
{
//setcolor(WHITE);
line(p_x1,p_y1,p_x2,p_y2);
//setfillstyle(SOLID_FILL,RED);
//floodfill(p_x1+1,p_y1+1,WHITE);
}

void player_up()
{
if(prevkey!='s')
{
snake_direction=1;
p_y1=p_y1-1;
p_y2=p_y2-1;
lastkey='w';
if(debug==1)
{
if(p_y1<=box_y1)
{
p_y1=box_y1+1;
p_y2=p_y1+5;
}
}
else
{
	if(p_y1<=box_y1)
	gameover();
}
}
else if(prevkey=='s')
{
	player_down();
	prevkey='s';
}
}

void player_down()
{
if(prevkey!='w')
{
snake_direction=2;
p_y1=p_y1+1;
p_y2=p_y2+1;
lastkey='s';
if(debug==1)
{
if(p_y1>=getmaxy())
{
p_y1=getmaxy()-1;
p_y2=p_y1-5;
}
}
else
{
	if(p_y1>=getmaxy())
	gameover();
}
}
else if(prevkey=='w')
{
	player_up();
	prevkey='w';
}
}

void player_left()
{
if(prevkey!='d')
{
p_x1=p_x1-p_dx;
p_x2=p_x2-p_dx;
snake_direction=3;
lastkey='a';
if(debug==1)
{
if(p_x1<=box_x1)
{
p_x1=box_x1+1;
p_x2=p_x1+5;
}
}
else
{
	if(p_x1<=box_x1)
	gameover();
}
}
else if(prevkey=='d')
{
	player_right();
	prevkey='d';
}
}


void player_right()
{
if(prevkey!='a')
{
p_x1=p_x1+p_dx;
p_x2=p_x2+p_dx;
snake_direction=4;
lastkey='d';
if(debug==1)
{
if(p_x2>=box_x2-1)
{
p_x1=box_x2-1;
p_x2=p_x1-5;
}
}
else
{
	if(p_x2>=box_x2-1)
	gameover();
}
}
else if(prevkey=='a')
{
	player_left();
	prevkey='a';
}
}

void update()
{
cleardevice();
fruit();
check_snake_eaten_food();
player();
box();
}
void gameover()
{
 cleardevice();
 box();
 outtextxy((box_x2/2)-45,(getmaxy()/2),"GAME OVER");
 getch();
 exit(1);
}
int main()
{
int gd=DETECT,gm,key;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI\\");
update();
key=getch();
lastkey=key;
while(key!=27) //27 = ESC
{
if(kbhit())
{
	if(prevkey!=lastkey)
	{
		prevkey=key;
	}
key=getch();
if(key=='w'||key=='a'||key=='s'||key=='d')
{
lastkey=key;
}
system("CLS");
cout<<"PREV KEY : "<<char(prevkey)<<endl<<"KEY      : "<<char(lastkey)<<endl;

}
start=1;
if(key=='p')
{
debug=1;
}
if(lastkey=='w')
{
player_up();
delay(snakespeed);
update();
}
if(lastkey=='a')
{
player_left();
delay(snakespeed);
update();
}
if(lastkey=='s')
{
player_down();
delay(snakespeed);
update();
}
if(lastkey=='d')
{
player_right();
delay(snakespeed);
update();
}
if(key==27)
{
exit(-1);
}
}
return main();
}
