#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h>  

#define ARROW_UP 72
#define ARROW_DOWN 80

void sort(int);
void displaysort(int [],int);	
void selection(int [],int);					// 1
void bubble(int [],int);					// 2
void insertion(int [],int);					// 3
void radix(int [],int);						// 4
int select_option();
				
int main()
{
	int ch;
	char key;
	system("COLOR F0");
	select :
		
	ch=select_option();
	
	for(;;)
	{
	switch(ch)
	{
		case 1:		sort(1);	
		break;
		case 2:		sort(2);	
		break;			
		case 3:		sort(3);
		break;
		case 4:		sort(4);
		break;
		case 5:		exit(1);
		break;
		
		default:
		printf("Enter a valid choice");
	}
	goto select;
	}
	return 0;
}

//**************************************************  SORT  *************************************************//
void sort(int choice)
{
	int a[10000],i,j,n;
	
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	
	for(i=0; i<n ;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	system("cls");
	if(choice == 1)
	{
		selection(a,n);
	}
	else if(choice == 2)
	{
		bubble(a,n);
	}
	else if(choice == 3)
	{
		insertion(a,n);
	}
	else if(choice == 4)
	{
		radix(a,n);
	}
}

// *******************************************  SELECTION SORT  *********************************************//
void selection(int a[],int n)
{
	int i,j,temp,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		for(k=0;k<n;k++)					  
		{									// Done to display the PASSES !!
			printf("%d\t",a[k]);			
		}									
		printf("\n\n");						
	}
	displaysort(a,n);
}

//**********************************************  BUBBLE SORT  **********************************************//
void bubble(int a[],int n)
{
int k, i, temp,j;

	for (j = 0; j <= n - 1; j++)
	{
		for (i = 0; i <= n - 2; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
		for(k=0;k<n;k++)					  
		{									// Done to display the PASSES !!
			printf("%d\t",a[k]);			
		}									
		printf("\n\n");	
	}
	displaysort(a,n);
}

//*********************************************  INCERTION SORT  *******************************************//
void insertion(int a[],int n)
{
	int j, i, pos, temp, value, d, k;

	for (i = 1; i <= n - 1; i++)
	{
		for (j = 0; j < i; j++)
		{
			if(a[i] < a[j])
			{
				value = a[i];
				pos = j;
				for (k = i; k > j; k--)
				{
					a[k] = a[k - 1];
				}
				a[j] = value;
			}
		}
		for (d = 0; d < n; d++)
		{
			printf("%d\t",a[d]);
		}
		printf("\n\n");
	}
	displaysort(a,n);
}

//********************************************  RADIX SORT  ************************************************//
void radix(int a[],int n)
{
	int b[23], k, i, j, temp, d=0;

for (i = 0; i < n ; i++)
{
	b[i] = a[i];
}

while (d != 3)
{
	for (i = 0; i < n ; i++)
	{
		for (j = i+1; j < n ; j++)
		{
			if ((b[i] % 10) > (b[j] % 10))
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	for (i = 0; i < n ; i++)
	{
		b[i] = b[i] / 10;	
	}
	++d;
	
	for(k=0;k<n;k++)					  
		{									// Done to display the PASSES !!
			printf("%d\t",a[k]);			
		}									
		printf("\n\n");
}
displaysort(a,n);
}

void displaysort(int a[],int n)
{
	int i;
	printf("\nSORTED ARRAY :- \n");
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	
	printf("\n\n\nPRESS ANY KEY TO CONTINUE...");
	_getch();
	system("CLS");
}

int select_option()
{
	int loc=1; //loc = LOCATION
	char key;
	char a[]="1) SELECTION SORT";
	char b[]="2) BUBBLE SORT";
	char c[]="3) INSERTION SORT";
	char d[]="4) RADIX SORT";
	char e[]="5) EXIT";
	
	
	while(key!=13)
	{
		if(loc==1)
		{
		printf("%s <----- \n",a);
		printf("%s \n",b);
		printf("%s \n",c);
		printf("%s \n",d);
		printf("%s \n",e);
		}
		else if(loc==2)
		{
		printf("%s \n",a);
		printf("%s <----- \n",b);
		printf("%s \n",c);
		printf("%s \n",d);
		printf("%s \n",e);
		}
		else if(loc==3)
		{
		printf("%s \n",a);
		printf("%s \n",b);
		printf("%s <----- \n",c);
		printf("%s \n",d);
		printf("%s \n",e);
		}
		else if(loc==4)
		{
		printf("%s \n",a);
		printf("%s \n",b);
		printf("%s \n",c);
		printf("%s <----- \n",d);
		printf("%s \n",e);
		}
		else if(loc==5)
		{
		printf("%s \n",a);
		printf("%s \n",b);
		printf("%s \n",c);
		printf("%s \n",d);
		printf("%s <----- \n",e);
		}
		key=_getch();
		
		if(key!=72 && key!=80)
		Beep(2000,72);
		
		if(key==ARROW_UP)
		{
			--loc;
			if(loc<1)
			loc=5;
		}
		else if(key==ARROW_DOWN)
		{
			++loc;
			if(loc>5)
			loc=1;
		}
		system("CLS");
	}
	
	return loc;
}

