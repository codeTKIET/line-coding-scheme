#include"iostream.h"
#include"conio.h"
#include"graphics.h"
#include"stdio.h"
#include"dos.h"
#include"string.h"
#include"time.h"
#include"fstream.h"
#include"stdlib.h"
void border();
void about();
void thanku();
class project
{
public:
  int a,i,j,k,l,x,y,x1,y1,v,cou,result;
  char e[9],c,fi[10];
  int n[9],m[9][8],o[72];
  project()
  {
    char str[30];
    time_t timer;
    struct tm *tblock;
    timer = time(NULL);
    tblock = localtime(&timer);
    sprintf(str, asctime(tblock));
    ifstream count("log/COUNT.bin");
    count.getline(fi,10);
    sscanf(fi,"%d",&result);
    count.close();
    sprintf(fi,"%d",result+1);
    ofstream count1("log/COUNT.bin");
    count1<<fi;
    count1.close();
    system("cd LOG");
    ofstream ope(fi, ios::ate);
    ope<<"\n===================================================================\n";
    ope<<"START :                    "<<str;
    ope.close();
    cou=0;
  }
  void cho();
  void get();
  void convert();
  void end();
  void draw1();
  void draw2();
  void draw3();
  void draw4();
};

void project::end()
{
  char str[30];
  time_t timer;
  struct tm *tblock;
  timer = time(NULL);
  tblock = localtime(&timer);
  sprintf(str, asctime(tblock));
  ofstream log(fi, ios::ate);
  if(cou==0)
  {
    log<<"\n\n\tUser terminate program without any input\n\n";
  }
  log<<"\n\nEND :                    "<<str<<"\n===================================================================\n";
  log.close();
  system("cd ..");
}

void project::cho()
{

  if(cou==0)
  {
    project::get();
  }
  else{
    clrscr();
     int gdriver = EGA, gmode = EGAHI, errorcode;
 initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
 setbkcolor(8);
 border();
 setcolor(RED);
 cout<<"\n\n\n\n\n\n\n\n\n\n\n";
 cout<<"                  Do you want to use existing string ("<<e<<")";
 cout<<"\n                  YES: y key NO: n key";
 cout<<"\n                  :";
    c=getche();
    switch(c)
    {
      case 'y':ofstream log(fi, ios::ate);
	       log<<"\n\n                    User Not changed old string";
	       log.close();
	       break;
      case 'n':ofstream log1(fi, ios::ate);
	       log1<<"\n\n                   User changed String (old string \""<<e<<"\")";
	       log1.close();
	       project::get();
		     break;
      default :project::cho();
	       break;
    }
    closegraph();
  }
}

void project::get()
{
 int gdriver = EGA, gmode = EGAHI, errorcode;
 clrscr();
 initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
 setbkcolor(13);
 border();
 setcolor(RED);
 rectangle(206,150,417,170);
 cout<<"\n\n\n\n\n\n\n\n\n\n\n";
 cout<<"                            Enter string : ";
 gets(e);
 a=strlen(e);
 if(a>9)
 {
 outtextxy(206,200,"string limit exceeds");
 delay(1000);
 project::get();
 }
 v=a*8;
 cou=1;
 closegraph();
}

void project::convert()
{
  for(i=0;i<9;i++)
  n[i]=(int)e[i];
  for(k=0;k<9;k++)
  for(j=0;j<8;j++)
  m[k][j]=0;
  for(j=0;j<72;j++)
  o[j]=0;
  for(k=0;k<a;k++)
  {
  for(j=7;j>0;j--)
   {
    m[k][j]=n[k]%2;
    n[k]=n[k]/2;
   }
  }
  int l=0;
   for(k=0;k<a;k++)
  {
  for(j=0;j<8;j++)
   {
    o[l]=m[k][j];
    l++;
   }
  }
}

