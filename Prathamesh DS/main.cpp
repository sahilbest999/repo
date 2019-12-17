#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 5

void pop();
void push();
void display();

int stack[MAX],top=-1;

int main()
{
int ch;
	
	while(1)	//infinite loop, will end when choice will be 4
	{
		printf("\n*** Stack Menu ***");
		printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
		printf("\n\nEnter your choice(1-4):");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			
			default: printf("\nWrong Choice!!");
		}
}
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
	for(int i=top;i<=0;i--)
	cout<<stack[i]<<endl;
}
