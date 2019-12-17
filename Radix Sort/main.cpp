#include <iostream>
#include<conio.h>
using namespace std;
int digit_count(int num) //CHECKS THE NUMBER OF DIGITS
{
	int count=0;
	while(num!=0)
	{
		num=num/10;
		++count;
	}
	return count;
}

int check_digit_number(int num,int count) //CHECKS WHETHER THE ENTERED DIGITS MATCHES THE COUNT
{
	int num2=num,count2=0;
	while(num2!=0)
	{
		num2=num2/10;
		++count2;
	}
	if(count2!=count)
	{
		cout<<"SORRY BRO ENTER THE NUMBER AGAIN WITH SAME NO. OF DIGITS"<<endl;
		cin>>num;
		check_digit_number(num,count);
	}
	return num;
}

int main()
{
	int len;
	cout<<"ENTER ARRAY LENGTH : "; cin>>len;
	int a[len],i,j,k,digit[len],temp,temp_a[len],count=0,div=10;
	cout<<endl<<"PLEASE ENTER THE ELEMENTS IN SAME NUMBER OF DIGITS EXAMPLE - "<<endl<<"12,34,12 OR 345,678,955 OR 5324,3245,6798"<<endl;
	cout<<endl<<"ENTER "<<len<<" ELEMENTS : "<<endl;
	for(i=0;i<len;i++)
	{
		cin>>a[i];
		
		if(i==0)
		{
		count=digit_count(a[i]);
		}
		else if(i>0)
		{
			a[i]=check_digit_number(a[i],count);
		}
	}

cout<<endl<<"--------------------------------------------------------------------------"<<endl;	

for(k=1;k<=count;k++)
{	for(i=0;i<len;i++)
	{
		temp_a[i]=a[i];
	}
	if(k>=2)
	{
		for(i=0;i<len;i++)
		{
		temp_a[i]=temp_a[i]/div;
		}
		div=div*10;
	}
	/**
	cout<<"LOOP - "<<k<<endl;						//REMOVE COMMENT TO GET LOOP DETAILS
	for(i=0;i<len;i++)
	{
		cout<<"A[i] - "<<a[i]<<endl;
    }
    cout<<endl;
	for(i=0;i<len;i++)
	{
		cout<<"TEMP_A[i] - "<<temp_a[i]<<endl;
    }
    **/
	for(i=0;i<len;i++)
	{
		digit[i]=temp_a[i]%10;
		temp_a[i]=temp_a[i]/10;
	}
	
	/**
	cout<<endl;
	for(i=0;i<len;i++)				//REMOVE COMMENT TO GET LOOP DETAILS
	{
		cout<<"DIGIT - "<<digit[i]<<endl;
    }
      cout<<"--------------------------------------------------------------------------";
      **/
	for(i=0;i<len;i++)   // SORTING LOOP
	{
		for(j=i+1;j<len;j++)
		{
			if(digit[i]>digit[j])
			{
				temp=digit[i];
				digit[i]=digit[j];
				digit[j]=temp;
				
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			
		}	
	}
	//cout<<endl;
}

cout<<endl<<"SORTED ARRAY [ USING RADIX SORT ] - "<<endl;
for(i=0;i<len;i++)
	{
		cout<<a[i]<<endl;
	}
	getch();
	return 0;
}
