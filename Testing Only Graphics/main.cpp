/*
lets see... hive project 0.0
I'll start by making some antz||whatever scavenging ore||something

done :
	- Random landscape generator
	- antz class with
		- size && speed && load && weelz && etc
		- scan || harvest || return state machinez
		- best-ore-location scanner
so far, it's hive v0.6

done since v0.6 :
	- Err... neurological networkz? :)  (peace of cake) (v1.x)
	- indivuduals :)  (maybe done already by neuro stuff)
and this became v1.1
conclusion : getting 25 Artificial Insane antz to dance for ya, takes a
quite some CPU... I wonder what kinda processor a real termite hole has? :)

v1.2
Neurons earlyer learned only that thay had increased performance,
now I've tought them to learn how thay did that and to do so again,
thus increasing performance even more.


still todo:
	- multiple hives
	- more antz propz; suchs as armour, weapons, health
	- war/heal state machines to go with above mentioned
	- AI hives (modding ant propz)
	- Group missions (taking over load, defending other antz, etc)

yeah... good luck to myself :]

Wondering what that green dot thingy does?
It's the best-yet-ore-scan location. If there's a richer Ore location
further away, the dot moves there.
This dot schould change color if it becomes a target for an Ant.

*/
#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include "D:\D DRIVE\Projects\Testing Only Graphics\GRAPH.INC"

using namespace std;

const MaxAntz=10;
int OldStatus[MaxAntz];
const Pi=3.141592654;
int verbose=0;
int GatheredSomething=0;

int HiveX=160;
int HiveY=100;
long HiveCash=0;

int DrainOre(int, int);
int OreValue(int Xloc, int Yloc);

int MaxOre=249, MinOre=0;
int MaxDrain=6;
int size=10;

int OreField[33][21];

class Neuron {
	private: int Xp,oldXp, Yp,oldYp, Xmod,Ymod;
	private: long Ax, By;
	public: void Set() {
		oldXp=Xp=50;//49+random(3);
		oldYp=Yp=50;//49+random(3);
		switch(random(3)) {
			case 0: Xmod=-1; break;
			case 1: Xmod=1; break;
			default: Xmod=0; break;
		}
		switch(random(3)) {
			case 0: Ymod=-1; break;
			case 1: Ymod=1; break;
			default: Ymod=0; break;
		}
	}
	public: void A(long I) {
		Ax=((I*100)/Xp)/2;
		By=((I*100)/(100-Xp))/2;
	}
	public: void B(long I) {
		Ax+=((I*100)/Yp)/2;
		By+=((I*100)/(100-Yp))/2;
	}
	public: long X() {
		return Ax;
	}
	public: long Y() {
		return By;
	}
	public: void Learn(int Better) {
		if(!Better) {
			Xp=oldXp;
			Yp=oldYp;
			switch(random(3)) {
				case 0: Xmod=-1; break;
				case 1: Xmod=1; break;
				default: Xmod=0; break;
			}
			switch(random(3)) {
				case 0: Ymod=-1; break;
				case 1: Ymod=1; break;
				default: Ymod=0; break;
			}
		}
		if(Xp>1&&Xp<99) Xp+=Xmod;
		if(Yp>1&&Yp<99) Yp+=Ymod;
		oldXp=Xp;
		oldYp=Yp;
	}
};

class BrainPart {
	private: Neuron A1,A2,A3,A4,A5, B1,B2,B3,B4, C1,C2,C3, D1,D2, E1;
	public: void Set() {
		A1.Set(); A2.Set(); A3.Set(); A4.Set(); A5.Set();
		B1.Set(); B2.Set(); B3.Set(); B4.Set();
		C1.Set(); C2.Set(); C3.Set();
		D1.Set(); D2.Set();
		E1.Set();
	}

	public: void Learn(int Better) {
		A1.Learn(Better); A2.Learn(Better); A3.Learn(Better); A4.Learn(Better); A5.Learn(Better);
		B1.Learn(Better); B2.Learn(Better); B3.Learn(Better); B3.Learn(Better);
		C1.Learn(Better); C2.Learn(Better); C3.Learn(Better);
		D1.Learn(Better); D2.Learn(Better);
		E1.Learn(Better);
	}

