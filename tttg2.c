#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
void check();
int x[3][3],o[3][3],win=0,z[9];
void main()
 {
    /* request auto detection */
   int gdriver = DETECT, gmode;
   int a,b,c,i,j,k=0,flag=0;
   char ch;
   /* initialize graphics and local
   variables */
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
   randomize();
  do
  {
   for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
      {
       x[i][j]=0;
       o[i][j]=0;
      }
    }
   cleardevice();
   

   //tic-tac-toe
   line(250,150,250,390);
   line(330,150,330,390);
   line(170,230,410,230);
   line(170,310,410,310);
   //player 1
   setcolor(3);
   delay(500);
   settextstyle(1, HORIZ_DIR,4);
   outtextxy(5,210,"PLAYER 1");
   line(50,260,100,310);
   line(100,260,50,310);
   //player 2
   setcolor(2);
   delay(500);
   settextstyle(1, HORIZ_DIR,4);
   outtextxy(420,210,"PLAYER 2");
   circle(490,285,30);
   //start
   setcolor(7);
   delay(500);
   settextstyle(1, HORIZ_DIR,1);
   outtextxy(420,350,"->> PLAYER 1 STARTS");
    b=0;
    win=0;
    for(i=0;i<9;i++)
     {
      z[i]=i+1;
     }
    while(b<9)
    {
      a=getch();
      flag=0;
      for(i=0;i<9;i++)
       {
  if(z[i]==(a-48))
   {
    z[i]=z[i]+10;
    flag=1;
   }
       }
      if(k==1)
       {
  setcolor(0);
  settextstyle(1, HORIZ_DIR,1);
  outtextxy(190,400,"CONTINUE");
  k=0;
       }
      c=random(14);
      c=c+1;
      setcolor(c);
      if(flag==1)
      {
      if(b%2==0)
       {
  if(a==49)
   {
    line(240,160,180,220);
    line(180,160,240,220);
    x[0][0]=1;
   }
  else if(a==50)
   {
    line(260,160,320,220);
    line(320,160,260,220);
    x[0][1]=1;
   }
  else if(a==51)
   {
    line(400,160,340,220);
    line(340,160,400,220);
    x[0][2]=1;
   }
  else if(a==52)
   {
    line(180,300,240,240);
    line(240,300,180,240);
    x[1][0]=1;
   }
  else if(a==53)
   {
    line(260,300,320,240);
    line(320,300,260,240);
    x[1][1]=1;
   }
  else if(a==54)
   {
    line(340,300,400,240);
    line(400,300,340,240);
    x[1][2]=1;
   }
  else if(a==55)
   {
    line(180,380,240,320);
    line(240,380,180,320);
    x[2][0]=1;
   }
  else if(a==56)
   {
    line(260,380,320,320);
    line(320,380,260,320);
    x[2][1]=1;
   }
  else if(a==57)
   {
    line(340,380,400,320);
    line(400,380,340,320);
    x[2][2]=1;
   }
       }
      else
       {
  if(a==49)
   {
    circle(210,190,30);
    o[0][0]=1;
   }
  else if(a==50)
   {
    circle(290,190,30);
    o[0][1]=1;
   }
  else if(a==51)
   {
    circle(370,190,30);
    o[0][2]=1;
   }
  else if(a==52)
   {
    circle(210,270,30);
    o[1][0]=1;
   }
  else if(a==53)
   {
    circle(290,270,30);
    o[1][1]=1;
   }
  else if(a==54)
   {
    circle(370,270,30);
    o[1][2]=1;
   }
  else if(a==55)
   {
    circle(210,350,30);
    o[2][0]=1;
   }
  else if(a==56)
   {
    circle(290,350,30);
    o[2][1]=1;
   }
  else if(a==57)
   {
    circle(370,350,30);
    o[2][2]=1;
   }
       }
      }
      else
       {
  setcolor(4);
  settextstyle(1, HORIZ_DIR,2);
  outtextxy(150,400,"Wrong Choice Entered(Wait)");
  delay(1000);
  setcolor(0);
  settextstyle(1, HORIZ_DIR,2);
  outtextxy(150,400,"Wrong Choice Entered(Wait)");
  delay(600);
  setcolor(2);
  settextstyle(1, HORIZ_DIR,2);
  outtextxy(190,400,"CONTINUE");
  k=1;
  b--;
       }
      b++;
      check();
      if(win==1)
       break;
    }
    if(b==9 && win==0)
     {
      setcolor(4);
      settextstyle(1, HORIZ_DIR,2);
      outtextxy(160,400,"MATCH DRAWN");
      getch();
     }
    cleardevice();
    setcolor(15);
    settextstyle(1, HORIZ_DIR,2);
    outtextxy(150,200,"Do you want to play again(y/n)???");
    ch=getch();
   }while(ch=='y'|| ch=='Y');
   if(ch!='y')
    exit(0);
   getch();
 }
void check()
 {
  int i;
  for(i=0;i<3;i++)
   {
    if(x[i][0]==1 && x[i][1]==1 && x[i][2]==1)
     {
      win=1;
      setcolor(2);
      settextstyle(1, HORIZ_DIR,4);
      outtextxy(150,400,"RESULT:Player 1 wins!!");
      getch();
     }
   }
  for(i=0;i<3;i++)
   {
    if(x[0][i]==1 && x[1][i]==1 && x[2][i]==1)
     {
      win=1;
      setcolor(2);
      settextstyle(1, HORIZ_DIR,4);
      outtextxy(150,400,"RESULT:Player 1 wins!!");
      getch();
     }
   }
  if(x[0][0]==1 && x[1][1]==1 && x[2][2]==1)
   {
    win=1;
    setcolor(2);
    settextstyle(1, HORIZ_DIR,4);
    outtextxy(150,400,"RESULT:Player 1 wins!!");
    getch();
   }
  else if(x[0][2]==1 && x[1][1]==1 && x[2][0]==1)
   {
    win=1;
    setcolor(2);
    settextstyle(1, HORIZ_DIR,4);
    outtextxy(150,400,"RESULT:Player 1 wins!!");
    getch();
   }
  for(i=0;i<3;i++)
   {
    if(o[i][0]==1 && o[i][1]==1 && o[i][2]==1)
     {
      win=1;
      setcolor(2);
      settextstyle(1, HORIZ_DIR,4);
      outtextxy(150,400,"RESULT:Player 2 wins!!");
      getch();
     }
   }
  for(i=0;i<3;i++)
   {
    if(o[0][i]==1 && o[1][i]==1 && o[2][i]==1)
     {
      win=1;
      setcolor(2);
      settextstyle(1, HORIZ_DIR,4);
      outtextxy(150,400,"RESULT:Player 2 wins!!");
      getch();
     }
   }
  if(o[0][0]==1 && o[1][1]==1 && o[2][2]==1)
   {
    win=1;
    setcolor(2);
    settextstyle(1, HORIZ_DIR,4);
    outtextxy(150,400,"RESULT:Player 2 wins!!");
    getch();
   }
  else if(o[0][2]==1 && o[1][1]==1 && o[2][0]==1)
   {
    win=1;
    setcolor(2);
    settextstyle(1, HORIZ_DIR,4);
    outtextxy(150,400,"RESULT:Player 2 wins!!");
    getch();
   }
 }