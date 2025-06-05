//***************************************************************************
//      HEADER FILES INCLUDED
//***************************************************************************

#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//***************************************************************************
//      GLOBAL DECLARATION FOR
//          STREAM OBJECT
//***************************************************************************




       fstream f1;
       fstream fp;



//***************************************************************************
//     PROTOTYPE OF FUNCTION USED
//***************************************************************************



       int check();
       void board();
       void disp();
       void disp1(char *a);
       void rules();



//***************************************************************************
//      GLOBAL DECLARATION OF
//             VARIABLE
//***************************************************************************


       struct dosdate_t d ;
       struct time t;
       char n[20]="NULL";
       char ch;
       int cnt=0;
       char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
       static int ctr=0;
       int i;
       char* a1;



//***************************************************************************
//      CLASS USED IN PROJECT
//***************************************************************************



  class academics
    {
     public:
     void ac_disp(char* c);

    };


  class music
    {
     public:
     void m_disp(char* c);
    };


  class games
    {
     public:
     void g_disp(char* c);

    };
  class movies
    {
     public:
     void mo_disp(char* c);

    };
  class news
    {
     public:
     void s_disp(char* c);
    };
  class membership
    {
     public:
     char name[20];
     char password[15];
     char address[20];

     char* enter();
     char* retp()
       {return password;}
    };


       membership m;

  char* membership::enter()
    {
     gotoxy(30,3);
     cout<<"FREE MEMBERSHIP";
     gotoxy(30,4);
     cout<<"---------------";
     gotoxy(1,4);
     cout<<"\n\tEnter NAME     :\t";
     gets(name);
     cout<<"\n\tEnter PASSWORD :\t";
     gets(password);
     cout<<"\n\tEnter ADDRESS  :\t";
     gets(address);
     f1.open("mem.dat",ios::out|ios::app|ios::binary);
     f1.write((char*)&m,sizeof(m));
     f1.close();
     return name;
    }




  class e_books
    {
     public:
     void e_disp(char* c3);
    };


  class front_page
    {
     public:
     void display();
     void choose();
    };

  class feedback
    {
     int ino;
     char name[20];
     char string[50];
     public:
     void create_feedback()
       {randomize();
	ino=(1000 + random(5000));
	cout<<"\n\n\n\t YOUR ID No.        :\t"<<ino;
	cout<<"\n\n\n\t Enter Your Name    :\t";
	gets(name);
	cout<<"\n\n\n\t Enter Comment(Please do not press \"Enter\" while entering Feedback):\n\n\t=>";
	gets(string);
       }
     void show_feedback()
       {
	cout<<"\n\n\tID No.     :\t "<<ino;
	cout<<"\n\n\tNAME       :\t ";
	puts(name);
	cout<<"\n\n\tCOMMENT    :\t ";
	puts(string);
       }
     void modify_feed()
	{
	 cout<<"\n\n\tID No.          :\t "<< ino;

	 cout<<"\n\n\tModify NAME     :\t";
	 gets(name);
	 cout<<"\n\n\tModify COMMENT  :\t ";
	 gets(string);
	 }
	void feed_disp(char* a);

	int  retino()
	  {return ino;}

  };


  class acc
    {
     public:
     char music[50];
     acc()
       {strcpy(music,"NULL");
       }

    };


//***************************************************************************
//      OBJECT OF CLASS
//***************************************************************************


       acc       z;
       academics a;
       music     m1;
       movies    m2;
       e_books   e;
       games     g;
       news    s;
       feedback  f;
       front_page p;



//***************************************************************************
//      FUNCTION TO WRITE IN FILE
//***************************************************************************



  void write_feedback()
    {
     fp.open("feedback.dat",ios::out|ios::app|ios::binary);
     f.create_feedback();
     fp.write((char*)&f,sizeof(feedback));
     fp.close();
     cout<<"\n\t\t\aComment Added!!!";
     getch();
    }



//***************************************************************************
//      FUNCTION TO READ FROM FILE
//***************************************************************************



  void display_feedback(int n)
    {
     clrscr();
     int flag=0;
     fp.open("feedback.dat",ios::in|ios::binary);
     while( fp.read((char*)&f,sizeof(feedback)))
      {

	 if(f.retino()==n)
		{
		 f.show_feedback();
		 flag=1;
		}
      }
     fp.close();
     if(flag==0)
       cout<<"\n\tID Number Does Not Exist";
     getch();
    }



//***************************************************************************
//      FUNCTION TO MODIFY RECORD IN
//                FILE
//***************************************************************************



  void modify_feedback()
    {
     int no,found=0;
     clrscr();
     cout<<"\n\n\tEnter ID no. of the Feedback to be Modified:";
     cin>>no;
     fp.open("feedback.dat",ios::in|ios::out|ios::binary);
     while(fp.read((char*)&f,sizeof(feedback)) && found==0)
	 {
	    if(f.retino()==no)
		   {
		    f.show_feedback();
		    cout<<"\n\t\tEnter The New Feedback"<<endl;
		    f.modify_feed();
		    int pos=-1*sizeof(f);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&f,sizeof(feedback));

		    found=1;
		   }
	 }
     fp.close();
     if(found==0)
     cout<<"\n\n\tComment Not Found ";
     getch();
    }



//***************************************************************************
//      FUNCTION TO DELETE RECORD
//              IN FILE
//***************************************************************************




  void delete_feedback()
    {
     int no;
     clrscr();
     cout<<"\n\n\tEnter The ID no. of the User whose Comment You Want To Delete:\t";
     cin>>no;
     fp.open("feedback.dat",ios::in|ios::out|ios::binary);
     fstream fp2;
     fp2.open("Temp.dat",ios::out);
     fp.seekg(0,ios::beg);
     while(fp.read((char*)&f,sizeof(feedback)))
	{
	  if(f.retino()!=no)
		{
		 fp2.write((char*)&f,sizeof(feedback));
		 }
	}
     fp2.close();
     fp.close();
     remove("feedback.dat");
     rename("Temp.dat","feedback.dat");
     cout<<"\n\n\tComment Deleted ..";
     getch();
    }