	public: long Prio(int A, int B, int C, int D, int E) {
// Speed, HarvDist, ScanDist, Load, OreValue

		A1.A(     A );
		A1.B( 100-A );
		A2.A(     B );
		A2.B( 100-B );
		A3.A(     C );
		A3.B( 100-C );
		A4.A(     D );
		A4.B( 100-D );
		A5.A(     E );
		A5.B( 100-E );

		B1.A( A1.Y() );
		B1.B( A2.X() );
		B2.A( A2.Y() );
		B2.B( A3.X() );
		B3.A( A3.Y() );
		B3.B( A4.X() );
		B4.A( A4.Y() );
		B4.B( A5.X() );

		C1.A( B1.Y() );
		C1.B( B2.X() );
		C2.A( B2.Y() );
		C2.B( B3.X() );
		C3.A( B3.Y() );
		C3.B( B4.X() );

		D1.A( C1.Y() );
		D1.B( C2.X() );
		D2.A( C2.Y() );
		D2.B( C3.X() );

		E1.A( D1.Y() );
		E1.B( D2.X() );

		return E1.Y();
	}
};

class Scavenger {
	private: int X, Y, TargetX, TargetY, BestX, BestY, status;
		BrainPart Scan, Retrieve, Harvest;
		int	Hive,
			Size,
			Engine,
			Weels;
		float	Speed, MaxSpeed;
		int	Load, MaxLoad,
			ScanDist, ScanMaxDist,
			HarvDist, HarvMaxDist;
		long	LastLoad, TotalLoad;
		long Ha, Sc, Re;
	public: int IsAlive() {
		return Hive;
	}
	public: int Xpos() {
		return X;
	}
	public: int Ypos() {
		return Y;
	}
	public: int Color() {
		return 250+Hive;
	}

	public: int Buy(int color, int size, int engine, int weels) {
		LastLoad=TotalLoad=0;
		Scan.Set();
		Retrieve.Set();
		Harvest.Set();

		int XdistSet, YdistSet;
		Hive=color;
		Size=size;
		Engine=engine;
		Weels=weels;
		Load=0;
			MaxLoad=(Size-(Engine+Weels));
		Speed=((Engine*Weels)-Load-Size);
			MaxSpeed=((Engine*Weels)-0-Size);
		ScanDist=HarvDist=0;
			if(HiveX<160) {
				XdistSet=HiveX;
			} else {
				XdistSet=(320-HiveX);
			}
			if(HiveY<100) {
				YdistSet=HiveY;
			} else {
				YdistSet=(200-HiveY);
			}
			HarvMaxDist=sqrt(pow(XdistSet,2)+pow(YdistSet,2));
			ScanMaxDist=HarvMaxDist;
		X=TargetX=BestX=HiveX;
		Y=TargetY=BestY=HiveY;
		return Hive;
	}

	private: void MoveTo(int Tx, int Ty) {
		for(int steps=0; steps<=(Speed/(MaxSpeed/3)); steps++) {
			pset(X,Y,OreValue(X,Y));
			if(X<Tx) {
				X++;
			} else if(X>Tx) {
				X--;
			}
			if(Y<Ty) {
				Y++;
			} else if(Y>Ty) {
				Y--;
			}
			pset(X,Y,Color());
		}
	}

	private: void GoScan() {
		ScanDist++;
		for(float A=0; A<=2.1; A+=(.19/ScanDist)) {
			TargetX = (X + (ScanDist*sin(A*Pi))+.5);
			TargetY = (Y + (ScanDist*cos(A*Pi))+.5);
			if((TargetX>=0&&TargetX<320)&&(TargetY>=0)&&(TargetY<200)) {
				if((OreValue(TargetX,TargetY)>OreValue(BestX,BestY))) {
					pset(BestX,BestY,OreValue(BestX,BestY));
					BestX=TargetX;
					BestY=TargetY;
					pset(BestX,BestY,254);
				}
			}
		}
		if(ScanDist>ScanMaxDist) {
			ScanDist=1;
		}
		if(!OreValue(BestX, BestY)) {
			TargetX=HiveX;
			TargetY=HiveY;
		} else {
			TargetX=BestX;
			TargetY=BestY;
		}
	}

	private: void GoRetrieve() {
		if(X==HiveX&&Y==HiveY) {
			TotalLoad+=Load;
			HiveCash+=Load;
			gotoxy(20,1);
			cout << HiveCash;
			Load=0;
		} else {
			MoveTo(HiveX,HiveY);
		}
	}

