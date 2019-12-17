#include <conio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define QUESTIONS_TO_ASK 5  //CHANGE IF YOU WANT MORE QUESTIONS TO ASK
#define ARROW_UP 72
#define ARROW_DOWN 80

using namespace std;

int record[QUESTIONS_TO_ASK];
int check_random(int);
int selection(string,string,string,string,string);
void skill_display(float,int);
//void display_wrong_questions(int,string,string);


class ques
{
	public :
		int score,qno,ans;
		time_t time_record;
		string name,q,a,b,c,d;
		char key,arrow;
		ques()
		{
		score=0;
		cout<<" ENTER YOUR NAME : ";cin>>name;
		system("CLS");
		}
		
		void questions(int que)
		{
			qno=que;
			if(qno==1)
			{
			q="Where is Guru Govind Singh Sports College located?";
			a="Saifai";
			b="Varanasi";
			c="Lucknow";
			d="Meerut";
			 //ans=3
			}

			if(qno==2)
			{
			q="Who was the flag bearer of India at Rio Olympics 2016?";
			a="P. V. Sindhu";
			b="Jwala Gutta";
			c="Yogeshwar Dutt";
			d="Abhinav Bindra";
			 //ans=4
			}

			if(qno==3)
			{
			q="Who is the Most Famous Video Game Character of all Time?";
			a="Mario";
			b="Donkey Kong";
			c="Sonic";
			d="Solid Snake";
			 //ans=1
			}

			if(qno==4)
			{
			q="How Many Buttons were on the Original NES controller (including the D-pad)";
			a="4";
			b="5";
			c="8";
			d="10";	
			 //ans=3
			}

			if(qno==5)
			{
			q="NES was Short for:";
			a="Never Ending Simulation";
			b="New Enterprise System";
			c="Not Ever Still";
			d="Nintendo Entertainment System";
			 //ans=4
			}

			if(qno==6)
			{
			q="How many forms does The Final Boss of The Legend of Dragoon Have?";
			a="2";
			b="5";
			c="7";
			d="1";
			 //ans=3
			}

			if(qno==7)
			{
			q="What was The First Home Console?";
			a="Oddessy";
			b="Atari 2600";
			c="NES";
			d="Sega Genisis";
			 //ans=1
			}

			if(qno==8)
			{
			q="What is Known as the Hardest Game of all Time?";
			a="Ghosts and Goblins";
			b="Super Ghouls 'n Ghosts";
			c="Contra";
			d="Assassin's Creed";
			 //ans=2
			}

			if(qno==9)
			{
			q="Who is The Elven Sword-Wielding, Green Clothed Hero in the Legend of Zelda series?";
			a="Link";
			b="Luigi";
			c="Ganon";
			d="Zelda";
			 //ans=1
			}

			if(qno==10)
			{
			q="How many main series Call of Duty games are there?";
			a="12";
			b="Way too many";
			c="9";
			d="13";
		//ans=3
			}

			if(qno==11)
			{
			q="What was Mario's name in Donkey Kong?";
			a="Jumpman";
			b="Mr. Plumber";
			c="Antonio";
			d="Junpei";
			 //ans=1
			}

			if(qno==12)
			{
			q="What time traveling device appears in Assassins Creed?";
			a="Time sphere";
			b="Cosmic treadmill";
			c="Animus";
			d="Epoch";
			 //ans=3
			}

			if(qno==13)
			{
			q="Which of these characters never speaks?";
			a="Nathan Drake";
			b="Link";
			c="Master Chief";
			d="Mario";
		 //ans=2
			}

			if(qno==14)
			{
			q="What was the best-selling video game console of all time?";
			a="Nintendo Entertainment System";
			b="Xbox 360";
			c="Nintendo DS";
			d="PlayStation 2";
			//ans=4
			}

			if(qno==15)
			{
			q="Which came first";
			a="Mortal Kombat the game";
			b="Mortal Kombat the movie";
			c="Mortal Kombat Comics";
			d="Mortal Kombat Series";
		 //ans=1
			}

			if(qno==16)
			{
			q="Why did Princess Peach invite Mario to the castle in Mario 64?";
			a="She was worried Bowser would attack";
			b="She'd baked him a cake";
			c="To go on a date";
			d="To pose for a painting";
			 //ans=2
			}

			if(qno==17)
			{
			q="What is Mega Man called in Japan?";
			a="Whiz Kid";
			b="Mr. Robot";
			c="Rock Man";
			d="Jumpman";
		 //ans=3
			}

			if(qno==18)
			{
			q="What does Pokemon stand for?";
			a="Pocket monsters";
			b="Portable collectible monsters";
			c="Poker monkeys";
			d="Pokey monsoon";
			//ans=1
			}

			if(qno==19)
			{
			q="Which Grand Theft Auto game was the first to offer playable female characters?";
			a="Grand Theft Auto Online";
			b="Grand Theft Auto";
			c="Grand Theft Auto 4: The Ballad of Gay Tony";
			d="None of the above";
			 //ans=2
			}

			if(qno==20)
			{
			q="Who helped created Mario, Zelda, and Star Fox?";
			a="Gabe Newell";
			b="Sigeru Miyamoto";
			c="Nobuo Uematsu";
			d="Satoru Iwata";
			 //ans=2
			}

		}
};

