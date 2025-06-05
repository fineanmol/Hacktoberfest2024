#ifndef TEENY_H_INCLUDED
#define TEENY_H_INCLUDED
#include <windows.h>
#include <conio.h>

//some macros for readability
#define ESCAPE 27
#define ARROW_LEFT  75
#define ARROW_RIGHT 77
#define BACKSPACE 8
#define INSERT 82
#define F1 59
#define F2 60
#define F3 61
#define F5 63
#define SPECIAL_KEY(x) (x==0 || x==0xE0)

//Global variable for screen dimensions
COORD dims;

/*Note: the following method allows you to write a writer a character
anywhere on the screen. It moves the screen cursor to the same position as well.
This method can make it easier for you to color single characters during
printing. You can also choose not to use it and work with cout.*/
void gotoxy(int xpos, int ypos, int col, char ch)
{
 COORD scrn;
 HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
 scrn.X = xpos; scrn.Y = ypos;
 SetConsoleCursorPosition(hOuput,scrn);
 HANDLE  screen=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(screen,col);
 DWORD useless;
 WriteConsole(screen,&ch,1,(LPDWORD)&useless,NULL);
 SetConsoleTextAttribute(screen,15);
 SMALL_RECT windowSize = {0, 0, 100, 100};
 SetConsoleWindowInfo(screen, TRUE, &windowSize);
}

COORD GetConsoleWindowDims(){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    SMALL_RECT srctWindow;
    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
    srctWindow = csbiInfo.srWindow;
    dims.X=srctWindow.Right;
    dims.Y=srctWindow.Bottom;
	return dims;
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

void moveScreenCursorLeft(){
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = GetConsoleCursorPosition(hOuput);
        if(pos.X>0)
            pos.X--;
        else if(pos.Y>0){
            pos.Y--;
            pos.X=dims.X;
        }
    SetConsoleCursorPosition(hOuput,pos);
}

void moveScreenCursorRight(){
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = GetConsoleCursorPosition(hOuput);
        if(pos.X<dims.X)
            pos.X++;
        else if(pos.Y<dims.Y){
            pos.Y++;
            pos.X=0;
        }
    SetConsoleCursorPosition(hOuput,pos);
}

#endif // TEENY_H_INCLUDED