	private: void GoHarvest() {
		int xx,yy,rr,aa;
		if(X==TargetX&&Y==TargetY) {
			rr=DrainOre(X,Y,(MaxLoad-Load));
			Load+=rr;
			TotalLoad+=rr;
			GatheredSomething+=rr;
			for(int rr=1; rr<15; rr++) {
				for(float aa=0; aa<=2.1; aa+=(.19/rr)) {
					xx = (X + (rr*sin(aa*Pi))+.5);
					yy = (Y + (rr*cos(aa*Pi))+.5);
					if((xx>=0&&xx<320)&&(yy>=0)&&(yy<200)&&pget(xx,yy)<250) pset(xx,yy,OreValue(xx,yy));
				}
			}
		} else {
			pset(TargetX,TargetY,254);
			MoveTo(TargetX,TargetY);
			if(TargetX<X) {
				xx=TargetX;
			} else {
				xx=(320-TargetX);
			}
			if(TargetY<Y) {
				yy=TargetY;
			} else {
				yy=(200-TargetY);
			}
			HarvDist=sqrt(pow(xx,2)+pow(yy,2));
		}
	}
	public: int Status() {
		return status;
	}
	public: int LLoad() {
		return LastLoad;
	}
	public: int TLoad() {
		return TotalLoad;
	}
	public: void Learn() {
		if(TotalLoad>LastLoad) {
			LastLoad=TotalLoad;
			TotalLoad=0;
			Scan.Learn(1);
			Retrieve.Learn(1);
			Harvest.Learn(1);
		} else {
			TotalLoad=0;
			Scan.Learn(0);
			Retrieve.Learn(0);
			Harvest.Learn(0);
		}
		ScanDist=1;
		Load=0;
			MaxLoad=(Size-(Engine+Weels));
		Speed=((Engine*Weels)-Load-Size);
			MaxSpeed=((Engine*Weels)-0-Size);
		pset(X,Y,OreValue(X,Y));
		pset(TargetX,TargetY,OreValue(TargetX,TargetY));
		X=TargetX=BestX=HiveX;
		Y=TargetY=BestY=HiveY;
	}

	public: long ScanPrio() {
		return Sc;
	}
	public: long HarvPrio() {
		return Ha;
	}
	public: long RetrPrio() {
		return Re;
	}

	public: void Act() {
		int A, B, C, D, E;
		pset(X,Y,Color());

		Speed=((Engine*Weels)-Load-Size);
		if(Speed<0) Speed=0;

		A=(Speed*100)/MaxSpeed;
		B=(HarvDist*100)/HarvMaxDist;
		C=(ScanDist*100)/ScanMaxDist;
		D=(Load*100)/MaxLoad;
		E=(OreValue(TargetX,TargetY)*100)/MaxOre;

		Ha=Harvest.Prio(A,B,C,D,E);
		Sc=Scan.Prio(A,B,C,D,E);
		Re=Retrieve.Prio(A,B,C,D,E);

		if(verbose) {
			gotoxy(1,2);
			cout << A << "\t" << B << "\t" << C << "\t" << D << "\t" << E << "\n";
			cout << Ha << "\t" << Re << "\t" << Sc << "\n";
		}

		if( Re > Sc ) {
			if( Re > Ha ) {
				if(verbose) cout << "GoRetrieve";
				status=2;
				GoRetrieve();
			} else {
				if(verbose) cout << "GoHarvest ";
				status=1;
				GoHarvest();
			}
		} else {
			if( Sc > Ha ) {
				if(verbose) cout << "GoScan    ";
				if(status!=3) ScanDist=0;
				status=3;
				GoScan();
			} else {
				if(verbose) cout << "GoHarvest ";
				status=1;
				GoHarvest();
			}
		}
	}
};

Scavenger Ant[MaxAntz];

