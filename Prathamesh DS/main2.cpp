#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;


void pop();
void push();
void display();

int top=-1,len;
char stack[1000],

int main()
{
	cout<<"ENTER AN INFIX OPERATION : ";
}

void push()
{
	if(top==MAX-1)
	{
		cout<<"STACK FULL";
	}
	else
	{
		cout<<"ENTER ELEMENT : ";
		++top;
		cin>>stack[top];
		
	}
}

void pop()
{
	if(top<0)
	{
		cout<<"STACK UNDERFLOW";
	}
	else
	{
		cout<<"ELEMENT DELETED ";
		--top;
	}
}

void display()
{
	system("CLS");
	for(int i=top;i>=0;i--)
	cout<<stack[i]<<endl;
	_getch();
}