void project::draw1()
{
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
setcolor(YELLOW);
border();
ofstream log(fi, ios::ate);
log<<"\n\nUSER choice is : Unipolar\nString is       : "<<e;
log.close();
outtextxy(16,113,"+5");
line(32,112,32,170);
line(30,167,616,167);
setbkcolor(13);
setcolor(RED);
rectangle(15,90,616,185);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n    ";
x1=32,y1=167,x=x1,y=y1;
j=0,k=1;
delay(2000);
setcolor(15);
outtextxy(15,190,"Unipolar Scheme         : In a unipolar scheme, all the signal levels are on");
outtextxy(15,202,"                          one side of the time axis, either above or below.");
outtextxy(15,214,"NRZ (Non-Return-to-Zero): Traditionally, a unipolar scheme was designed as a");
outtextxy(15,226,"                          nonreturn-to-zero (NRZ) scheme in which the posit-");
outtextxy(15,238,"                          ive  voltage defines bit 1 and the zero voltage");
outtextxy(15,250,"                          defines  bit O. It is called NRZ because the signal");
outtextxy(15,262,"                          does not return to zero at the middle of the bit. ");
outtextxy(15,276,"           The above figure shows a unipolar NRZ scheme");
setcolor(BLUE);
for(int r=0;r<v;r++)
{
  cout<<o[r];
if(o[k] == 1)
{
sound(1000);
delay(100);
nosound();
}
  x=x,y=y,x1=x+4,y1=y;
  line(x,y,x1,y1);
  x=x1+4,y=y1;
  line(x,y,x1,y1);
  delay(100);

  if(o[j]==1 && o[k]==0)
  {
  x1=x,y1=y+25;
  line(x,y,x1,y1);
  x=x1,y=y1+25;
  line(x,y,x1,y1);
  delay(100);
  }

  if(o[j]==0 && o[k]==1)
  {
  x1=x,y1=y-25;
  line(x,y,x1,y1);
  x=x1,y=y1-25;
  line(x,y,x1,y1);
  delay(100);
  }
 j++,k++;
 delay(100);
}
getch();
}

void project::draw2()
{
  int gdriver = EGA, gmode = EGAHI;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setcolor(YELLOW);
  border();
  ofstream log(fi, ios::ate);
  log<<"\n\nUSER choice is : Polar\nString is      : "<<e;
  log.close();
  outtextxy(24,113,"+5");
  outtextxy(24,160,"-5");
  line(40,112,40,172);
  line(40,142,618,142);
  setbkcolor(13);
  setcolor(RED);
  rectangle(15,90,620,185);
  setcolor(15);
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n     ";
  x1=40,y1=167,x=x1,y=y1;
  j=0,k=1;
  delay(2000);
  outtextxy(15,190,"Polar Schemes           : In polar schemes, the voltages are on the both ");
  outtextxy(15,202,"                          sides of the time axis. For example, the voltage");
  outtextxy(15,214,"                          level for 0 can be positive and the voltage level");
  outtextxy(15,226,"                          for It can be negative.");
  outtextxy(15,240,"Non-Return-to-Zero (NRZ): In polar NRZ encoding, we use two levels of voltage");
  outtextxy(15,252,"                          amplitude. NRZ-L (NRZ-Level), the level of the vol-");
  outtextxy(15,264,"                          tage determines the value of the bit. ");
  outtextxy(15,276,"                          variation.");
  setcolor(BLUE);
  for(int r=0;r<v;r++)
  {
    cout<<o[r];
  if(o[j] == 1)
  {
  sound(1000);
  delay(100);
  nosound();
  }

  if(o[j] == 0)
  {
  sound(2000);
  delay(100);
  nosound();
  }

  x=x,y=y,x1=x+4,y1=y;
  line(x,y,x1,y1);
  x=x1+4,y=y1;
  line(x,y,x1,y1);
  delay(100);

  if(o[j]==1 && o[k]==0)
  {
  x1=x,y1=y+25;
  line(x,y,x1,y1);
  x=x1,y=y1+25;
  line(x,y,x1,y1);
  delay(100);
  }

  if(o[j]==0 && o[k]==1)
  {
  x1=x,y1=y-25;
  line(x,y,x1,y1);
  x=x1,y=y1-25;
  line(x,y,x1,y1);
  delay(100);
  }
 j++,k++;
 delay(100);
}
getch();
}