class answer_check:public ques
{
	public :
		int wrong = 0; // int wrong created to calculate/store wrong questions and their answer
		string wrong_questions[QUESTIONS_TO_ASK],answers_for_wrong_questions[QUESTIONS_TO_ASK],ans_string;
		void ans_check(int que)
		{
			qno=que;
			
			if(qno==1 && ans==3)
			correct();
			else if(qno==2 && ans==4)
			correct();
			else if(qno==3 && ans==1)
			correct();
			else if(qno==4 && ans==3)
			correct();
			else if(qno==5 && ans==4)
			correct();
			else if(qno==6 && ans==3)
			correct();
			else if(qno==7 && ans==1)
			correct();
			else if(qno==8 && ans==2)
			correct();
			else if(qno==9 && ans==1)
			correct();
			else if(qno==10 && ans==3)
			correct();
			else if(qno==11 && ans==1)
			correct();
			else if(qno==12 && ans==3)
			correct();
			else if(qno==13 && ans==2)
			correct();
			else if(qno==14 && ans==4)
			correct();
			else if(qno==15 && ans==1)
			correct();
			else if(qno==16 && ans==2)
			correct();
			else if(qno==17 && ans==3)
			correct();
			else if(qno==18 && ans==1)
			correct();
			else if(qno==19 && ans==2)
			correct();
			else if(qno==20 && ans==2)
			correct();
			else
			{
			cout<<"WRONG ANSWER";
			score-=5;
			wrong_questions[wrong]=q;

			if(qno==1)
			ans_string="Lucknow";
			else if(qno==2)
			ans_string="Abhinav Bindra";
			else if(qno==3)
			ans_string="Mario";
			else if(qno==4)
			ans_string="8";
			else if(qno==5)
			ans_string="Nintendo Entertainment System";
			else if(qno==6)
			ans_string="7";
			else if(qno==7)
			ans_string="Oddessy";
			else if(qno==8)
			ans_string="Super Ghouls 'n Ghosts";			
			else if(qno==9)
			ans_string="Link";			
			else if(qno==10)
			ans_string="9";			
			else if(qno==11)
			ans_string="Jumpman";
			else if(qno==12)
			ans_string="Animus"	;		
			else if(qno==13)
			ans_string="Link";			
			else if(qno==14)
			ans_string="PlayStation 2";			
			else if(qno==15)
			ans_string="Mortal Kombat the game";			
			else if(qno==16)
			ans_string="She'd baked him a cake";			
			else if(qno==17)
			ans_string="Rock Man";			
			else if(qno==18)
			ans_string="Pocket monsters";			
			else if(qno==19)
			ans_string="Grand Theft Auto";			
			else if(qno==20)
			ans_string="Sigeru Miyamoto";
			
			answers_for_wrong_questions[wrong]=ans_string;
			
			++wrong;
			if(score<0)
		    score=0;
			}
		}
		
void correct()
{
	cout<<" CORRECT ANSWER";
	score+=10;	
}		
		
void display_wrong_questions()
{
	system("COLOR F0");
	char key=1;
	string current="YES";
	int i;
	while(key!=13)
	{
	cout<<"DO YOU WANT ANSWERS FOR YOUR INCORRECT ANSWERS?"<<endl;
	if(current=="YES")
	{
		cout<<" YES  <-----"<<endl;
		cout<<" NO  "<<endl;
	}
	else if(current=="NO")
	{
	cout<<" YES"<<endl;
	cout<<" NO  <----"<<endl;
	}
	
	key=_getch();
	if(key!=ARROW_UP && key!=ARROW_DOWN)
	Beep(1900,70);
	system("CLS");
	if(key==ARROW_UP)
	{
		if(current=="YES")
		current="NO";
		else if(current=="NO")
		current="YES";
	}
	else if(key==ARROW_DOWN )
	{
		if(current=="YES")
		current="NO";
		else if(current=="NO")
		current="YES";
	}
	}
	
	if(current=="YES")
	{
			cout<<"====================================================================================================="<<endl;
		for(i=0;i<wrong;i++)
		{
			cout<<" QUESTION - "<<wrong_questions[i]<<endl<<endl;
			cout<<" ANSWER - "<<answers_for_wrong_questions[i]<<endl;
			cout<<"====================================================================================================="<<endl;
		}
		_getch();
	}
}
};