//***************************************************************************
//      FUNCTION USED IN PROGRAM
//***************************************************************************


  void tic()
    {
     int player = 1,i,choice;
     char mark;
     clrscr();
     do
	{
		board();
		player=(player%2)?1:2;
		cout << " Player " << player << ", Enter a Number(1 to 9):  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<" Invalid Move ";
			player--;
			getch();
		}
		i=check();
		player++;
	}while(i==-1);
     board();
     if(i==1)
	cout<<"==>Player "<<--player<<" WINS ";
     else
	cout<<"==>Game DRAW";
      square[0]='0';
      square[1]='1';
      square[2]='2';
      square[3]='3';
      square[4]='4';
      square[5]='5';
      square[6]='6';
      square[7]='7';
      square[8]='8';
      square[9]='9';
     getch();

    }


  int check()
    {
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
    }


  void board()
    {
	clrscr();
	cout << "\n\n\t\t\tTic Tac Toe\n\n";
	cout << "\n\t\tPlayer 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "                   |     |     " << endl;
	cout << "                " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "              _____|_____|_____" << endl;
	cout << "                   |     |     " << endl;
	cout << "                " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "              _____|_____|_____" << endl;
	cout << "                   |     |     " << endl;
	cout << "                " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "                   |     |     " << endl << endl;
    }


  void casino()
    {
     unsigned int balanceamt,amt;
     int no,dice;
     char playername[80],ch;
     clrscr();
     cout<<"\n\n\n\n\t\t\tCASINO GAME";
     cout<<"\n\t\t\t-----------";
     cout<<"\n\n\n Enter Your Name  :";
     gets(playername);
     cout<<"\n\n\ Enter Deposit Amount to Play Game : Rs.";
     cin>>balanceamt;
     do
       {
	  clrscr();
	  rules();
	  cout<<"\n\nYour Current Balance is Rs."<<balanceamt;
	  if(balanceamt==0)
	       {	cout<<"\n\nNo Balance Amount Left";
			getch();
			break;
	       }
     do
       {
	  cout<<"\n\n"<<playername<<" Enter Money to BET : ";
	  cin>>amt;
	  if(amt>balanceamt)
	  cout<<"Your Betting Amount is more than your Current Balance\n\nRe-Enter Data\n ";
	  else
	    break;
       }while(1);
     do
       {
	  cout<<"Enter Your Lucky Number to BET Between 1 to 12 :";
	  cin>>no;
	  if(no<=0||no>12)
	    cout<<"Please Check the Number!! It should be Between 1 to 12\n\nRe-Enter Data\n ";
	  else
	    break;
	}while(1);
     randomize();
     dice=random(12)+1;
     if(dice==no)
       {
	cout<<"\n\nGood Luck!! You WON Rs."<<amt*10;
	balanceamt=balanceamt+amt*10;
       }
     else
       {
	cout<<"Bad Luck This Time !! You LOSE Rs."<<amt;
	balanceamt=balanceamt-amt;
       }
	cout<<"\n\nThe Winning Number Was : "<<dice;
	cout<<"\n\n\t"<<playername<<" You Have Rs. "<<balanceamt<<endl;
	cout<<"\n\n-->Do you want to Play Again (y/n)? ";
	cin>>ch;
     }while(ch=='Y'|| ch=='y');
     getch();
  }


  void rules()
    {
     clrscr();
     cout<<"\n\n";
     cout<<"\n\t\t\tRULES OF THE GAME\n";
     cout<<"\t\t\t-----------------";
     cout<<"\n\t1. Choose Any Number Between 1 to 12\n\t2. If You WIN you will get 10 TIMES of the Money You BET\n\t3. If You BET on Wrong Number You will LOSE your Betting Amount\n\n";
     cout<<endl;
     cout<<"================================================================================";
    }


  int choice()
    {
     gotoxy(21,5);
     cout<<"********** E-BOOKS **********";
     gotoxy(32,6);
     cout<<"-------";
     gotoxy(25,7);
     cout<<"1. Review";
     gotoxy(25,8);
     cout<<"2. Download";
     gotoxy(25,9);
     cout<<"3. Back";
     gotoxy(26,11);
     cout<<"Enter choice : ";
     cin>>ch;
     if(ch=='1')
       {return 1;
       }
     if(ch=='2')
       { return 0;
       }
     else
       return 2;
    }


  void d_load(char* c,char* c1)
    {
     gotoxy(45,10);
     cout<<"03%";

     gotoxy(45,10);
     cout<<"09%";

     gotoxy(45,10);
     cout<<"15%";

     gotoxy(45,10);
     cout<<"21%";
          gotoxy(45,10);
     cout<<"27%";
          gotoxy(45,10);
     cout<<"33%";

     gotoxy(45,10);
     cout<<"39%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"45%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"51%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"57%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"63%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"69%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"75%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"81%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"87%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"93%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"99%";
     //delay(1000);
     gotoxy(45,10);
     cout<<"100%";
     gotoxy(27,12);
     cout<<"DOWNLOAD Complete";
     gotoxy(20,16);
     cout<<"Press Any Key To Return....";
     if(ctr==0)
       {getch();
	clrscr();
       }
     else
       {getch();
       fp.open("mem2.dat",ios::out|ios::binary);
       fp.read((char*)&m,sizeof(m));
       strcpy(z.music,c);
       fp.write((char*)&z,sizeof(z));
       fp.close();
       }
       }






  void bsongs(char* a1)
    {
     clrscr();
     gotoxy(20,5);
     cout<<"********** HINDI SONGS **********";
     gotoxy(31,6);
     cout<<"-----------";
     gotoxy(25,7);
     cout<<"1.Party All Night - BOSS";
     gotoxy(25,8);
     cout<<"2.Lungi Dance - Chennai Express";
     gotoxy(25,9);
     cout<<"3.Main Rang Sharbaton Ka - Phata Poster Nikla Hero";
     gotoxy(25,10);
     cout<<"4.Tum Hi Ho - Aashiqui 2";
     gotoxy(25,11);
     cout<<"5.Besharam - Besharam";
     gotoxy(25,12);
     cout<<"6.Boss - BOSS";
     gotoxy(25,13);
     cout<<"7.Titli - Chennai Express";
     gotoxy(25,14);
     cout<<"8.1234 Get on the Dance Floor - Chennai Express";
     gotoxy(25,15);
     cout<<"9.Love Ki Ghanti - Besharam";
     gotoxy(25,17);
     cout<<"#.Return Back";
     gotoxy(26,19);
     cout<<"Enter choice : ";
     cin>>ch;
     switch(ch)
       {case '1':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Party All Night",a1);
		 bsongs(a1);
		 break;
	case '2':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Lungi Dance",a1);
		 bsongs(a1);
		 break;
	case '3':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Main Rang Sharbaton Ka",a1);
		 bsongs(a1);
		 break;
	case '4':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Tum Hi Ho",a1);
		 bsongs(a1);
		 break;
	case '5':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Besharam",a1);
		 bsongs(a1);
		 break;
	case '6':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Boss",a1);
		 bsongs(a1);
		 break;
	case '7':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Titli",a1);
		 bsongs(a1);
		 break;
	case '8':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("1234 Get on the Dance Floor",a1);
		 bsongs(a1);
		 break;
	case '9':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Love Ki Ghanti",a1);
		 bsongs(a1);
		 break;
	case '#':clrscr();
		 m1.m_disp(a1);
		 break;

	default :clrscr();
		 gotoxy(30,10);
		 cout<<"Wrong Choice!!!!";
		 getch();
		 bsongs(a1);
		 break;

    }

   getch();
  }


   void hsongs(char* b2)
    {
     clrscr();
     gotoxy(20,5);
     cout<<"********** ENGLISH SONGS **********";
     gotoxy(31,6);
     cout<<"-------------";
     gotoxy(25,7);
     cout<<"1.Roar - Katy Perry";
     gotoxy(25,8);
     cout<<"2.Wrecking Ball - Miley Cyrus ";
     gotoxy(25,9);
     cout<<"3.Royals - Lorde";
     gotoxy(25,10);
     cout<<"4.Berzerk - Eminem";
     gotoxy(25,11);
     cout<<"5.Wake Me Up - Avicii";
     gotoxy(25,12);
     cout<<"6.Black and Yellow - Vis Khalifa";
     gotoxy(25,13);
     cout<<"7.Safe And Sound - Capital Cities";
     gotoxy(25,14);
     cout<<"8.We Can't Stop - Miley Cyrus";
     gotoxy(25,15);
     cout<<"9.Applause - Lady Gaga";
     gotoxy(25,17);
     cout<<"#.Return Back";
     gotoxy(26,19);
     cout<<"Enter choice : ";
     cin>>ch;
     switch(ch)
       {case '1':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Roar",b2);
		 hsongs(b2);
		 break;
	case '2':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Wrecking Ball",b2);
		 hsongs(b2);
		 break;
	case '3':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Royals",b2);
		 hsongs(b2);
		 break;
	case '4':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Berzerk",b2);
		 hsongs(b2);
		 break;
	case '5':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Wake Me Up",b2);
		 hsongs(b2);
		 break;
	case '6':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Black and Yellow",b2);
		 hsongs(b2);
		 break;
	case '7':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Safe And Sound",b2);
		 hsongs(b2);
		 break;
	case '8':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("We Can't Stop",b2);
		 hsongs(b2);
	case '9':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING SONG - ";
		 d_load("Applause",b2);
		 hsongs(b2);
	case '#':clrscr();
		 m1.m_disp(b2);
		 break;

	default :clrscr();
		 gotoxy(30,10);
		 cout<<"Wrong Choice!!!!";
		 getch();
		 hsongs(b2);
		 break;



       }

     getch();

  }


  void bmovies(char* d1)
    {
     clrscr();
     gotoxy(20,5);
     cout<<"********** BOLLYWOOD MOVIES **********";
     gotoxy(31,6);
     cout<<"----------------";
     gotoxy(25,7);
     cout<<"1.ROCKSTAR";
     gotoxy(25,8);
     cout<<"2.GANGS OF WASSEYPUR";
     gotoxy(25,9);
     cout<<"3.Pyaar ka Punchnama";
     gotoxy(25,10);
     cout<<"4.Yeh Jawaani Hai Deewani";
     gotoxy(25,11);
     cout<<"5.Bhaag Milkha Bhaag";
     gotoxy(25,12);
     cout<<"6.Kabir Singh";
     gotoxy(25,13);
     cout<<"7.The Lunch Box";
     gotoxy(25,14);
     cout<<"8.Mission Mangal";
     gotoxy(25,15);
     cout<<"9.Aashiqui 2";
     gotoxy(25,17);
     cout<<"#.Return Back";
     gotoxy(26,19);
     cout<<"Enter choice : ";
     cin>>ch;
     switch(ch)
       {case '1':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("ROCKSTAR",d1);
		 bmovies(d1);
		 break;
	case '2':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("GANGS OF WASSEYPUR",d1);
		 bmovies(d1);
		 break;
	case '3':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Pyaar ka Punchnama",d1);
		 bmovies(d1);
		 break;
	case '4':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Yeh Jawaani Hai Deewani",d1);
		 bmovies(d1);
		 break;
	case '5':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Bhaag Milkha Bhaag",d1);
		 bmovies(d1);
		 break;
	case '6':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Kabir Singh",d1);
		 bmovies(d1);
		 break;
	case '7':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("The Lunch Box",d1);
		 bmovies(d1);
		 break;
	case '8':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Mission Mangal",d1);
		 bmovies(d1);
	case '9':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Aashiqui 2",d1);
		 bmovies(d1);
	case '#':clrscr();
		 m2.mo_disp(d1);
		 break;

	default :clrscr();
		 gotoxy(30,10);
		 cout<<"Wrong Choice!!!!";
		 getch();
		 bmovies(d1);
		 break;



       }

     getch();
  }


  void hmovies(char* e1)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"********** HOLLYWOOD MOVIES ***********";
     gotoxy(32,6);
     cout<<"----------------";
     gotoxy(25,7);
     cout<<"1.IRON MAN 3";
     gotoxy(25,8);
     cout<<"2.GRAVITY";
     gotoxy(25,9);
     cout<<"3.OBLIVION";
     gotoxy(25,10);
     cout<<"4.WOLVERINE";
     gotoxy(25,11);
     cout<<"5.Fast and Furious 8";
     gotoxy(25,12);
     cout<<"6.The Hangover Part 3";
     gotoxy(25,13);
     cout<<"7.Man Of Steel";
     gotoxy(25,14);
     cout<<"8.Monsters University";
     gotoxy(25,15);
     cout<<"9.Pacific Rim";
     gotoxy(25,17);
     cout<<"#.RETURN BACK";
     gotoxy(26,19);
     cout<<"Enter Choice : ";
     cin>>ch;
     switch(ch)
       {
	case '1':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE  - ";
		 d_load("IRON MAN 3",e1);
		 hmovies(e1);
		 break;
	case '2':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("GRAVITY",e1);
		 hmovies(e1);
		 break;
	case '3':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("OBLIVION",e1);
		 hmovies(e1);
		 break;
	case '4':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("WOLVERINE",e1);
		 hmovies(e1);
		 break;
	case '5':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Fast and Furious 8",e1);
		 hmovies(e1);
		 break;
	case '6':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("The Hangover Part 3",e1);
		 hmovies(e1);
		 break;
	case '7':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Man of Steel",e1);
		 hmovies(e1);
		 break;
	case '8':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Monsters University",e1);
		 hmovies(e1);
	case '9':clrscr();
		 gotoxy(27,10);
		 cout<<"DOWNLOADING MOVIE - ";
		 d_load("Pacific Rim",e1);
		 hmovies(e1);
	case '#':clrscr();
		 m2.mo_disp(e1);
		 break;
      default   :clrscr();
		 gotoxy(30,10);
		 cout<<"Wrong Choice!!!!";
		 getch();
		 hmovies(e1);
		 break;
       }

     getch();
  }

  void acc_his()
    {
    fp.open("mem2.dat",ios::in|ios::binary);
     while(!fp.eof())
      {fp.read((char*)&z,sizeof(z));
	  clrscr();
	  gotoxy(20,5);
	  cout<<"########## ACCOUNT HISTORY ##########";
	  gotoxy(31,6);
	  cout<<"---------------";
	  gotoxy(20,8);
	  cout<<"==> LAST  DOWNLOAD : ";
	  cout<<z.music;
	  fp.close();
	  getch();
	  clrscr();
	  break;
	 }
    }



   void disp1(char* p)
    {
     gotoxy(5,9);
     cout<<"NAME:"<<p;
     gotoxy(5,10);
     cout<<"----";
     gotoxy(1,1);
     cout<<"*******************************************************************************";
     //delay(200);
     cout<<"     --|--                               "<<"\n";
     cout<<"      |    /|   |--|  |    / -|-  |---   "<<"\n";
     cout<<"      |   / |   |__|  |   /   |   |___   "<<"\n";
     cout<<"      |  /--|   /  |  |  /    |       |   "<<"\n";
     cout<<"  |___| /   |  /   |  |_/    _|_  |___|   "<<"\n";
     //delay(200);
     gotoxy(1,25);
     cout<<"*******************************************************************************";
     gotoxy(21,13);
     cout<<"CONGRATULATIONS - You have Become a Member of\"JARVIS\".Now,  ";
     gotoxy(21,14);
     cout<<"you can Download Unlimited Songs, Movies and";
     gotoxy(21,15);
     cout<<"e-Books Absolutely FREE.";
     gotoxy(21,16);
     cout<<"SO, E N J O Y ! ! ! ! ! !";
     gotoxy(1,11);
     cout<<" -----------------";
     cout<<"\n | 1. Academics  |";
     cout<<"\n | 2. Music      |";
     cout<<"\n | 3. Games      |";
     cout<<"\n | 4. Movies     |";
     cout<<"\n | 5. e-Books    |";
     cout<<"\n | 6. Feedback   |";
     cout<<"\n | 7. News       |";
     cout<<"\n | 8. Account    |";
     cout<<"\n |    History    |";
     cout<<"\n | 9. Exit       |";
     cout<<"\n -----------------";
     gotoxy(60,2);
     cout<<"";
     gotoxy(60,3);
     cout<<" FREE MEMBERSHIP ";
     gotoxy(60,4);
     cout<<"";
     gotoxy(53,5);
     cout<<"Press \"#\" to LOGOUT";
     gotoxy(53,6);
     cout<<"--------------------";
     gotoxy(27,22);
     cout<<"Copyright B_k";
     gotoxy(30,23);
     cout<<"All Rights Reserved";
     _dos_getdate(&d);
     gotoxy(62,24);
     printf(" %d", (d.day));
     cout<<"/";
     gotoxy(66,24);
     printf(" %d",( d.month));
     cout<<"/";
     gotoxy(70,24);
     printf(" %d",(d.year));
     gettime(&t);
     gotoxy(66,23);
     cout<<int(t.ti_hour)<<":"<<int(t.ti_min);
     gotoxy(29,19);
     cout<<"Enter Your Choice: ";
     cin>>ch;
     switch(ch)
	{ case '1': a.ac_disp(p);
		    break;
	  case '2': m1.m_disp(p);
		    break;
	  case '3': g.g_disp(p);
		    break;
	  case '4': m2.mo_disp(p);
		    break;
	  case '5': e.e_disp(p);
		    break;
	  case '6': f.feed_disp(p);
		    break;
	  case '7': s.s_disp(p);
		    break;
	  case '9': clrscr();
		    gotoxy(25,11);
		    cout<<"Thank You for Using JARVIS";
		    gotoxy(26,12);
		    cout<<"Hope you enjoyed it!!!!!";
		    getch();
		    exit(0);
		    break;
	  case '8': clrscr();
		    acc_his();
		    disp1(p);
		    break;
	  case '#': clrscr();
		    ctr=0;
		    disp();
		    break;
	  default: clrscr();
		    gotoxy(30,10);
		    cout<<"WRONG CHOICE!!!!!!!!" ;
		    getch();
		    clrscr();
		    disp1(p);
	}
    }