void project::draw3()
{
  int gdriver = EGA, gmode = EGAHI;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setcolor(YELLOW);
  border();
  ofstream log(fi, ios::ate);
  log<<"\n\nUSER choice is : Manchester\nString is      : "<<e;
  log.close();
  outtextxy(24,113,"+5");
  outtextxy(24,160,"-5");
  line(40,112,40,170);
  line(40,142,618,142);
  setbkcolor(13);
  setcolor(RED);
  rectangle(23,90,620,185);
  setcolor(15);
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n     ";
  x1=40,y1=167,x=x1,y=y1;
  j=0,k=1;
  delay(2000);
  outtextxy(15,202,"             idea of NRZ-L are combined into the Manchester scheme.  In ");
  outtextxy(15,190,"Manchester : The idea of RZ (transition at the middle of the bit) and the ");
  outtextxy(15,214,"             Manchester encoding, the duration of the bit is divided into");
  outtextxy(15,226,"             two halves. The voltage remains at one level during the first");
  outtextxy(15,238,"             half and moves to the other level in the second half. The ");
  outtextxy(15,250,"             transition at the middle of the bit provides synchronization.");
  setcolor(BLUE);
  for(int r=0;r<v;r++)
  {
    cout<<o[r];
    if(o[j] == 1)
    {
    sound(1000);
    delay(100);
    nosound();
    }

    if(o[j] == 0)
    {
    sound(2000);
    delay(100);
    nosound();
    }
	if( o[j]==0)
	{
	  x=x,y=y,x1=x+4,y1=y;
	  line(x,y,x1,y1);
	  delay(100);
	  x=x1,y=y1,x1=x,y1=y-50;
	  line(x,y,x1,y1);
	  delay(100);
	  x=x1+4,y=y1;
	  line(x1,y1,x,y);
	  delay(100);
	}

	if(o[j]==1)
	{
	  x=x,y=y,x1=x+4,y1=y;
	  line(x,y,x1,y1);
	  delay(100);
	  x=x1,y=y1,x1=x,y1=y+50;
	  line(x,y,x1,y1);
	  delay(100);
	  x=x1+4,y=y1;
	  line(x1,y1,x,y);
	  delay(100);
	}
	if(o[j]== 1 && o[k]==1)
	{
	  x1=x,y1=y,x=x1,y=y-50;
	  line(x1,y1,x,y);
	  delay(100);
	}
	if(o[j]== 0 && o[k]==0)
	{
	  x1=x,y1=y,x=x,y=y1+50;
	  line(x1,y1,x,y);
	  delay(100);
	}
	j++;
	k++;
	delay(100);
  }
  getch();
}

void project::draw4()
{
  int gdriver = EGA, gmode = EGAHI;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setcolor(YELLOW);
  border();
  ofstream log(fi, ios::ate);
  log<<"\n\nUSER choice is : AMI\nString is      : "<<e;
  log.close();
  outtextxy(24,113,"+5");
  outtextxy(24,160,"-5");
  line(40,112,40,170);
  line(40,142,618,142);
  setbkcolor(13);
  setcolor(RED);
  rectangle(15,90,620,185);
  setcolor(15);
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n     ";
  x1=40,y1=142,x=x1,y=y1;
  j=0,k=1;
  int count=0;
  delay(2000);
  outtextxy(15,190,"Bipolar Schemes : In bipolar encoding (sometimes called multilevel binary),");
  outtextxy(15,202,"                  there are three voltage levels, positive, negative, and ");
  outtextxy(15,214,"                  zero. The voltage level for one data element is at zero,  ");
  outtextxy(15,226,"                  while the voltage level for the other element alternates");
  outtextxy(15,238,"                  between positive and negative.");
  outtextxy(15,250,"            AMI : In alternate mark inversion, a neutral zero voltage");
  outtextxy(15,274,"                  alternating positive and negative voltages");
  outtextxy(15,262,"                  represents binary O. Binary 1s are represented by ");
  setcolor(BLUE);
  for(int r=0;r<v;r++)
  {
    cout<<o[r];
   if(count == 0)
   {
     if(o[j]==0)
     {
      x=x1,y=y1,x1=x+8,y1=y;
      line(x,y,x1,y1);
      delay(100);
     }
     if(o[j]==1)
     {
      sound(1000);
      delay(100);
      nosound();
     x=x1,y=y1,x1=x,y1=y-25;
     line(x,y,x1,y1);
     delay(100);
     x=x1,y=y1,x1=x+8,y1=y;
     line(x,y,x1,y1);
     delay(100);
     x=x1,y=y1,x1=x,y1=y+25;
     line(x,y,x1,y1);
     delay(100);
     count=1;
     }

   }
  else
   {
     if(o[j]==0)
     {
     x=x1,y=y1,x1=x+8,y1=y;
     line(x,y,x1,y1);
     delay(100);
     }
     if(o[j]==1)
     {
     count=0;
     sound(2000);
     delay(100);
     nosound();
     x=x1,y=y1,x1=x,y1=y+25;
      line(x,y,x1,y1);
       delay(100);
     x=x1,y=y1,x1=x+8,y1=y;
      line(x,y,x1,y1);
       delay(100);
     x=x1,y=y1,x1=x,y1=y-25;
      line(x,y,x1,y1);
       delay(100);

     }

   }
 j++;
 delay(100);
}
getch();
}

