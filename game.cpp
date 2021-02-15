#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<dos.h>

int i,j,i1,j1,i2,j2,n,life1=3,life2=3,steps1=0,steps2=0,m,temp,mod,noplayer=1;
int point1=0,point2=0,s,level=0,w=1000,P=0,T=0,G=0,I=0,totsteps=0,timesr=0;
char a[10][10],ch,t1,t2,ch1,T1,T2;
//------------------------------------------------------------------------------------------------------class open
class player
{
char pname[20];
public:
float score;
//-------constructor
player()
{
strcpy(pname,"----");
score=0;
}
void edit();
void pdisplay();
};
player p[2];
void player::pdisplay()
{ //-----stats display
p[1].score=point1+(life1*30);
p[2].score=point2+(life2*30);
if(noplayer==1)
{
cout<<"\nMODE : - SINGLE-PLAYER ";
cout<<"\nPLAYER NAME:";
puts(p[1].pname);
cout<<"\nSCORE :"<<point1;
cout<<"\nLIFE :"<<life1<<"\n";
cout<<"\nNET SCORE :"<<point1<<" + (LIFE BONUS) "<<life1<<" x 30 :"<<p[1].score;
}
else if(noplayer==2)
{
cout<<"\nMODE : - DUAL-PLAYER ";
cout<<"\n\nPLAYER NAME:";
puts(p[1].pname);
cout<<"\nSCORE :"<<point1;
cout<<"\nLIFE :"<<life1;
cout<<"\n\nPLAYER NAME:";
puts(p[2].pname);
cout<<"\nSCORE :"<<point2;
cout<<"\nLIFE :"<<life2;
cout<<"\n\nNET SCORE :"<<point1<<" + (LIFE BONUS) "<<life1<<" x 30 :"<<p[1].score;
cout<<"\nNET SCORE :"<<point2<<" + (LIFE BONUS) "<<life2<<" x 30 :"<<p[2].score;
}
if(noplayer!=1)
{
if(p[1].score>p[2].score)
{
textcolor(YELLOW);
cprintf(" PLAYER 1 WINS.... ");
}
else
{
cprintf(" PLAYER 2 WINS.... ");
}
}
textcolor(15);
}
//-------------------------------------------------------------class closed
void player::edit()
{
do
{
clrscr();
cout<<"\n\n\t\t\t";
textcolor(YELLOW);
cprintf(" ENTER PLAYER DETAILS: ");
textcolor(15);
cout<<"\n\nENTER PLAYER NAME :";
gets(p[1].pname);
cout<<"\n";
textcolor(YELLOW);
cprintf("ENTER GAMING MODE -");
cout<<"\n\n";
textcolor(LIGHTGREEN);
cprintf(" - SINGLE PLAYER (1)");
textcolor(15);
cout<<"\n\nOR\n\n";
textcolor(LIGHTGREEN);
cprintf(" -- DUAL (2)");
cout<<"\n\n";
cin>>noplayer;
textcolor(15);
if(noplayer!=1)
{
cout<<"\nENTER NAME OF PLAYER 2 :";
gets(p[2].pname);
a[0][0]='é'; //enter name only if dual
a[7][9]='ê'; mod=1;
}
if(noplayer==1) //single
{
mod=0;
}
cout<<"\nSURE TO PROCEED? \n";
cin>>ch;
}while(ch!='y' && ch!='Y');
} //--------------------player edit
void pointbldr(int i1,int j1,int i2,int j2)
{
int repeat=timesr%8;
if(repeat==0)
{
i=(i1+i2)/2; j=(j1+j2)/2;
if(i2!=i && j2!=j)
{
switch(level)
{
case 0 :a[i][j]=(char)36;
break;
case 1 :a[i][j]=(char)1;
break;
case 2 :a[i][j]=(char)3; //life
break;
case 3 :a[i][j]='?';
break;
case 4 :a[i][j]=(char)15; //money
break;
}
}
else
{
switch(level)
{
case 0 :a[i][j]=(char)36;
break;
case 1 :a[i][j]=(char)1;
break;
case 2 :a[i][j]=(char)3; //life
break;
case 3 :a[i][j]='?';
break;
case 4 :a[i][j]=(char)15; //money
break;
}
} //---------------pointblder
}
}
void display(char a[10][10])
{
textcolor(LIGHTRED);
cprintf(" LIFE : ");
cout<<life1<<" ";
for(int k=0;k<life1;k++)
{
cout<<(char)3<<"\t";
}
cout<<"--- \t";
textcolor(LIGHTGREEN);
cprintf(" STEPS 1 : "); cout<<steps1;
cprintf(" --- STEPS 2 : "); cout<<steps2;
textcolor(LIGHTBLUE);
cout<<"\n";
if(noplayer==2)
{
textcolor(LIGHTRED);
cprintf(" LIFE : ");
cout<<life2<<" ";
for(int k=0;k<life2;k++)
{
cout<<(char)3<<"\t";
}
}
cprintf(" POINTS 1 : ");
cout<<point1;
cprintf(" --- POINTS 2 : ");
cout<<point2<<"\n\n";
textcolor(15);
for(int i=0;i<8;i++)
{
for(int j=0;j<10;j++)
{ //--------colon screen
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}
}
//-----------------------------------------------------------------main()
void main()
{
textcolor(15);
ofstream off;
off.open("scoreboard.dat",ios::out | ios::app | ios::binary);
do
{
clrscr(); level=0;
textcolor(YELLOW);
cout<<"\n\n\t\t\t\t\t";
cprintf("GAME\n\n\n");
textcolor(15);
cout<<"\n PRESS 'P' : TO CREATE YOUR PROFILE\n\n\n";
textcolor(LIGHTGREEN);
cout<<"\t\t\t";
cprintf("PRESS 'G' : TO START GAMING");
textcolor(15);
cout<<"\n\n\n PRESS 'T' : TO RUN TUTORIAL";
cout<<"\n\n\n PRESS 'L' : LEADERBOARD\n\n\n";
cout<<" 'ANY KEY' : TO EXIT\n\n\n";
cout<<"ENTER CODE : ";
cin>>ch;
switch(ch)
{
case 'P': {
P=0;
clrscr();
textcolor(YELLOW);
cprintf("\n\nCREATE YOUR PROFILE: \n\n");
textcolor(15);
p[1].edit();
P++;
}
case 'G': { G=0;
clrscr();
cout<<"START GAMING";
 //----------------------------------------------------------------------------------- play game
do
{
G++;
clrscr();
if(G!=1)
level++;
for(i=0;i<8;i++) //assign value;
{
for(j=0;j<10;j++)
{
switch(level)
{
case 0:
{
a[i][j]=':';
break;
}
case 1:
{
a[i][j]='"';
break;
}
case 2:
{
a[i][j]='o';
break;
}
case 3:
{
a[i][j]='.';
break;
}
case 4:
{
a[i][j]='^';
break;
}
} //switch
} //for
} //outer for
a[0][0]='é'; a[7][9]='ê';
display(a);
i=0,j=0,i1=0,j1=0,i2=7,j2=9;
//--------------------------------------------------------------------------------------------GAMING STARTS
do
{
clrscr();
//------------------------------------------------------------------
do
{
I++;mod=I%2;
display(a);
cout<<"\n";
textcolor(YELLOW);
cprintf("LEVEL : ");
cout<<level<<”\t\t\t”;
textcolor(LIGHTGREEN);
cprintf("ENTER MOVE : ");
textcolor(15);
cin>>ch;
switch(noplayer)
{
case 2:
{
{
cout<<"\nPLAYER 1\n";
switch(ch)
{
case 'a':
{
if(j1!=0)
{
if(a[i1][j1-1]==' ')
{
point1--;
}
steps1++;
t1=a[i1][j1];
T1=a[i1][j1]=a[i1][j1-1];
a[i1][j1-1]=t1;
if(t1!=' ')
{
a[i1][j1]=' ';
point1++;
}
j1--;
}
else
{
cout<<"NO ROOM";
}
break;
}
case 'd':
{
if(j1!=9)
{
if(a[i1][j1+1]==' ')
{
point1--;
}
steps1++;
t1=a[i1][j1];
T1=a[i1][j1]=a[i1][j1+1];
a[i1][j1+1]=t1;
if(t1!=' ')
{
a[i1][j1]=' ';
point1++;
}
j1++;
}
else
{
cout<<"NO ROOM";
}
break;
}
case 's':
{
if(i1!=7)
{
if(a[i1+1][j1]==' ')
{
point1--;
}
steps1++;
t1=a[i1][j1];
T1=a[i1][j1]=a[i1+1][j1];
a[i1+1][j1]=t1;
if(t1!=' ')
{
a[i1][j1]=' ';
point1++;
}
i1++;
}
else
{
cout<<"NO ROOM";
}
break;
}
case 'w':
{
if(i1!=0)
{
if(a[i1-1][j1]==' ')
{
point1--;
}
steps1++;
t1=a[i1][j1];
T1=a[i1][j1]=a[i1-1][j1];
a[i1-1][j1]=t1;
if(t1!=' ')
{
a[i1][j1]=' ';
point1++;
}
i1--;
}
else
{
cout<<"NO ROOM";
}
break;
}
} //switch
}
}
//--------------------------------------------------------------------------------------------------
case 1:
{
{
cout<<"\nPLAYER 2\n";
switch(ch)
{
case 'j':
{
if(j2!=0)
{
if(a[i2][j2-1]==' ')
{
point2--;
}
steps2++;
t2=a[i2][j2];
T2=a[i2][j2]=a[i2][j2-1];
a[i2][j2-1]=t2;
if(t2!=' ')
{
a[i2][j2]=' ';
point2++;
}
j2--;
}
else
{
cout<<"NO ROOM";
}
break;
}
case 'l':
{
if(j2!=9)
{
if(a[i2][j2+1]==' ')
{
point2--;
}
steps2++;
t2=a[i2][j2];
T2=a[i2][j2]=a[i2][j2+1];
a[i2][j2+1]=t2;
if(t2!=' ')
{
a[i2][j2]=' ';
point2++;
}
j2++;
}
else
{
cout<<"NO ROOM";
}
break;
}
case 'k':
{
if(i2!=7)
{
if(a[i2+1][j2]==' ')
{
point2--;
}
steps2++;
t2=a[i2][j2];
T2=a[i2][j2]=a[i2+1][j2];
a[i2+1][j2]=t2;
if(t2!=' ')
{
a[i2][j2]=' ';
point2++;
}
i2++;
}
else
{
cout<<"NO ROOM";
}
break;
}
case 'i':
{
if(i2!=0)
{
if(a[i2-1][j2]==' ')
{
point2--;
}
steps2++;
t2=a[i2][j2];
T2=a[i2][j2]=a[i2-1][j2];
a[i2-1][j2]=t2;
if(t2!=' ')
{
a[i2][j2]=' ';
point2++;
}
i2--;
}
else
{
cout<<"NO ROOM";
}
break;
}
} //switch
} //if closed
}
} //switch();
 //------------------------------------------------------------------------------------------
clrscr(); timesr++;
pointbldr(i1,j1,i2,j2);
//----------------------------------------------------------------------------------------------called point builder.
if((T1==(char)1) || (T2==(char)1))
{ //-------------life
if((T1==(char)1))
{ //-------------life
life1--;
cout<<"\nOOPS....\n";
}
else
life2--;
if(life1<=0 || life2<=0)
{
cout<<"\nYOU LOSE !!";
ch='e'; ch1='E';
} //to exit from outer loop.
}
if(T1=='?')
{
m=random(12);
if(m>5)
{
cout<<"\nOPENNED THE WRONG BOX\n";
point1-=5;
}
else
{
cout<<"\nGREAT CHOICE\n";
point1+=5;
}
}
if((T1==(char)3) && life1<3)
{
life1++;
}
if((T2==(char)3) && life2<3)
{
life2++;
}
if(T1==(char)36)
{
cout<<"JACKPOT!!!"; point1+=15;
}
if(T1==(char)15)
{
cout<<"SICKNESS!!!"; point1=steps1;
}
if(T2==(char)15)
{
cout<<"SICKNESS!!!"; point2=steps2;
}
else if(T2=='?')
{
if(m>5)
{
cout<<"\nOPENNED THE WRONG BOX\n"; point2-=5;
}
else
{
cout<<"\nGREAT CHOICE\n"; point2+=5;
}
}
if(T2==(char)36)
{
cout<<"JACKPOT!!!"; point2+=15;
}
if((steps1>=20 || steps2>=20))
{
cout<<"LAST '5' STEPS\n";
if(steps1==25 || steps2==25)
{
cout<<"\nGAME OVER !!";
while(w>0)
w--;
ch='e'; ch1='E';
}
}
}while(ch!='e' && ch!='E');
//------------------------------------------------------------------------------------------------------------------
if(ch1!='E')
{
clrscr();
cout<<"\n\n\n\n\n";
textcolor(RED);
cout<<" ";
cprintf("ARE YOU SURE YOU WANT TO EXIT ?\n\n");
textcolor(15);
cout<<"\n\nTAKE YOUR DECISION...\n\nENTER : \n\n";
for(int in=0;in<1;in++)
{
delay(500);
textcolor(LIGHTGREEN);
cprintf(" 'n' TO CONTINUE");
delay(500);
cout<<"\n\n";
textcolor(LIGHTRED);
cprintf(" 'y' TO EXIT");
cout<<"\n\n";
textcolor(15);
}
cin>>ch;
}
else
ch='y';
}while(ch!='y' && ch!='Y');
//--------------------------------------------------------------------------------------------------------------------
clrscr(); //displaying player stats.
cout<<setw(50);
textcolor(YELLOW);
cprintf("\n\nPLAYER STATS:\n\n");
textcolor(15);
p[1].pdisplay();
cout<<"\nTHANK YOU...";
if(life1<=0 || life2<=0)
{
cout<<"\n\nPLAY AGAIN ?";
steps1=steps2=0; level=0;
life1=life2=3;
cin>>ch1;
}
else if((life1!=0 && life2!=0) && level<4)
{
cout<<"\n\nPLAY NEXT LEVEL ?";
steps1=steps2=0;
cin>>ch1;
}
else if(level>=5)
{
cout<<"\n\nGAME OVER...\n\nPRESS 'ANY KEY' TO EXIT";
cin>>ch1;
ch1='N';
}
 //------outermost dowhile
 //--exit if not continued
}while(ch1!='n' && ch1!='N');
 //-----------------------------------------------------------------------
cout<<"\nGOOD BYE...";
off.write((char*)&p[1],sizeof(p[1]));
off<<p[1].score;
if(noplayer==2)
off<<p[2].score;
off.close();
}
break;
//-------------------- case gaming
case 'T':
{
T=0; T++;
do
{
do
{
clrscr();
cout<<"\n\n\t\t\t\t";
textcolor(YELLOW);
cprintf(" TUTORIAL ");
textcolor(LIGHTBLUE);
cout<<"\n\n";
cprintf(" CONTROLS ");
textcolor(15);
cout<<"\n\n\n PRESS 'j'/ 'a' TO MOVE LEFT \n\n";
cout<<" PRESS 'k'/ 's' TO MOVE DOWN \n\n PRESS 'l'/ 'd' TO MOVE RIGHT \n\n ";
cout<<" - PRESS 'i'/ 'w' TO MOVE UP \n\n* PRESS 'e' TO EXIT \n\n ";
cout<<"GET TO YOUR BASE TO REVIVE YOURSELF, IF YOU ARE EATEN.\n";
cout<<"\n YOU HAVE '25' STEPS AND '3' LIVES TO PLAY WITH.\n";
cout<<" \n\n";
textcolor(LIGHTGREEN);
cprintf("NEXT PAGE ? (N)\n");
textcolor(15);
cin>>ch;
}while(ch!='n' && ch!='N');
do
{
clrscr();
cout<<"\n\t\t\t\t";
textcolor(YELLOW);
cprintf(" TUTORIAL ");
cout<<"\n\n";
textcolor(LIGHTBLUE);
cprintf(" LAY-OUT ");
textcolor(15);
cout<<"\n\n"<<(char)1<<" -YOU LOSE A LIFE\n\n";
cout<<(char)2<<" -YOU EARN A BONUS OF '10' POINTS\n\n";
cout<<(char)3<<" -YOU EARN A LIFE\n\n";
cout<<(char)36<<" -JACKPOT TO DOUBLE YOUR POINTS\n\n";
cout<<(char)15<<" -BEWARE...YOU COULD GET YOUR POINTS DROPPED\n\n";
cout<<"'?' TEST YOUR LUCK, LOSE OR EARN POINTS.";
cout<<"\nCOLLECT THE MOST YOU CAN....\n\n";
textcolor(YELLOW);
cprintf("CHEERS..!!!");
textcolor(15);
cout<<" \n\nPREVIOUS PAGE ? (P)";
cout<<"\n\nHOME PAGE ? (H)\n";
cin>>ch;
if(ch=='H' || ch=='h')
{
ch='P'; ch1='H';
}
}while(ch!='P' && ch!='p');
}while(ch1!='H' && ch1!='h');
}
break;
case 'L':
{
clrscr();
cout<<setw(50);
textcolor(YELLOW);
cprintf("\n\nLEADERBOARD \n\n");
textcolor(15);
ifstream iff;
iff.open("scoreboard.dat",ios::in | ios::binary);
iff.seekg(0);
while(!iff.eof())
{
iff.read((char*)&p[1],sizeof(p[1]));
p[1].pdisplay();
}
iff.close();
}
break;
default:
cout<<"\nCHOOSE AGAIN... ";
} //SWITCH CLOSED
if(T!=0 || G!=0)
cout<<"\n\nGO TO HOME PAGE ? :";
textcolor(LIGHTGREEN);
cprintf("'y' or 'Y'- YES");
cout<<"\t";
textcolor(RED);
cprintf("'n' or 'N' - NO");
textcolor(15);
cout<<"\n";
cin>>ch;
}while(ch!='n' && ch!='N');
getch();
}