//***************************************************************************
//     INTRODUCTION FUNCTION
//***************************************************************************





   void disp()
    {
     cout<<"*******************************************************************************";
     //delay(200);
     cout<<"     --|--                               "<<"\n";
     cout<<"      |    /|   |--|  |    / -|-  |---   "<<"\n";
     cout<<"      |   / |   |__|  |   /   |   |___   "<<"\n";
     cout<<"      |  /--|   /  |  |  /    |       |   "<<"\n";
     cout<<"  |___| /   |  /   |  |_/    _|_  |___|   "<<"\n";
     //delay(200);
     gotoxy(1,25);
     cout<<"*******************************************************************************";
     gotoxy(21,13);
     cout<<"JARVIS allows you to Download latest Songs, Movies";
     gotoxy(21,14);
     cout<<"and e-Books Absolutely FREE.You can also take";
     gotoxy(21,15);
     cout<<"tips for Academics and view Latest News.";
     gotoxy(21,16);
     cout<<"SO, E N J O Y ! ! ! ! ! !";
     //delay(500);
     gotoxy(1,11);
     cout<<" -----------------";
     cout<<"\n | 1. Academics  |";
     cout<<"\n | 2. Music      |";
     cout<<"\n | 3. Games      |";
     cout<<"\n | 4. Movies     |";
     cout<<"\n | 5. e-Books    |";
     cout<<"\n | 6. Feedback   |";
     cout<<"\n | 7. News       |";
     cout<<"\n | 8. Exit       |";
     cout<<"\n -----------------";
     gotoxy(60,2);
     //delay(500);
     cout<<"";
     gotoxy(60,3);
     cout<<" FREE MEMBERSHIP ";
     gotoxy(60,4);
     cout<<"";
     gotoxy(49,5);
     //delay(500);
     cout<<"Press \"@\" for Free Membership!!";
     gotoxy(49,6);
     cout<<"-------------------------------";
     gotoxy(55,7);
     //delay(500);
     cout<<"Press \"$\" to LOGIN";
     gotoxy(55,8);
     cout<<"-------------------";
     gotoxy(27,22);
     cout<<"Copyright B_k";
     gotoxy(30,23);
     cout<<"All Rights Reserved";
     _dos_getdate(&d);
     gotoxy(62,24);
     printf(" %d", (d.day));
     cout<<"/";
     gotoxy(66,24);
     printf(" %d",( d.month));
     cout<<"/";
     gotoxy(70,24);
     printf(" %d",(d.year));
     gettime(&t);
     gotoxy(66,23);
     cout<<int(t.ti_hour)<<":"<<int(t.ti_min);
     gotoxy(29,19);
     cout<<"Enter Your Choice: ";
     p.display();
    }




  void feedback::feed_disp(char* a)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"########## YOUR FEEDBACK ##########";
     gotoxy(32,6);
     cout<<"-------------";
     gotoxy(27,8);
     cout<<"1.Add a Feedback";
     gotoxy(27,9);
     cout<<"2.Search a Feedback";
     gotoxy(27,10);
     cout<<"3.Modify a Feedback";
     gotoxy(27,11);
     cout<<"4.Delete a Feedback";
     gotoxy(27,12);
     cout<<"5.Return";
     gotoxy(26,14);
     cout<<"Enter Your Choice : ";
     cin>>ch;
     if(ch=='1')
       {clrscr();
	write_feedback();
	f.feed_disp(a);
       }
     else if(ch=='2')
       {clrscr();
	int x;
	cout<<"\n\tEnter the ID Number,whose Feedback is to be Seen : ";
	cin>>x;
	display_feedback(x);
	f.feed_disp(a);
       }
     else if(ch=='3')
       {clrscr();
	modify_feedback();
	f.feed_disp(a);
       }
     else if(ch=='4')
       {clrscr();
	delete_feedback();
	f.feed_disp(a);
       }
     else if(ch=='5')
      {if(ctr==0)
       {clrscr();
	disp();}
     else
       {clrscr();
	disp1(a); }
      }
    }


  void login();




  void front_page::display()
    {ch=getch();
     switch(ch)
	{ case '1': a.ac_disp("NULL");
		    break;
	  case '2': m1.m_disp("NULL");
		    break;
	  case '3': g.g_disp("NULL");
		    break;
	  case '4': m2.mo_disp("NULL");
		    break;
	  case '5': e.e_disp("NULL");
		    break;
	  case '6': f.feed_disp("NULL");
		    break;
	  case '7': s.s_disp("NULL");
		    break;
	  case '8': clrscr();
		    gotoxy(27,10);
		    cout<<"Thank you for visiting JARVIS ";
		    gotoxy(28,11);
		    cout<<"Hope you enjoyed it!!!!!";
		    getch();
		    exit(0);
		    break;
	  case '@': clrscr();
		    a1=m.enter();
		    int n1;
		    cout<<"\n\n\n\t\tPRESS \"1\" TO LOGIN";
		    cout<<"\n\n\n\t\tOR ANY OTHER KEY TO RETURN : ";
		    cin>>n1;
		    if(n1==1)
		    {ctr=1;
		     clrscr();
		     disp1(a1);
		       }
		       else
			{clrscr();
			 disp();
			 }
		    break;

	  case '$': clrscr();
		    login();
		    break;
	  default : clrscr();
		    gotoxy(30,10);
		    cout<<"WRONG CHOICE!!!!!!!!" ;
		    getch();
		    clrscr();
		    if(ctr==0)
		       disp();
		    else
		       disp1("NULL");
		    break;
	}
      getch();
  }



  void login()
    {int q=0;
     clrscr();
     char mname[20];
     char mpassword[15];
     gotoxy(21,5);
     cout<<"########## LOGIN ##########";
     gotoxy(32,6);
     cout<<"-----";
     cout<<"\n\n\tENTER NAME     : ";
     gets(mname);
     cout<<"\n\n\tENTER PASSWORD : ";
     gets(mpassword);
     f1.open("mem.dat",ios::in|ios::binary);
     while(!f1.eof())
       { if(q==0)
	 {f1.read((char*)&m,sizeof(m));
	 if(strcmp(m.retp(),mpassword)==0)
	      {clrscr();
	       ctr=1;
	       f1.close();
	       disp1(mname);
	 }    }
	 else
	 break;
       }
     clrscr();
     gotoxy(30,10);
     cout<<"WRONG PASSWORD!!!!!!!!" ;
     getch();
     f1.close();
     clrscr();
     disp();
  }