void about()
{
  char msg[80];
  int gdriver = EGA, gmode = EGAHI, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setbkcolor(15);
  border();
  setcolor(RED);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
  outtextxy(50,20, "Tatyasaheb Kore College Of Engineering & Technology");
  outtextxy(200,45,"Department Of CSE");
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
  setcolor(5);
  outtextxy(170,110,"LINE CODING SCHEME");
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
  setcolor(3);
  outtextxy(20,220,"GUIDENCE      :    Prof. C. A. KURI");
  outtextxy(20,250,"GROUP MEMBERS :    1) PANKAJ REDEKAR              2) DNYANESHWAR SHINDE");
  outtextxy(20,270,"                   3) ABHISHEK ZIRANGE            4) SUDARSHAN JADHAV");
  setcolor(1);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
  int h=getmaxy() - 35;
  int k=10,j=618;
  for(int b=0;b<39;b++)
  {
   outtextxy(k,h,"=");
   outtextxy(j,h,"=");
   k+=8;
   j-=8;
   delay(100);
       }
  closegraph();
}

void thanku()
{
  int a,b;
  char msg[80];
  int gdriver = EGA, gmode = EGAHI, errorcode;
  initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
  setbkcolor(6);
  border();
  a = getmaxx() / 2;
  a=a-100;
  b = getmaxy() / 2;
  b=b-50;
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
      outtextxy(a, b, "Thank YOU !");
      delay(2500);
  closegraph();
}
void border()
{
 char str[30];

 time_t timer;
 struct tm *tblock;
 timer = time(NULL);
 tblock = localtime(&timer);
 sprintf(str, asctime(tblock));
 setcolor(RED);
 int  left = 10;
 int  top = 10;
 int  right = getmaxx()-10;
 int  bottom = getmaxy()-15;
 rectangle(left,top,right,bottom);
 setcolor(1);
 circle(15,341,8);
 outtextxy(12,338,"C Friends (mini project)");
 outtextxy(210,338,asctime(tblock));
 setcolor(YELLOW);
}
int main()
{
about();
  char h,a[10];
  system("mkdir LOG");
  project cpp;
do {
  clrscr();
  int gdriver = EGA, gmode = EGAHI, errorcode;
 initgraph(&gdriver, &gmode, "C:\\TC\\bgi");
 setbkcolor(9);
 border();
  cout<<"\n\n\n\n\n\n";
  cout<<"\n                              |=====================|";
  cout<<"\n                              ||   1 : UNIPOLAR    ||";
  cout<<"\n                              ||   2 : POLAR NRZ   ||";
  cout<<"\n                              ||   3 : MANCHESTER  ||";
  cout<<"\n                              ||   4 : AMI         ||";
  cout<<"\n                              ||   0 : Exit        ||";
  cout<<"\n                               `===================='";
  cout<<"\n\n                                   Enter Choice : ";
 h=getche();
  switch (h) {
    case '1':cpp.cho();
     cpp.convert();
     cpp.draw1();
     closegraph();
     break;
    case '2':cpp.cho();
     cpp.convert();
     cpp.draw2();
     closegraph();
     break;

    case '3':cpp.cho();
     cpp.convert();
     cpp.draw3();
     closegraph();
     break;

    case '4':cpp.cho();
     cpp.convert();
     cpp.draw4();
     closegraph();
     break;

    case '0' :cpp.end();
	      break;
  }
  closegraph();
} while(h != '0');
thanku();
  return 0;
}
