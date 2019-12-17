#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_MOVES 9

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77

struct box
{
	bool present=false;
	char ans=' ';
};

box a,b,c,d,e,f,g,h,i;

string check_win();
void display();
void exit_(string winner);
void ans();


int main()
{
	int key,moves=0;
	string winner="TIE";
	while(moves!=MAX_MOVES)
	{
	ans();
	winner=check_win();
	moves++;
	
	if(winner!="TIE")
	break;
	}	
	
	exit_(winner);
	return 0;
}

void exit_(string winner)
{
	system("CLS");
	display();
	if(winner!="TIE")
	cout<<endl<<"WINNER - "<<winner;
	else
	cout<<"AWW MAN THAT'S A TIE"<<endl;
	
	_getch();
}

string check_win()
{
	string winner="LAVDA";
	
	//PLAYER 1 WINNING PATTERNS

	if(a.ans=='1')
	if(b.ans=='1')
	if(c.ans=='1')
	winner="PLAYER 1";
	
	if(d.ans=='1')
	if(e.ans=='1')
	if(f.ans=='1')
	winner="PLAYER 1";
	
	if(g.ans=='1')
	if(h.ans=='1')
	if(i.ans=='1')
	winner="PLAYER 1";
	
	if(a.ans=='1')
	if(d.ans=='1')
	if(g.ans=='1')
	winner="PLAYER 1";
	
	if(b.ans=='1')
	if(e.ans=='1')
	if(h.ans=='1')
	winner="PLAYER 1";
	
	if(c.ans=='1')
	if(f.ans=='1')
	if(i.ans=='1')
	winner="PLAYER 1";
	
	if(a.ans=='1')
	if(e.ans=='1')
	if(i.ans=='1')
	winner="PLAYER 1";
	
	if(c.ans=='1')
	if(e.ans=='1')
	if(g.ans=='1')
	winner="PLAYER 1";
	
	
	//PLAYER 2 WINNING PATTERNS
		
	if(a.ans=='0')
	if(b.ans=='0')
	if(c.ans=='0')
	winner="PLAYER 2";
	
	if(d.ans=='0')
	if(e.ans=='0')
	if(f.ans=='0')
	winner="PLAYER 2";
	
	if(g.ans=='0')
	if(h.ans=='0')
	if(i.ans=='0')
	winner="PLAYER 2";
	
	if(a.ans=='0')
	if(d.ans=='0')
	if(g.ans=='0')
	winner="PLAYER 2";
	
	if(b.ans=='0')
	if(e.ans=='0')
	if(h.ans=='0')
	winner="PLAYER 2";
	
	if(c.ans=='0')
	if(f.ans=='0')
	if(i.ans=='0')
	winner="PLAYER 2";
	
	if(a.ans=='0')
	if(e.ans=='0')
	if(i.ans=='0')
	winner="PLAYER 2";
	
	if(c.ans=='0')
	if(e.ans=='0')
	if(g.ans=='0')
	winner="PLAYER 2";

	return winner;
}

void display()
{
	system("CLS");
	cout<<" "<<a.ans<<"|"<<" "<<b.ans<<"|"<<" "<<c.ans<<endl;
	cout<<"--------"<<endl;
	cout<<" "<<d.ans<<"|"<<" "<<e.ans<<"|"<<" "<<f.ans<<endl;
	cout<<"--------"<<endl;
	cout<<" "<<g.ans<<"|"<<" "<<h.ans<<"|"<<" "<<i.ans<<endl;
}

void ans()
{
	char key=NULL;
	int location=1;
	
	while(key!=27)
	{
		
		if(location==1)
		{
			cout<<"-->"<<" "<<a.ans<<"|"<<" "<<b.ans<<"|"<<" "<<c.ans<<endl;
			cout<<"    --------"<<endl;
			cout<<" "<<d.ans<<"|"<<" "<<e.ans<<"|"<<" "<<f.ans<<endl;
			cout<<"    --------"<<endl;
			cout<<" "<<g.ans<<"|"<<" "<<h.ans<<"|"<<" "<<i.ans<<endl;
		}
		else if(location==2)
		{
			cout<<" "<<a.ans<<"|"<<" "<<b.ans<<"|"<<" "<<c.ans<<endl;
			cout<<"    --------"<<endl;
			cout<<"-->"<<" "<<d.ans<<"|"<<" "<<e.ans<<"|"<<" "<<f.ans<<endl;
			cout<<"    --------"<<endl;
			cout<<" "<<g.ans<<"|"<<" "<<h.ans<<"|"<<" "<<i.ans<<endl;
		}
		else if(location==3)
		{
			cout<<" "<<a.ans<<"|"<<" "<<b.ans<<"|"<<" "<<c.ans<<endl;
			cout<<"    --------"<<endl;
			cout<<" "<<d.ans<<"|"<<" "<<e.ans<<"|"<<" "<<f.ans<<endl;
			cout<<"    --------"<<endl;
			cout<<"-->"<<" "<<g.ans<<"|"<<" "<<h.ans<<"|"<<" "<<i.ans<<endl;
		}
		else if(location==4)
		{
			
		}
		else if(location==5)
		{
			
		}
		else if(location==6)
		{
			
		}
		else if(location==7)
		{
			
		}
		else if(location==8)
		{
			
		}
		else if(location==9)
		{
			
		}
		
	}
		
}