//***************************************************************************
//      FUNCTION TO DELETE RECORD
//              IN FILE
//***************************************************************************



  void academics::ac_disp(char* c)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"######### ACADEMICS ##########";
     gotoxy(31,6);
     cout<<"---------";
     gotoxy(25,7);
     cout<<"1.How to succeed in IIT Mains as well as Advance ?";
     gotoxy(25,9);
     cout<<"2.Tips for success in AIIMS ?";
     gotoxy(25,11);
     cout<<"3. C.B.S.E Tips ";
     gotoxy(25,13);
     cout<<"4.Return Back";
     gotoxy(26,15);
     cout<<"Enter Choice: ";
     cin>>ch;
     switch(ch)
       {case '1':
		 clrscr();
		 gotoxy(25,2);
		 cout<<"3 Essentials to Crack IIT Mains and Advance";
		 gotoxy(25,3);
		 cout<<"-----------------------------";
		 gotoxy(8,4);
		 cout<<"If you want to be an iitian then you will need";
		 gotoxy(8,5);
		 cout<<"1. The right Study Material";
		 gotoxy(8,6);
		 cout<<"2. Hard Work";
		 gotoxy(8,7);
		 cout<<"3. The Desire to Succeed";
		 gotoxy(8,9);
		 cout<<"The Right Study Material:::--";
		 gotoxy(8,10);
		 cout<<"Text Books Are Enough.There are many books of famous authors which";
		 gotoxy(8,11);
		 cout<<"can be used to prepare for IIT. Moreover, books by NCERT are written by a ";
		 gotoxy(8,12);
		 cout<<"team of well Qualified Experts on the Subject. A student gets only Two";
		 gotoxy(8,13);
		 cout<<"attempts to Appear for IIT exam that too in Two Consecutive Years.";
		 gotoxy(8,14);
		 cout<<"Other than these,students should have an excellent percentage in 12th boards.";
		 gotoxy(8,16);
		 cout<<"Hard Work:::-";
		 gotoxy(8,17);
		 cout<<"If an aspirant studies for 4-5 hours everyday, but on a regular basis,";
		 gotoxy(8,18);
		 cout<<"he should do well in IIT Mains and Advance. IIT is all about Skills and";
		 gotoxy(8,19);
		 cout<<"Intelligence.An Aspirant needs to sharpen his Problem Solving Skills ";
		 gotoxy(8,20);
		 cout<<"to take Admission in IIT Colleges.";
		 gotoxy(8,22);
		 cout<<"The Desire to Succeed:::- ";
		 gotoxy(8,23);
		 cout<<"Call this Positive Outlook or Positive Thinking or Being Ambitious; ";
		 gotoxy(8,24);
		 cout<<"but without dreaming big one cannot succeed. Mahatma Gandhi once said ";
		 gotoxy(8,25);
		 cout<<"\"A man is but the product of his thoughts.What he thinks,he becomes.\"";
		 getch();
		 a.ac_disp(c);
		 break;

	case '2':
		 clrscr();
		 gotoxy(14,3);
		 cout<<"Essentials to do well in AIIMS";
		 gotoxy(14,4);
		 cout<<"------------------------------------------------";
		 gotoxy(8,5);
		 cout<<"-> Know Your Strengths and Weaknesses";
		 gotoxy(8,6);
		 cout<<"-> Plan your Preparation as, He who fails to plan, himself.";
		 gotoxy(8,7);
		 cout<<"   plans to fail.";
		 gotoxy(8,8);
		 cout<<"-> Know your exam well.";
		 gotoxy(8,9);
		 cout<<"-> Each question is different in its own way with an element of";
		 gotoxy(8,10);
		 cout<<"   surprise in it.";
		 gotoxy(8,11);
		 cout<<"-> Candidates who know how and what to look for in a question are";
		 gotoxy(8,12);
		 cout<<"   likely to score high in the test.";
		 gotoxy(8,13);
		 cout<<"-> Attain minimum qualifying scores in subject.";
		 gotoxy(8,13);
		 cout<<"-> Focus on one subject and ignoring the other may land up problems.";
		 gotoxy(8,14);
		 cout<<"-> Divide your time wisely and equally for all subjects.";
		 gotoxy(8,15);
		 cout<<"-> Focus on solving problems on your own,while preparing for the exam.";
		 gotoxy(8,16);
		 cout<<"-> Try conventional methods first to solve problems Hit and Miss.";
		 gotoxy(8,17);
		 cout<<"-> Try to understand the problem again and find clues that can lead ";
		 gotoxy(8,18);
		 cout<<"   you to solution. ";
		 gotoxy(8,19);
		 cout<<"-> Consult the solution, only when you have exhausted your limits.";
		 gotoxy(8,20);
		 cout<<"-> Devise your own shortcuts & ways to tackle particular kind of";
		 gotoxy(8,21);
		 cout<<"   problems.";
		 gotoxy(8,22);
		 cout<<"-> Never use calculator for the calculations during practice. Mental";
		 gotoxy(8,23);
		 cout<<"   calculations actually increase your speed to a great extent. ";
		 getch();
		 a.ac_disp(c);;
		 break;

	case '3':
		 clrscr();
		 gotoxy(14,3);
		 cout<<"HOW TO TACKLE C.B.S.E BOARDS";
		 gotoxy(14,4);
		 cout<<"----------------------------";
		 gotoxy(8,5);
		 cout<<"* Sleep early the night before,get up early the next morning, have";
		 gotoxy(8,6);
		 cout<<"  a proper breakfast and then study. ";
		 gotoxy(8,7);
		 cout<<"* Do not stay up late or waste time doing something that is counter";
		 gotoxy(8,8);
		 cout<<"  prouctive like worrying about what  might happen. Take out an hour";
		 gotoxy(8,9);
		 cout<<"  or two to relax and not think about the exams. Read,sleep,play or do";
		 gotoxy(8,10);
		 cout<<"  whatever you think diverts your attention away from exams.";
		 gotoxy(8,11);
		 cout<<"* Exercise you brain in a constructive way, and do not clutter it with";
		 gotoxy(8,12);
		 cout<<"  a lot of thoughts.";
		 gotoxy(8,13);
		 cout<<"* Be clear in your mind and do not pressure yourself to cover things";
		 gotoxy(8,14);
		 cout<<"  that are beyond your reach.";
		 gotoxy(8,15);
		 cout<<"* Make realistic targets for a day.Even Rome was not built in for a";
		 gotoxy(8,16);
		 cout<<"  day. Do not overdo things.";
		 gotoxy(8,17);
		 cout<<"* Do not try and study everything in a single day. Of the 5 or 6 ";
		 gotoxy(8,18);
		 cout<<"  subjects, pick up 2 or a maximum of  3 subjects and pick up a";
		 gotoxy(8,19);
		 cout<<"  topic or two from each and go into the depths of the topics, ";
		 gotoxy(8,20);
		 cout<<"  instead of skimming 8-10 topics.";
		 gotoxy(8,21);
		 cout<<"* Plan your day well. Like a good meal, it is important to have";
		 gotoxy(8,22);
		 cout<<"  all the essential ingredients while studying as well.";
		 gotoxy(8,23);
		 cout<<"* Do not have all easy subjects/topics in a day or do not over";
		 gotoxy(8,24);
		 cout<<"  burden yourself with topics that you find difficult.";
		 getch();
		 a.ac_disp(c);
		 break;




       case '4':clrscr();
		if(ctr==0)
		   disp();
		else
		   disp1(c);
		   break;

       default :clrscr();
		gotoxy(30,10);
		cout<<"WRONG CHOICE!!!!!!!!" ;
		getch();
		ac_disp(c);
		break;

	 }
    }

   void music::m_disp(char* a2)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"########## MUSIC ##########";
     gotoxy(32,6);
     cout<<"-----";
     gotoxy(25,7);
     cout<<"1. Bollywood Songs";
     gotoxy(25,9);
     cout<<"2. English Songs";
     gotoxy(25,11);
     cout<<"3. Return Back";
     gotoxy(26,13);
     cout<<"Enter Choice: ";
     cin>>ch;
     switch(ch)
	 {case '1':bsongs(a2);
		   m_disp(a2);
		   break;

	  case '2':hsongs(a2);
		   m_disp(a2);
		   break;

	  case '3':clrscr();
		    if(ctr==0)
		    disp();
		    else
		    disp1(a2);
		   break;

	  default :clrscr();
		   gotoxy(30,10);
		   cout<<"WRONG CHOICE!!!!!!!!" ;
		   getch();
		   m_disp(a2);
		   break;

	 }
  }

  void movies::mo_disp(char * b2)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"########## MOVIES ##########";
     gotoxy(32,6);
     cout<<"------";
     gotoxy(25,7);
     cout<<"1. Bollywood Movies";
     gotoxy(25,9);
     cout<<"2. Hollywood Movies";
     gotoxy(25,11);
     cout<<"3. Return Back";
     gotoxy(26,13);
     cout<<"Enter Choice:";
     cin>>ch;
     switch(ch)
	 {case '1':bmovies(b2);
		   mo_disp(b2);
		   break;

	  case '2':hmovies(b2);
		   mo_disp(b2);
		   break;

	  case '3':clrscr();
		   if(ctr==0)
		   disp();
		   else
		   disp1(b2);
		   break;

	  default :clrscr();
		   gotoxy(30,10);
		   cout<<"WRONG CHOICE!!!!!!!!" ;
		   getch();
		   mo_disp(b2);
		   break;

	 }
  }


  void games::g_disp(char* c)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"########## GAMES ##########";
     gotoxy(32,6);
     cout<<"-----";
     gotoxy(25,7);
     cout<<"1. Tic-Tac-Toe";
     gotoxy(25,9);
     cout<<"2. Casino - game";
     gotoxy(25,11);
     cout<<"3. Return Back";
     gotoxy(26,13);
     cout<<" Enter Choice:";
     cin>>ch;
     switch(ch)
	 {case '1':tic();
		   g_disp(c);
		   break;

	  case '2':casino();
		   g_disp(c);
		   break;

	  case '3':clrscr();
		  if(ctr==0)
		    disp();
		    else
		    disp1(c);
		   break;

	  default :clrscr();
		   gotoxy(30,10);
		   cout<<"WRONG CHOICE!!!!!!!!" ;
		   getch();
		   g_disp(c);
		   break;

	 }

  }


  void e_books::e_disp(char* c2)
    {
     clrscr();
     gotoxy(21,5);
     cout<<"########## E-BOOKS ##########";
     gotoxy(32,6);
     cout<<"-------";
     gotoxy(25,7);
     cout<<"1. Harry Potter And The Deathly Hallows";
     gotoxy(25,8);
     cout<<"2. Digital Fortress";
     gotoxy(25,9);
     cout<<"3. Twilight";
     gotoxy(25,10);
     cout<<"4. Alchemist";
     gotoxy(25,11);
     cout<<"5. 2 States";
     gotoxy(25,12);
     cout<<"6. Da vinci code";
     gotoxy(25,13);
     cout<<"7. Breaking Dawn";
     gotoxy(25,14);
     cout<<"8. The Road";
     gotoxy(25,15);
     cout<<"9. Return Back";
     gotoxy(26,17);
     cout<<"Enter choice: ";
     cin>>ch;
     switch(ch)
       {case '1':clrscr();
		 i=choice();
		 a:;
		 clrscr();
		 if(i==1)
		  {
		  gotoxy(25,3);
		  cout<<"Harry Potter And The Deathly Hallows";
		  gotoxy(8,5);
		  cout<<"Harry Potter and the Deathly Hallows is more than just the";
		  gotoxy(8,6);
		  cout<<"seventh and final installment in J.K. Rowling's epic wizardry";
		  gotoxy(8,7);
		  cout<<"series. It is the keystone, the culmination of the 4000 or so";
		  gotoxy(8,8);
		  cout<<"previous pages. Rowling brings to Deathly Hallows a fully-realized";
		  gotoxy(8,9);
		  cout<<"world, complete with history, mythology, and a vast web of";
		  gotoxy(8,10);
		  cout<<"characters intertwined thoroughly with that history, that mythology,";
		  gotoxy(8,11);
		  cout<<"and with each other.";
		  getch();
		  clrscr();
		  i=choice();
		  goto a;
		 }
		 if(i==0)
		  {clrscr();
		   gotoxy(27,10);
		   cout<<"DOWNLOADING - ";
		   d_load("Harry Potter And The Deathly Hallows",c2);
		   e_disp(c2);
		  }
		 if(i==2)
		 {           e_disp(c2);
		 }
		 else
		  {clrscr();
		   gotoxy(30,10);
		   cout<<"WRONG CHOICE!!!!!!!!" ;
		   getch();
		   i=choice();
		   goto a;
		   }
	case '2':clrscr();
		 i=choice();
		 b:;
		 clrscr();
		 if(i==1)
		  {gotoxy(25,3);
		   cout<<"Digital Fortress";
		   gotoxy(8,5);
		   cout<<"A New York Times #1 best-seller from the author who brought the";
		   gotoxy(8,6);
		   cout<<"world The Da Vinci Code this cyber-thriller revolves around the";
		   gotoxy(8,7);
		   cout<<"quest for an unbreakable encryption algorithm & the lengths some";
		   gotoxy(8,8);
		   cout<<"individuals will go to in order to acquire it.While letting the ";
		   gotoxy(8,9);
		   cout<<"world believe that certain strong encryption algorithms are too";
		   gotoxy(8,10);
		   cout<<"mathematically complicated to break in a reasonable amount of time";
		   gotoxy(8,11);
		   cout<<"given current technology, the NSA (National Security Association)";
		   gotoxy(8,12);
		   cout<<"has developed a machine which can break anything- until a new";
		   gotoxy(8,13);
		   cout<<"unbreakable encryption algorithm is created by an individual with a";
		   gotoxy(8,14);
		   cout<<"grudge against the NSA.The NSA find themselves in a position of";
		   gotoxy(8,15);
		   cout<<"needing to intercept and destroy the algorithm before it can be";
		   gotoxy(8,16);
		   cout<<"released to the world and render their spying efforts useless.";
		   gotoxy(8,17);
		   cout<<"Along the way there are twists & turns and different individuals";
		   gotoxy(8,18);
		   cout<<"with different agendas to add some excitement to the story.";
		   getch();
		   clrscr();
		   i=choice();
		   goto b;
		  }
		 if(i==0)
		  {clrscr();
		   gotoxy(27,10);
		   cout<<"DOWNLOADING - ";
		   d_load("DIGITAL FORTRESS",c2);
		   e_disp(c2);
		  }
		 if(i==2)
		 {           e_disp(c2);
		 }
		 else
		   {clrscr();
		    gotoxy(30,10);
		    cout<<"WRONG CHOICE!!!!!!!!" ;
		    getch();
		    i=choice();
		    goto b;
		   }
	case '3':clrscr();
		 i=choice();
		 c:;
		 clrscr();
		 if(i==1)
		  {gotoxy(25,3);
		   cout<<"Twilight";
		   gotoxy(8,5);
		   cout<<"Twilight is the story of Edward and Bella’s romance.Forget any ";
		   gotoxy(8,6);
		   cout<<"vampire romance you have read before,Twilight is so unique it is";
		   gotoxy(8,7);
		   cout<<"almost like it's in its own genre.The book is marketed at Young";
		   gotoxy(8,8);
		   cout<<"Adult readers but it has the ability to cross age barriers and will ";
		   gotoxy(8,9);
		   cout<<"satisfy both teenagers and adults alike.Twilight is simply and yet";
		   gotoxy(8,10);
		   cout<<"beautifully written.The descriptions of Forks leave you feeling like";
		   gotoxy(8,11);
		   cout<<"you can almost smell the damp air and hear the rain falling on the";
		   gotoxy(8,12);
		   cout<<"roof." ;
		   getch();
		   clrscr();
		   i=choice();
		   goto c;
		 }
		 if(i==0)
		  {clrscr();
		   gotoxy(27,10);
		   cout<<"DOWNLOADING - ";
		   d_load("TWILIGHT",c2);
		   e_disp(c2);
		  }
		 if(i==2)
		 {           e_disp(c2);
		 }
		 else
		   {clrscr();
		    gotoxy(30,10);
		    cout<<"WRONG CHOICE!!!!!!!!" ;
		    getch();
		    i=choice();
		    goto c;
		   }
	case '4':clrscr();
		 i=choice();
		 d:;
		 clrscr();
		 if(i==1)
		  {gotoxy(6,3);
		   cout<<"Alchemist";
		   gotoxy(8,5);
		   cout<<"In his journey, Santiago sees the greatness of the world, and meets";
		   gotoxy(8,6);
		   cout<<"all kinds of exciting people like kings and alchemists. However, by";
		   gotoxy(8,7);
		   cout<<"the end of the novel, he discovers that treasure lies where your";
		   gotoxy(8,8);
		   cout<<"heart belong,and that the treasure was the journey itself, the";
		   gotoxy(8,9);
		   cout<<"discoveries he made,and the wisdom he acquired.";
		   getch();
		   clrscr();
		   i=choice();
		   goto d;
		  }
		if(i==0)
		  {clrscr();
		  gotoxy(27,10);
		  cout<<"DOWNLOADING - ";
		  d_load("Alchemist",c2);
		  e_disp(c2);
		  }
		if(i==2)
		 {           e_disp(c2);
		 }
		else
		  { clrscr();
		    gotoxy(30,10);
		    cout<<"WRONG CHOICE!!!!!!!!" ;
		    getch();
		    i=choice();
		    goto d;
		  }
	case'5':clrscr();
		gotoxy(30,5);
		i=choice();
		e:;
		clrscr();
		if(i==1)
		 {gotoxy(6,3);
		  cout<<"2 states";
		  gotoxy(8,5);
		  cout<<"Chetan Bhagat latest book '2 States' is about a boy and girl from";
		  gotoxy(8,6);
		  cout<<"two different states of India,who fall in love and want to get";
		  gotoxy(8,7);
		  cout<<"married. Of course, their parents don't agree. What happens next";
		  gotoxy(8,8);
		  cout<<"is what the book is about. From the author of blockbusters Five";
		  gotoxy(8,9);
		  cout<<"Point Someone, One Night @ the Call Center and The 3 Mistakes of";
		  gotoxy(8,10);
		  cout<<"My Life,comes another witty tale - 2 states - about inter-community ";
		  gotoxy(8,11);
		  cout<<"marriages in modern india.";
		  getch();
		  clrscr();
		  i=choice();
		  goto e;
		 }
	       if(i==0)
		 {clrscr();
		  gotoxy(27,10);
		  cout<<"DOWNLOADING - ";
		  d_load("2 states",c2);
		  e_disp(c2);
		 }
	       if(i==2)
		 {           e_disp(c2);
		 }
	       else
		 { clrscr();
		   gotoxy(30,10);
		   cout<<"WRONG CHOICE!!!!!!!!" ;
		   getch();
		   i=choice();
		   goto e;
		 }
	case '6':clrscr();
		 gotoxy(30,5);
		 i=choice();
		 f:;
		 clrscr();
		 if(i==1)
		  {gotoxy(6,3);
		   cout<<"Da vinci code";
		   gotoxy(8,5);
		   cout<<"The Da Vinci Code by Dan Brown is a fast paced thriller where the";
		   gotoxy(8,6);
		   cout<<"main characters have to decipher clues in artwork, architecture and";
		   gotoxy(8,7);
		   cout<<"riddles to get to the bottom of a murder and save themselves.";
		   gotoxy(8,8);
		   cout<<"As a thriller, it is an O.K. pick, but not as good as Brown's Angels ";
		   gotoxy(8,9);
		   cout<<"and Demons.The main characters discuss unsubstantiated religious ideas";
		   gotoxy(8,10);
		   cout<<"as if they are facts (and Brown's page implies that they are). This may";
		   gotoxy(8,11);
		   cout<<"offend or annoy some readers.";
		   getch();
		   clrscr();
		   i=choice();
		   goto f;
		  }
		if(i==0)
		 {clrscr();
		  gotoxy(27,10);
		  cout<<"DOWNLOADING - ";
		  d_load("Da vinci code",c2);
		  e_disp(c2);
		 }
	       if(i==2)
		 {           e_disp(c2);
		 }
		else
		 {clrscr();
		  gotoxy(30,10);
		  cout<<"WRONG CHOICE!!!!!!!!" ;
		  getch();
		  i=choice();
		  goto f;
		 }

	case '7':clrscr();
		 gotoxy(30,5);
		 i=choice();
		 g:;
		 clrscr();
		 if(i==1)
		  {gotoxy(6,3);
		   cout<<"Breaking dawn ";
		   gotoxy(8,5);
		   cout<<"Breaking Dawn is the fourth and final novel in Stephenie Meyer's ";
		   gotoxy(8,6);
		   cout<<"hugely popular Twilight saga.With all the hype surrounding the";
		   gotoxy(8,7);
		   cout<<"release of Breaking Dawn I doubt that there is anyone left";
		   gotoxy(8,8);
		   cout<<"on the planet that isn’t aware of the books publication!  However,";
		   gotoxy(8,9);
		   cout<<"readers who haven't read any of the previous books in this saga";
		   gotoxy(8,10);
		   cout<<"should not be tempted to start here  you really need to read these ";
		   gotoxy(8,10);
		   cout<<"books in order since the story continues over the series.";
		   getch();
		   clrscr();
		   i=choice();
		   goto g;
		  }
		if(i==0)
		  {clrscr();
		   gotoxy(27,10);
		   cout<<"DOWNLOADING - ";
		   d_load("Breaking dawn ",c2);
		   e_disp(c2);
		  }
	       if(i==2)
		 {           e_disp(c2);
		 }
		else
		   { clrscr();
		     gotoxy(30,10);
		     cout<<"WRONG CHOICE!!!!!!!!" ;
		     getch();
		     i=choice();
		     goto g;
		   }
	case '8':clrscr();
		 gotoxy(30,5);
		 i=choice();
		 h:;
		 clrscr();
		 if(i==1)
		  {gotoxy(6,3);
		  cout<<"The ROAD";
		  gotoxy(8,5);
		  cout<<"Cormac McCarthy is one of the greatest novelists still alive today";
		  gotoxy(8,6);
		  cout<<"(a phantasm of Faulker),and his newest book, The Road, clearly";
		  gotoxy(8,7);
		  cout<<"exemplifies this claim. It's full of McCarthy's terse dialogue,";
		  gotoxy(8,8);
		  cout<<"minute detail (but not TOO much, like Blood Meridian)";
		  gotoxy(8,9);
		  cout<<"stream-of-consciousness,masculinity, and an excruciatingly intense";
		  gotoxy(8,10);
		  cout<<"violent plot (win!). Not to mention that,in addition to all of these";
		  gotoxy(8,11);
		  cout<<"things,it's also overwhelmingly sad, which is not an easy thing";
		  gotoxy(8,10);
		  cout<<"for a novel to be. It’s the perfect combination of everything, with";
		  gotoxy(8,11);
		  cout<<"exact measurements dolled out like a recipe for brownies.";
		  getch();
		  clrscr();
		  i=choice();
		  goto h;
		 }
	       if(i==0)
		 {clrscr();
		  gotoxy(27,10);
		  cout<<"DOWNLOADING - ";
		  d_load("The ROAD",c2);
		  e_disp(c2);
		 }
		 if(i==2)
		 {           e_disp(c2);
		 }
	       else
		 { clrscr();
		   gotoxy(35,10);
		   cout<<"WRONG CHOICE!!!!!!!!" ;
		   getch();
		   i=choice();
		   goto h;
		 }
      case '9':clrscr();
		  if(ctr==0)
		     disp();
		  else
		     disp1(c2);
		  break;
       default:clrscr();
	       gotoxy(30,10);
	       cout<<"WRONG CHOICE!!!!!!!!" ;
	       getch();
	       e_disp(c2);
	       break;

      }
     getch();
    }


   void news::s_disp(char* c)
    {
     clrscr();
     gotoxy(21,2);
     cout<<"########## N.E.W.S ##########";
     gotoxy(32,3);
     cout<<"-------";
     gotoxy(30,4);
     cout<<"SPORTS";
     gotoxy(4,5);
     cout<<"-> INDIA to open 2014 ICC World Twenty20 campaign against Pakistan";
     gotoxy(4,6);
     cout<<"-> Chelsea's Mourinho indebted to Fernando Torres determination";
     gotoxy(4,7);
     cout<<"-> Michael Clarke poised for comeback with NSW";
     gotoxy(30,9);
     cout<<"CITY";
     gotoxy(4,10);
     cout<<"-> Defamation Case:Rs.5,000 fine imposed on Shiela Dikshit";
     gotoxy(4,11);
     cout<<"-> Sacked woman kills boss' son";
     gotoxy(30,13);
     cout<<"INDIA";
     gotoxy(4,14);
     cout<<"-> Patna Blasts: Key accused has confessed,probe on,cops say";
     gotoxy(4,15);
     cout<<"-> Infosis introduces onsite rotation policy for staff";
     gotoxy(4,16);
     cout<<"-> Treasure trove worth Rs.4,000Cr found in Bundelkhand";
     gotoxy(30,18);
     cout<<"WORLD";
     gotoxy(4,19);
     cout<<"-> US monitered 60M calls in Spain in a month";
     gotoxy(4,20);
     cout<<"-> Soldier killed in Pakistan firing in J&K";
     gotoxy(4,21);
     cout<<"-> Lou Reed, iconic Punk Poet, dead at 71";
     gotoxy(30,23);
     cout<<"TECH";
     gotoxy(4,24);
     cout<<"-> ET:How to use Internet to your advantage in Job search ";
     gotoxy(4,25);
     cout<<"-> Samsung India Launches its most expensive Smart Phone";
     getch();
     clrscr();
     if(ctr==0)
	disp();
     else
	disp1(c);
  }





  void password()
    {clrscr();
     char a,b,c,d,e,x[20];
     gotoxy(1,5);
     cout<<"================================================================================";
     gotoxy(1,20);
     cout<<"================================================================================";
     gotoxy(10,9);
     cout<<" ----------------";
     gotoxy(10,10);
     cout<<"| Enter USERNAME | :";
     gotoxy(10,11);
     cout<<" ----------------";
     gotoxy(34,9);
     cout<<" ------------";
     gotoxy(34,11);
     cout<<" ------------";
     gotoxy(33,10);
     cout<<" |";
     gotoxy(46,10);
     cout<<" |";
     gotoxy(38,10);
     gets(x);
     gotoxy(1,20);
     cout<<"================================================================================";
     gotoxy(10,14);
     cout<<" ----------------";
     gotoxy(10,15);
     cout<<"| Enter PASSWORD | :";
     gotoxy(10,16);
     cout<<" ----------------";
     gotoxy(34,14);
     cout<<" ------------";
     gotoxy(34,16);
     cout<<" ------------";
     gotoxy(33,15);
     cout<<" |";
     gotoxy(46,15);
     cout<<" |";
     gotoxy(38,15);
     a=getch();
     cout<<"*";
     b= getch();
     cout<<"*";
     c= getch();
     cout<<"*" ;
     d= getch();
     cout<<"*";
     e= getch();
     cout<<"*";
     getch();
     if(a=='t'&&b=='u'&&c=='r'&&d=='b'&&e=='o')
       {
	 gotoxy(31,18);
	 cout<<"LOADING";
	 //delay(500);
	 cout<<".";
	 //delay(500);
	 cout<<".";
	 //delay(500);
	 cout<<".";
	 //delay(500);
	 cout<<".";
	 //delay(500);
	 cout<<".";
	 clrscr();
	 disp();
      }
      cnt++;
      if(cnt<=2)
      { clrscr();
	gotoxy(30,10);
	cout<<"WRONG PASSWORD!!!!!";
	gotoxy(29,12);
	cout<<"You have "<<(3-cnt)<<" trials left";
	getch();
	password();
      }
      else
     {exit(0);
     }


  }

//***************************************************************************
//    THE MAIN FUNCTION OF PROGRAM
//***************************************************************************


  void main()
    {
     clrscr();


     password();
     getch();
    }


//***************************************************************************
//         END OF PROJECT
//***************************************************************************
