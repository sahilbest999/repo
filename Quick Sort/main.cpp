#include<conio.h>
#include<iostream>

#define asize 6
using namespace std;
int temp[asize],pivot,size[asize],sorted[asize],pivot_times=1,i,j,startpos,endpos,temp2,current_loop=0,pivot_pos[asize],last[asize],start,end,pivot_pos2,pivot_pos3=0; //size = PER PIVOT ARRAY SIZE

/**
UPDATE VARIABLE PER LOOP - 

last[asize];

**/
int loop()
{
	pivot_pos2=pivot_pos[current_loop];
	pivot=temp[pivot_pos2];
	
	for(i=pivot_pos[current_loop];i<size[current_loop];i++)
	{
		if(temp[i] > pivot)
		{
		start=temp[i];
		startpos=i;
		break;
		}
		else
		{
			startpos=pivotpos[current_loop];
			start=temp[startpos];
		}	
	}
	
	for(i=size[current_loop]-1; i >= last[current_loop];i++)
	{
		if(pivot > temp[i])
		{
		end=temp[current_loop][i];
		endpos=i;
		break;
		}
		else
		{
			endpos=pivotpos[current_loop];
			end=temp[current_loop][endpos];	
		}
	}
	
	 if(startpos < endpos)        //SWAP BETWEEN START AND END
	 {
	 	temp[startpos]=end;
	 	temp[endpos]=start;
	 }
	 else if(startpos > endpos)		//SWAP BETWEEN END AND PIVOT
	 {
	 	temp[pivot_pos2]=end;
	 	temp[endpos]=pivot;
	 	++pivot_times;
	 	++pivot_pos3;
	 	pivot_pos[pivot_pos3]=endpos+1;
	 	pivot_pos[pivot_pos3]=endpos+1;
	 }
	
	
	
}

int main()
{	
	size[0]=asize;
	last[0]=asize-1;
	pivotpos[0]=a[0];
	int a[asize]={40,20,10,30,60,50};
	
	for(i=0;i<asize;i++)
	{
		temp[i]=a[i];
	}
	
	for(i=0;i<=pivot_times;i++)
	{
		loop();
		++current_loop;
	}
	
	for(i=0;i<asize;i++)
	{
		cout<<sorted[i]<<endl;
	}
	return 0;
}


















































/**
int swap(int a,int b)
{
	int temp;
	a=temp;
	a=b;
	b=temp;
	return a,b;
}

int main()
{
	int a[]={6,10,1,2,3,4,5},len=7,i,j,k,start,startpos,end,endpos,pivot,pivotpos=0,temp;
	
	for(i=0;i<len;i++)
	{
	 
	 pivot=a[pivotpos];
	 
	 for(j=0;j<len;j++)
	 {
	 	if(pivot<a[j])
	 	{
	 		start=a[j];
	 		startpos=j;
	 		break;
		}
		else
		{
		pivot=a[0];
	    }  
	 }
	 
	 for(k=len-1;k>=0;k--)
	 {
	 	if(pivot>a[k])
	 	{
	 		end=a[k];
	 		endpos=k;
	 		break;
		}
	 }
	cout<<endl<<"LOOP "<<i+1<<endl;
	 if(startpos < endpos)
	 {
	 	//swap(start,end);
	 	a[startpos]=end;
	 	a[endpos]=start;
	 	cout<<"START POS = "<<startpos<<endl<<"END POS   = "<<endpos<<endl<<endl;
	 }
	 else if(startpos > endpos)
	 {
	 	//swap(pivot,end);
	 	a[endpos]=pivot;
	 	a[pivotpos]=end;
	 	cout<<endl<<"SORTED = "<<a[endpos]<<" AT POS = "<<endpos<<endl;
	 }
	 cout<<endl<<"CHANGE : "<<endl<<"START - "<<start<<endl<<"END - "<<end<<endl<<"PIVOT - "<<pivot<<endl;
	}
	cout<<endl<<endl<<"ARRAY : "<<endl;
	for(i=0;i<len;i++)
	 {
	 	cout<<a[i]<<endl;
	 }
	return 0;
}

**/
