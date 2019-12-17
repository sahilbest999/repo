#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

#define ARROW_UP 72
#define ARROW_DOWN 80
#define SPACE 32
int select_option(int);
void price_check(int,int);

int cart_loop;
int item_price_cart[1000];
char item_name_cart[1000][1000];
char first_name[300],middle_name[1000],last_name[300],address[1000],email[1000];
int phone,debit;

void create_bill(float);
void verify_customer();
void view_cart(int);
void get_info();
void display_info();

int main()
{	
	int menu,loc,i,total;
	system("COLOR F0");
	start :
	system("CLS");
	cart_loop=0;
	total=0;
	menu=1;
	loc=select_option(menu); //START
	if(loc==2)
	{
	view_cart(total);
	_getch();
	goto start;
	}
	++menu;
	product_selection:
	loc=select_option(menu); //PRODUCT SELECTION
	if(cart_loop==0)
	{
		system("CLS");
		printf("SELECT ATLEST ONE PRODUCT TO CONTINUE...(PRESS SPACE TO SELECT PRODUCT)\n\n");
		printf("YOU WILL BE REDIRECTED TO THE PRODUCT SELECTION MENU IN 3 SECONDS");
		Sleep(3000);
		system("CLS");
		goto product_selection;
	}
	++menu;
	loc=select_option(menu);
	++menu;
	
	for(i=0;i<cart_loop;i++)
	{
		total=total+item_price_cart[i];
	}
	
	if(loc==1)
	{
	view_cart(total);
	_getch();
	system("CLS");
	}
	get_info_again :
		
	get_info();
	loc=select_option(menu);
	if(loc==2)
	goto get_info_again;
	++menu;
	system("CLS");
	create_bill(total);
}


int select_option(int menu)
		{
			char key='1',a[500],b[500],c[500],d[500],e[500],f[500],g[500],h[500],i[500],j[500],item_name[1000];
			int loc=1,sound_hz=2100,sound_time=70;
				while(key!=13)
				{
					if(menu==1)
					{
						strcpy(a, "SHOP");
						strcpy(b, "CART");
						if(loc==1)
						{
						printf("1) %s <-----\n",a);
						printf("2) %s \n",b);
						}
						else if(loc==2)
						{
						printf("1) %s \n",a);
						printf("2) %s <-----\n",b);
						}
						key=_getch();
				
						if(key!=72 && key!=80)
						Beep(sound_hz,sound_time);
						system("CLS");
						if(key==ARROW_UP)
						{
							--loc;
							if(loc<1)
							loc=2;
						}
						else if(key==ARROW_DOWN)
						{
							++loc;
							if(loc>2)
							loc=1;
						}
					}
					else if(menu==2)
					{
						strcpy(a,"OnePlus 7 Pro");
						strcpy(b,"iPhone 11");
						strcpy(c,"Xaiomi Mi A3");
						strcpy(d,"Nokia 3310");
						strcpy(e,"Redmi K20Pro");
						strcpy(f,"Asus ROG phone 2");
						strcpy(g,"Google Pixel 3");
						strcpy(h,"Samsung S10 Plus");
						strcpy(i,"Samsung Note 10");
						strcpy(j,"Redmi Note 7 Pro");
						
						
						if(loc==1)
						{
						printf("1) %s <-----\n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,a);
						}
						else if(loc==2)
						{
						printf("1) %s \n",a);
						printf("2) %s <-----\n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,b);
						}
						else if(loc==3)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s <-----\n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,c);
						}
						else if(loc==4)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s <-----\n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,d);
						}
						else if(loc==5)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s <-----\n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,e);
						}
						else if(loc==6)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s <-----\n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,f);
						}
						else if(loc==7)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s <-----\n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,g);
						}
						else if(loc==8)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s <-----\n",h);
						printf("9) %s \n",i);
						printf("10) %s \n",j);
						strcpy(item_name,h);
						}
						else if(loc==9)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s <-----\n",i);
						printf("10) %s \n",j);
						strcpy(item_name,i);
						}
						else if(loc==10)
						{
						printf("1) %s \n",a);
						printf("2) %s \n",b);
						printf("3) %s \n",c);
						printf("4) %s \n",d);
						printf("5) %s \n",e);
						printf("6) %s \n",f);
						printf("7) %s \n",g);
						printf("8) %s \n",h);
						printf("9) %s \n",i);
						printf("10) %s <-----\n",j);
						strcpy(item_name,j);
						}
						key=_getch();
				
						if(key!=72 && key!=80)
						Beep(sound_hz,sound_time);
						system("CLS");
						
						if(key==ARROW_UP)
						{
							--loc;
							if(loc<1)
							loc=10;
						}
						else if(key==ARROW_DOWN)
						{
							++loc;
							if(loc>10)
							loc=1;
						}
						else if(key==SPACE)
						{
						  strcpy(item_name_cart[cart_loop],item_name);
						  price_check(menu,loc);
						}
					}
					else if(menu==3)
					{
						strcpy(a,"YES");
						strcpy(b,"NO");
						strcpy(c,"DO YOU WANT TO VIEW YOUR CART ?");
						
						if(loc==1)
						{
							printf("%s\n\n",c);
							printf("%s <-----\n",a);
							printf("%s",b);
						}
						else if(loc==2)
						{
							printf("%s\n\n",c);
							printf("%s \n",a);
							printf("%s <-----\n",b);
						}
						
						key=_getch();
				
						if(key!=72 && key!=80)
						Beep(sound_hz,sound_time);
						system("CLS");
						
						if(key==ARROW_UP)
						{
							--loc;
							if(loc<1)
							loc=2;
						}
						else if(key==ARROW_DOWN)
						{
							++loc;
							if(loc>2)
							loc=1;
						}
						
					}
					else if(menu==4)
					{
						display_info();
						strcpy(a,"YES");
						strcpy(b,"NO");
						strcpy(c,"IS THE DISPLAYED INFORMATION CORRECT ?");
						
						if(loc==1)
						{
							printf("\n\n%s\n\n",c);
							printf("%s <-----\n",a);
							printf("%s",b);
						}
						else if(loc==2)
						{
							printf("\n\n%s\n\n",c);
							printf("%s \n",a);
							printf("%s <-----\n",b);
						}
						
						key=_getch();
				
						if(key!=72 && key!=80)
						Beep(sound_hz,sound_time);
						system("CLS");
						
						if(key==ARROW_UP)
						{
							--loc;
							if(loc<1)
							loc=2;
						}
						else if(key==ARROW_DOWN)
						{
							++loc;
							if(loc>2)
							loc=1;
						}
						
					}
					
				}
				return loc;
			}
				