int OreValue(int Xloc, int Yloc) {
	int Ax,Ay, Bx,By, Cx,Cy, Dx,Dy, Xoff, Yoff;
	Xoff=Xloc%size;
	Yoff=Yloc%size;

	Ax=(Xloc)/size; if(Ax<=0) Ax=0;
	Ay=(Yloc)/size; if(Ay<=0) Ay=0;

	Bx=(Xloc+size)/size; if(Bx>32) Bx=32;
	By=(Yloc)/size; if(By<=0) By=0;

	Cx=(Xloc)/size; if(Cx<=0) Cx=0;
	Cy=(Yloc+size)/size; if(Cy>=20) Cy=20;

	Dx=(Xloc+size)/size; if(Dx>=32) Dx=32;
	Dy=(Yloc+size)/size; if(Dy>=20) Dy=20;

	return ((OreField[Ax][Ay]*(size-Xoff)*(size-Yoff))+(OreField[Bx][By]*Xoff*(size-Yoff))+(OreField[Cx][Cy]*(size-Xoff)*Yoff)+(OreField[Dx][Dy]*Xoff*Yoff))/(size*size);
}

void ScreenUpdate() {
	for(int ypos=0; ypos<200; ypos++) {
		if(ypos>20) {
			gotoxy(20,1);
			cout << HiveCash;
		}
		for(int xpos=0; xpos<320; xpos++) {
			pset(xpos,ypos,OreValue(xpos,ypos));
			for(int Anr=0; Anr<MaxAntz; Anr++) {
				if(Ant[Anr].IsAlive()&&xpos==Ant[Anr].Xpos()&&ypos==Ant[Anr].Ypos()) {
					pset(Ant[Anr].Xpos(), Ant[Anr].Ypos(), Ant[Anr].Color());
				}
			}
			if(xpos==HiveX&&ypos==HiveY) {
				pset(HiveX,HiveY,251);
			}
		}
	}
}

int DrainOre(int Xloc, int Yloc, int AntMax) {
	int Ore=OreValue(Xloc,Yloc);
	int Ax,Ay, Bx,By, Cx,Cy, Dx,Dy, Xoff, Yoff;
	if(Ore>0) {
		if(Ore>(MaxDrain/2)) Ore=(MaxDrain/2)+((OreValue(Xloc,Yloc)/MaxOre)*(MaxDrain/2));
		if(Ore>AntMax) Ore=AntMax;
		Xoff=Xloc%size;
		Yoff=Yloc%size;

		Ax=(Xloc)/size; if(Ax<=0) Ax=0;
		Ay=(Yloc)/size; if(Ay<=0) Ay=0;

		Bx=(Xloc+size)/size; if(Bx>32) Bx=32;
		By=(Yloc)/size; if(By<=0) By=0;

		Cx=(Xloc)/size; if(Cx<=0) Cx=0;
		Cy=(Yloc+size)/size; if(Cy>=20) Cy=20;

		Dx=(Xloc+size)/size; if(Dx>=32) Dx=32;
		Dy=(Yloc+size)/size; if(Dy>=20) Dy=20;

		gotoxy(1,1);
		OreField[Ax][Ay]-=Ore*(((size-Xoff)*(size-Yoff)))/(size*size);
		OreField[Bx][By]-=Ore*(((Xoff)*(size-Yoff)))/(size*size);
		OreField[Cx][Cy]-=Ore*(((size-Xoff)*(Yoff)))/(size*size);
		OreField[Dx][Dy]-=Ore*(((Xoff)*(Yoff)))/(size*size);
		if(OreField[Ax][Ay]<=MinOre||OreField[Ax][Ay]>MaxOre) OreField[Ax][Ay]=0;
		if(OreField[Bx][By]<=MinOre||OreField[Bx][By]>MaxOre) OreField[Bx][By]=0;
		if(OreField[Cx][Cy]<=MinOre||OreField[Cx][Cy]>MaxOre) OreField[Cx][Cy]=0;
		if(OreField[Dx][Dy]<=MinOre||OreField[Dx][Dy]>MaxOre) OreField[Dx][Dy]=0;
//		ScreenUpdate();
	} else {
		Ore=0;
	}
	return Ore;
}

