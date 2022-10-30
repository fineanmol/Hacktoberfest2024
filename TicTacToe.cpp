#include <iostream>
using namespace std;
char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
bool run =1;
int row=9, col=9, draw = 0;


void board() //Display basic board
{
    system("cls"); //to clear previous screen
    cout << "*******************************************************************************\n";
    cout << "\t\t Tic Tac Toe by Gagandeep Singh\n";
    cout << "*******************************************************************************\n";
    cout << endl << "\t\t Player 1 is X" << endl << "\t\t Player 2 is O" << endl;
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<"  \n";
    cout << "\t\t     |     |     \n";
}

void pturn()
{
    if(turn == 'X')
        cout << "\t\n Player 1 X turn \n";
    else if(turn == 'O')
        cout << "\t\n Player 2 O turn \n";
    int choice;
    cin >> choice;
    switch(choice) //Taking Input
    {
        case 1:
            row=0; col=0;
            break;
        case 2:
            row=0; col=1;
            break;
        case 3:
            row=0; col=2;
            break;
        case 4:
            row=1; col=0;
            break;
        case 5:
            row=1; col=1;
            break;
        case 6:
            row=1; col=2;
            break;
        case 7:
            row=2; col=0;
            break;
        case 8:
            row=2; col=1;
            break;
        case 9:
            row=2; col=2;
            break;
        default : cout << "Invalid Choice \n"; 
    }
    /*
        Turn Switch and Prevention of changing other's marking
    */
    if(turn == 'X' && grid[row][col] != 'X' && grid[row][col] != 'O')
    {
        grid[row][col] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && grid[row][col] != 'X' && grid[row][col] != 'O')
    {
        grid[row][col] = 'O';
        turn = 'X';
    }    
    else
    {
        cout << "Wrong Input";
        pturn(); //Asking for input again here
    }
    board();
}

bool game()
{
    //win
    //horizontal
    for(int i=0; i<=2; i++)
        if(grid[i][0]==grid[i][1] && grid[i][0]== grid[i][2])
            return 0;
    //vertical
    for(int i=0; i<=2; i++)
        if(grid[0][i]==grid[1][i] && grid[0][i]== grid[2][i])
            return 0;
    //diagonals
    if(grid[0][0]==grid[1][1] && grid[1][1]== grid[2][2])
            return 0;
    if(grid[0][2]==grid[1][1] && grid[1][1]== grid[2][0])
            return 0;    
    //game running
    for(int i=0; i<=2; i++)
        for(int j=0; j<=2; j++)
            if(grid[i][j] != 'X' && grid[i][j] != 'O')
                return 1;
    //draw
    draw = 1;
    return 0;
}

void ending()
{
    if(draw == 1)
        cout << "\t\tGame Draw";
    else if(turn == 'X')
        cout << "Player 2 WINS!!!";
    else if(turn == 'O')
        cout << "Player 1 WINS!!!";
    cout << "\n\t\tGAME OVER TATA";
}


int main()
{
    while(run)
    {
        board();
        pturn();
        run = game();
    }
    ending();
    return 0;
}
