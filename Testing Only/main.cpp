#include <conio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node* Node;

Node head = NULL;

void insert()
{
	int data_ins;
	Node newnode = (Node)malloc(sizeof(Node));
	cout<<"Enter Data : ";
	cin>>data_ins;
	newnode -> data = data_ins;
	newnode -> next = head; 
	head = newnode;
}
void display()
{
	Node ptr;
	ptr = head;
	int count = 0;
	while(ptr->next!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr = ptr->next;
		count++;
	}
	cout<<"TOTAL NUMBER OF NODES : "<<count<<endl;
	_getch();
}

void delete_(char para[100])
{
	Node ptr,start;
	if(strcmp(para,"start")==0)
	{
		start = head;
		ptr = head;
		while(ptr->next!=NULL)
		{ 
			head = ptr->next;
		}
		head = NULL;
		head = start;
	}
	else if(strcmp(para,"end")==0)
	{
		head = head->next;
	}
	
}

int main()
{
	char key;
	while(1)
	{
		cout<<"1.Insert"<<endl;
		cout<<"2.Delete START"<<endl;
		cout<<"3.Delete END"<<endl;
		cout<<"4.Display"<<endl;
		cout<<"5.Exit"<<endl;
		key=_getch();
		system("CLS");
		if(key=='1')
		insert();
		else if(key=='4')
		display();
		else if(key=='2')
		delete_("start");
		else if(key=='3')
		delete_("end");
		else if(key=='5')
		exit(0);
		
		system("CLS");
	}
	return 0;
}