void SetOreField() {
	randomize();
	int xpos, ypos, dist=10, ist;
	for(xpos=0; xpos<33; xpos++) {
		for(ypos=0; ypos<21; ypos++) {
			OreField[xpos][ypos]=0;
		}
	}
	for(ist=0; ist<=25; ist++) {
		for(ypos=10-dist; ypos<=10+dist; ypos++) {
			for(xpos=16-(dist*1.6); xpos<=16+(dist*1.6); xpos++) {
				if(xpos<16) {
					if(xpos<=30) {
						OreField[xpos][ypos]+=OreField[xpos+1][ypos];
					}
				} else {
					if(xpos>1) {
						OreField[xpos][ypos]+=OreField[xpos-1][ypos];
					}
				}
				if(ypos<10) {
					if(ypos<=18) {
						OreField[xpos][ypos]+=OreField[xpos][ypos+1];
					}
				} else {
					if(ypos>1) {
						OreField[xpos][ypos]+=OreField[xpos][ypos-1];
					}
				}
				OreField[xpos][ypos]+=(random(4*ist))-ist;
				OreField[xpos][ypos]/=3;
				if(OreField[xpos][ypos]>MaxOre) OreField[xpos][ypos]=MaxOre;
				if(OreField[xpos][ypos]<=MinOre) OreField[xpos][ypos]=MinOre;
			}
		}
	}
	ScreenUpdate();
}

void main() {
	int AntChangedMind=0;
	randomize();
	graph();
	setpal();
	SetOreField();
	while(OreValue(HiveX,HiveY)) {
		DrainOre(HiveX,HiveY,1);
	}
	ScreenUpdate();
	for(int spawn=0; spawn<MaxAntz; spawn++) {
		Ant[spawn].Buy(1, 100, 15, 15);
		for(int Anr=0; Anr<MaxAntz; Anr++) {
			if(Ant[Anr].IsAlive()) {
				Ant[Anr].Act();
			}
//			ScreenUpdate();
		}
	}
	for(int Anr=0; Anr<MaxAntz; Anr++) {
		OldStatus[Anr]=Ant[Anr].Status();
	}
	for(int blaaat=0; blaaat<30000; blaaat++) {
		for(int blaat=0; blaat<2000; blaat++) {
			gotoxy(1,1);
			cout << blaat << " / " << blaaat;
			for(int Anr=0; Anr<MaxAntz; Anr++) {
//				if(!Anr) verbose=1;
//				else verbose=0;
				if(Ant[Anr].IsAlive()) {
					Ant[Anr].Act();
				}
				gotoxy(1,4+Anr);
				switch(Ant[Anr].Status()) {
					case 0: cout << "dead       " << Ant[Anr].LLoad() << " " << Ant[Anr].TLoad() << Ant[Anr].ScanPrio() << " " << Ant[Anr].HarvPrio() << " " << Ant[Anr].RetrPrio() ; break;
					case 1: cout << "harvesting " << Ant[Anr].LLoad() << " " << Ant[Anr].TLoad() << Ant[Anr].ScanPrio() << " " << Ant[Anr].HarvPrio() << " " << Ant[Anr].RetrPrio() ; break;
					case 2: cout << "retrieving " << Ant[Anr].LLoad() << " " << Ant[Anr].TLoad() << Ant[Anr].ScanPrio() << " " << Ant[Anr].HarvPrio() << " " << Ant[Anr].RetrPrio() ; break;
					case 3: cout << "scanning   " << Ant[Anr].LLoad() << " " << Ant[Anr].TLoad() << Ant[Anr].ScanPrio() << " " << Ant[Anr].HarvPrio() << " " << Ant[Anr].RetrPrio() ; break;
					default: cout << "unknown    " << Ant[Anr].LLoad() << " " << Ant[Anr].TLoad() << Ant[Anr].ScanPrio() << " " << Ant[Anr].HarvPrio() << " " << Ant[Anr].RetrPrio() ; break;
				}
				if(OldStatus[Anr]!=Ant[Anr].Status()) {
					AntChangedMind=1;
					cout << " !";
					OldStatus[Anr]=Ant[Anr].Status();
				}
			}
			if((blaat==300&&GatheredSomething<1)||(blaat==150&&!AntChangedMind)) {
				blaat=1995;
			}
//			ScreenUpdate();
		}
		AntChangedMind=0;
		GatheredSomething=0;
		SetOreField();
		while(OreValue(HiveX,HiveY)) {
			DrainOre(HiveX,HiveY,1);
		}
		ScreenUpdate();

		for(int Anr=0; Anr<MaxAntz; Anr++) {
			if(Ant[Anr].IsAlive()) {
				Ant[Anr].Learn();
				Ant[Anr].Act();
				OldStatus[Anr]=Ant[Anr].Status();
			}
		}
	}
	getch();
	getch();
	txt();
}
