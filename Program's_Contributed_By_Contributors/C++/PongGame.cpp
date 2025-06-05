#include<cstdio>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
using namespace std;
int page=0;
bool run=true;
int P1=0,P2=0;
class paddle
{
 public:
 int x;
 int y;
 char side;
 int speed;

 paddle(int a,int b,char s)
 {side=s;
  x=a;
  y=b;
  speed=3;
 }
 void moverec()
 {if(side=='R')
  {if(GetAsyncKeyState(VK_UP))
  {if(y>0)
   y-=speed;
  }
  else if(GetAsyncKeyState(VK_DOWN))
  {if(y<450)
   y+=speed;
  }
 }


 else if(side=='L')
 {
  {if(GetAsyncKeyState('W'))
  {if(y>0)
   y-=speed;
  }
  else if(GetAsyncKeyState('S'))
  {if(y<450)
   y+=speed;
  }
 }
 }
 }


 void makerec()
 {if(side=='R')
 {

  for(int j=150;j>0;j--)
  {
   rectangle(x,y,x+50,y+j);
  }}
  else if(side=='L')
  for(int j=150;j>0;j--)
  {
   rectangle(x,y,x-50,y+j);
  }
 }
 int returnx()
 {
  return x+50;
 }
};
paddle T1(60,250,'L');
paddle T2(550,250,'R');

class ball
{
public:
int x,y,xspeed,yspeed;

 ball(int a,int b)
 {
  x=a;
  y=b;
  xspeed=2;
  yspeed=4;
 }
 void check()
 {
  if(y==0)
   yspeed=-yspeed;
  if(y>=570)
   yspeed=-yspeed;
  if(x==60 &&(y>=T1.y&&y<=T1.y+150))
   xspeed=-xspeed;
  else if((x==T2.x &&(y>=T2.y&&y<=T2.y+150)))
   xspeed=-xspeed;

 }

 void moveball()
 {
  enum Dir{STOP=0,UP,DOWN,RIGHT,LEFT,UPRIGHT,UPLEFT,DOWNRIGHT,DOWNLEFT};
  int dir;
  dir=UPRIGHT;
  if(dir==3)
  {
   x+=xspeed;

   }
  if(dir==4)
  {
   x-=xspeed;
   }
if(dir==1)
{
  y+=yspeed;
}
if(dir==2)
{
 y-=yspeed;
}
if(dir==5)
{x+=xspeed;
 y-=yspeed;
}
if(dir==6)
{x-=xspeed;
 y-=yspeed;
}
if(dir==7)
{x+=xspeed;
 y+=yspeed;
}
if(dir==8)
{x-=xspeed;
 y+=yspeed;
}

 }
 void makeball()
 {

  for(int i=25;i>0;i--)
  {

  circle(x,y,i);

  }
 }
  void reset()
  {
   x=300;
   y=300;
  }
};
ball B(300,300);
void scorecheck()
{
 if (B.x<0)
 {
  cout<<endl<<"Player 2 scores! "<<endl;
  P2+=1;
  cout<<endl<<"P1 :"<<P1<< " : "<<P2<<": P2"<<endl;
  if(P2==6){run=false;cout<<"P2 WINS!";}
  B.reset();
  cleardevice();
  B.makeball();
  Sleep(2000);
 }
 if(B.x>600)
 {
  cout<<endl<<"Player 1 Scores! "<<endl;
  P1+=1;
  cout<<endl<<"P1 :"<<P1<< " : "<<P2<<": P2"<<endl;
   if(P1==6){run=false;cout<<"P1 WINS! ";}
  B.reset();
  cleardevice();
  B.makeball();
  Sleep(2000);
 }

}
void gameplay()
{



 int page=0;
 do
 {
  setactivepage(page);
  setvisualpage(1-page);
  cleardevice();
  B.makeball();
  B.moveball();
  B.check();
  T1.makerec();
  T1.moverec();
  T2.makerec();
  T2.moverec();
  scorecheck();
   page=1-page;
    delay(1);


 }while(run);

}
int main()
{
 initwindow(600,600,"lol");
gameplay();
 closegraph();
   return 0;

}