void price_check(int menu,int loc)
	{
		int price;
		
		if(menu==2)
		{
		if(loc==1)
		price=48000;
		else if(loc==2)
		price=64000;
		else if(loc==3)
		price=12000;
		else if(loc==4)
		price=3179;
		else if(loc==5)
		price=23000;
		else if(loc==6)
		price=38000;
		else if(loc==7)
		price=43000;
		else if(loc==8)
		price=74000;
		else if(loc==9)
		price=70000;
		else if(loc==10)
		price=15000;
		}
		
		item_price_cart[cart_loop]=price;
		++cart_loop;
	}
	
void view_cart(int total)
{
	int i;
	if(cart_loop>0)
	{
	for(i=0;i<cart_loop;i++)	//RUN THIS LOOP TO GET CART PRICE OR PRODUCT INFORMATION
	{
		printf("ITEM %d - \n",i+1);
		printf("%s - ",item_name_cart[i]);
		printf("%d Rs.\n\n",item_price_cart[i]);
	}
	}
	else
	{
		printf("NO ITEMS SELECTED\n\n");
	}
	printf("TOTAL - %d Rs.",total);
}


void get_info()
{
	printf("ENTER YOUR FIRST NAME : ");
	scanf("%s",&first_name);
	printf("ENTER YOUR MIDDLE NAME : ");
	scanf("%s",&middle_name);
	printf("ENTER YOUR LAST NAME : ");
	scanf("%s",&last_name);
	printf("ENTER YOUR PHONE NUMBER : ");
	scanf("%s",&phone);
	printf("ENTER YOUR EMAIL : ");
	scanf("%s",&email);
	printf("ENTER YOUR ADDRESS : ");
	scanf("%s",&address);
	
	strcpy(first_name,strupr(first_name));
	strcpy(middle_name,strupr(middle_name));
	strcpy(last_name,strupr(last_name));
	strcpy(email,strupr(email));
	strcpy(address,strupr(address));
	system("CLS");
}

void display_info()
{
	printf("NAME : %s %s %s\n",first_name,middle_name,last_name);
	printf("PHONE NUMBER : %d\n",phone);
	printf("EMAIL : %s\n",email);
	printf("ADDRESS: %s\n",address);
}

void create_bill(float total)
{
	int i;
	float gst=14;
	FILE *bill;
	total=(gst*total/100)+total;

	bill=fopen("bill_inlc_gst.txt","a+");
	if(bill==NULL)
	printf("FILE UNABLE TO CREATE\n");
	fprintf(bill,"---------------------------------------------------------------------------------------------------------\n");
	fprintf(bill,"NAME : %s %s %s\nPHONE NUMBER : %d\nEMAIL : %s\nADDRESS : %s\n\nPURCHASED ITEMS - \n\n",first_name,middle_name,last_name,phone,email,address);
	
	for(i=0;i<cart_loop;i++)
	{
	fprintf(bill,"%d) %s - %d Rs.\n",i+1,item_name_cart[i],item_price_cart[i]);
	}
	fprintf(bill,"\nTOTAL INCLUDING GST - %f",total);
	fprintf(bill,"\n\n\n");
	fclose(bill);
	
	printf("BILL SUCCESSFULLY CREATED");
}