int main()
{
int que_loop=0,rn_que=1,i=0,random=1;
time_t start_record,end_record;  //RANDOM = 1 MEANS ASK RANDOM QUESTIONS AND IF RANDOM = 0 SEQUENTIAL QUESTIONS TO ASK
char key;
string q;
system("CLS");
system("COLOR F0");
cout<<" THIS GAME IS MADE BY SAHIL SHAHANE."<<endl<<endl<<" YOUR TOTAL TIME & SCORE WILL BE RECORDED AND BASED ON THAT YOUR SKILL LEVEL IS DECIDED."<<endl<<endl;
cout<<" YOU CAN NAVIGATE OPTIONS THROUGH KEY - 1,2,3,4 OR YOU CAN USE ARROW KEYS."<<endl<<endl<<" TO SUBMIT THE ANSWER PRESS ENTER KEY."<<endl<<endl<<" GOOD LUCK!!!"<<endl;
_getch();
system("CLS");
answer_check  player;
time(&start_record);
if(random==1)
{
srand(time(0));
while(que_loop!=QUESTIONS_TO_ASK)
{
    rn_que=1+rand()%20;
    rn_que=check_random(rn_que);
    record[i]=rn_que;
    player.questions(rn_que);
    player.ans=selection(player.q,player.a,player.b,player.c,player.d);
    system("CLS");
  	player.ans_check(rn_que);
  	Sleep(500);
    system("CLS");
    ++que_loop;
    ++i;
}
}
if(random==0)
{
while(que_loop!=QUESTIONS_TO_ASK)
{
    player.questions(rn_que);
    system("CLS");
  	player.ans_check(rn_que);
  	Sleep(500);
    system("CLS");
    ++rn_que;
    ++que_loop;
    ++i;
}
}
time(&end_record);
player.time_record=(end_record-start_record);
system("CLS");
/**
for(i=0;i<QUESTIONS_TO_ASK;i++)      //RUN THIS LOOP TO GET QUESTION NO.s
cout<<record[i]<<endl;
**/
cout<<"====================================================================================================="<<endl;
cout<<" NAME :"<<player.name<<endl;
if(player.score>0)
{
system("COLOR F2");
cout<<endl<<" SCORE : "<<player.score<<endl;
}
else
{
system("COLOR F4");
cout<<endl<<" SCORE : "<<player.score<<endl;	
}

if(player.time_record>60)
cout<<" TIME TAKEN - "<<float(player.time_record)/60<<" Minutes"<<endl;
else
cout<<" TIME TAKEN - "<<player.time_record<<" Seconds"<<endl;

skill_display(player.time_record,player.score);

if(player.wrong!=0)
{
if(player.wrong==QUESTIONS_TO_ASK)
cout<<" ALL ANSWERS WERE WRONG"<<endl<<endl;
else if(player.wrong==1)
cout<<" "<<player.wrong<<" ANSWER WAS WRONG"<<endl;
else
cout<<" "<<player.wrong<<" ANSWERS WERE WRONG"<<endl;
cout<<"====================================================================================================="<<endl<<endl;
system("pause");
system("CLS");
player.display_wrong_questions();
//display_wrong_questions(player.wrong,player.wrong_questions,player.answers_for_wrong_questions);
}
cout<<"====================================================================================================="<<endl<<endl;
return 0;
}

int check_random(int rn)
{
	for(int i=0;i<10;i++)
	{
		if(rn==record[i])
		{
			rn=rn+(1+rand()%2);
		}
		if(rn>20)
		{
			rn=rn-(1+rand()%(1+rand()%2));
		}
	}
	return rn;
}

