#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int gd=DETECT,gm;
 int tx,ty,tz,sx,sy,a,b,a1,b1,c,m,n,m1,n1,z,sz;
int main()
{
 int ch;
 b:
 printf("********3D TRANSFORMATIONS*****\n");
 printf("1.Translation\n");
 printf("2.Scaling\n");
 printf("Enter your choice = ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  bar3d(200,300,400,250,20,1);
  printf("Enter tx = ");
  scanf("%d",&tx);
  printf("Enter ty = ");
  scanf("%d",&ty);
  a=200+tx;
  b=300+ty;
  a1=400+tx;
  b1=250+ty;
  bar3d(a,b,a1,b1,20,1);
  printf("\n");
  goto b;
  break;
  case 2:
 initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  bar3d(200,300,400,250,20,1);
   printf("Enter sx = ");
  scanf("%d",&sx);
  printf("Enter sy = ");
  scanf("%d",&sy);
  printf("Enter sz = ");
  scanf("%d",&sz);
  m=200*sx;
  n=300*sy;
  m1=400*sx;
  n1=250*sy;
   z=20*sz;
  bar3d(m,n,m1,n1,z,1);
  break;
  } getch();
  }