#include <conio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h> 

using namespace std;

int main()
{
	string line,word_array,word,search;
	fstream temp;
	int line_no=1,f_n=0,found_=0,found[99999];
	fstream file;
	start:
	file.open("test.txt",ios::in);
	
	if(file.fail())
	{
		cout<<"ERROR FILE CANNOT BE READ";
		exit(-1);
	}
	system("CLS");
	cout<<"ENTER WORD TO SEARCH : ";cin>>search;
	while(!file.eof())
	{
	getline(file,line);
	stringstream word(line);
	while(word >> word_array)
	{
		if(search==word_array)
		{
		found_=1;
		found[f_n]=line_no;
		f_n++; 
		}
	}
	line.clear();
	line_no++;		
	}	
	file.close();
	system("CLS");
	if(found_==1)
	{
	cout<<"FOUND AT LINE NO- "<<endl;
	for(int i=0;i<f_n;i++)
	{
		cout<<found[i]<<endl;
	}
	}	
	else
		cout<<"NOT FOUND";
	_getch();
	file.close();
	line_no=1;
	f_n=0;
	found_=0;
	goto start;
	return 0;
}