int selection(string q,string a,string b,string c,string d)
		{
			char prevkey,key='1';
			string current="YES";
			int ans,sound_hz=1900,sound_time=70,arrow=0;
 			while(key!=13)
 			{	start :
 				
				if(key=='1')
				{
				system("CLS");
				cout<<" "<<q<<endl;
				cout<<" 1) "<<a<<"  <-----"<<endl;
				cout<<" 2) "<<b<<endl;
				cout<<" 3) "<<c<<endl;
				cout<<" 4) "<<d<<endl;
				ans=1;
				}
				else if(key=='2')
				{
				system("CLS");
				cout<<" "<<q<<endl;
				cout<<" 1) "<<a<<endl;
				cout<<" 2) "<<b<<"  <-----"<<endl;
				cout<<" 3) "<<c<<endl;
				cout<<" 4) "<<d<<endl;
				ans=2;
				}
				else if(key=='3')
				{
				system("CLS");
				cout<<" "<<q<<endl;
				cout<<" 1) "<<a<<endl;
				cout<<" 2) "<<b<<endl;
				cout<<" 3) "<<c<<"  <-----"<<endl;
				cout<<" 4) "<<d<<endl;
				ans=3;
				}
				else if(key=='4')
				{
				system("CLS");
				cout<<" "<<q<<endl;
				cout<<" 1) "<<a<<endl;
				cout<<" 2) "<<b<<endl;
				cout<<" 3) "<<c<<endl;
				cout<<" 4) "<<d<<"  <-----"<<endl;
				ans=4;
				}
				key=_getch();
				
				if(key!=72 && key!=80)
				Beep(sound_hz,sound_time);
				
				prevkey=ans;
				if(prevkey==1)
				prevkey='1';
				
				else if(prevkey==2)
				prevkey='2';
				
				else if(prevkey==3)
				prevkey='3';
				
				else if(prevkey==4)
				prevkey='4';
				
				if(key==ARROW_UP)
 					{
 					if(prevkey=='1')
 					key='4';
 					
 					if(prevkey=='2')
 					key='1';
 					
 					if(prevkey=='3')
 					key='2';
 					
 					if(prevkey=='4')
 					key='3';
 					
 					}
 					
 					else if(key==ARROW_DOWN)
 					{
 					if(prevkey=='1')
 					key='2';
 					
 					if(prevkey=='2')
 					key='3';
 					
 					if(prevkey=='3')
 					key='4';
 					
 					if(prevkey=='4')
 					key='1';
 					
 					}
 					
 				if(key==27)
				{
					system("CLS");
					while(key!=13)
					{
					cout<<" DO WANT TO EXIT ?"<<endl;
					if(current=="YES")
					{
					cout<<" YES  <-----"<<endl;
					cout<<" NO  "<<endl;
					}
					else if(current=="NO")
					{
					cout<<" YES"<<endl;
					cout<<" NO  <-----"<<endl;
					}
	
					key=_getch();
					if(key!=ARROW_UP && key!=ARROW_DOWN)
					Beep(1900,70);
					system("CLS");
					if(key==ARROW_UP)
					{
					if(current=="YES")
					current="NO";
					else if(current=="NO")
					current="YES";
					}
					else if(key==ARROW_DOWN )
					{
					if(current=="YES")
					current="NO";
					else if(current=="NO")
					current="YES";
					}
					}
					
					if(current=="YES")
					{
					exit(0);
					}
					else
					{
						key='1';
						goto start;
					}
					
				}
			}
			 return ans;
		}

void skill_display(float time_record,int score)
		{
		string skill;
		
		if(time_record <= 10 && score==50 )
		skill="LEGENDARY";
		else if(score==0)
		skill="NOOB";
		else if(time_record <= 15 && score>=40  )
		skill="CRAZY";
		else if(time_record <= 30 && score>=30  )
		skill="NORMAL";
		else if(time_record >= 30 && score>=10 )
		skill="NOOB";
		else if(time_record <= 30 && score<=15 )
		skill="NORMAL ~ NOOB";
		else if(time_record <= 10 && score<=30 )
		skill="NORMAL";
		else if(time_record <= 15 && score<=30 )
		skill="NORMAL";
		else if(time_record <= 15 && score<=10 )
		skill="NOOB";
		else
		skill="NORMAL";
		
		cout<<" SOLVING SKILL - "<<skill<<endl<<endl;
		}
