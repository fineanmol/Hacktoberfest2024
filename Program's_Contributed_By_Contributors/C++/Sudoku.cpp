#include <bits/stdc++.h>

using namespace std;

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"       
#define BOLDGREEN   "\033[1m\033[32m"      

int play[9][9] = {0};

bool is_safe(int row, int col, int num);
bool find_0(int &i, int &j);
bool find_in_row(int j, int key);
bool find_in_column(int i, int key);
bool find_in_box(int row, int col, int key);

void Board(){

    for (int i=0; i<9; i++){
        if (i==0 || i==3 || i==6){
            cout<<BOLDRED<<"-------------------------------------"<<RESET<<endl;
        }
        for (int j=0; j<9; j++){
            cout<<BOLDGREEN<<"|"<<RESET<<" "<<play[i][j]<<" ";
            if (j==8){
                cout<<BOLDGREEN<<"|"<<RESET;
            }
        }
        cout<<endl;
        if (i==0 || i==1 || i==3 || i==4 || i==6 || i==7){
            cout<<"-------------------------------------"<<endl;
        }
        if (i==8){
            cout<<BOLDRED<<"-------------------------------------"<<RESET<<endl;
        }
    }
}

bool solve(){

    int row, col;

    if (!find_0(row, col)){
        return true;
    }
    
    for (int sol=1; sol<=9; sol++){
        if (is_safe(row, col, sol)){
            play[row][col] = sol;
            if (solve()){
                return true;
            }
            play[row][col] = 0;
        }
    }

    return false;
}

bool is_safe(int row, int col, int num){
    return !find_in_row(row, num) && !find_in_column(col, num) && !find_in_box(row - row%3, col - col%3, num) && (play[row][col] == 0);
}

bool find_0(int &i, int &j){
    for ( i=0; i<9; i++){
        for ( j=0; j<9; j++){
            if (play[i][j] == 0){
                return true;
            }
        }
    }

    return false;
}

bool find_in_row(int i, int key){
    for (int j=0; j<9; j++){
        if (play[i][j] == key){
            return true;
        }
    }

    return false;
}

bool find_in_column(int j, int key){
    for (int i=0; i<9; i++){
        if (play[i][j] == key){
            return true;
        }
    }

    return false;
}

bool find_in_box(int row, int col, int key){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (play[i+row][j+col] == key){
                return true;
            }
        }
    }

    return false;
}

int main(){

    Board();
    
    cout<<"Enter all the numbers in sudoku and give 0 for the elements to be inserted.\n";
    cout<<"Make sure to enter elements from left to right: \n";
    
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin>>play[i][j];
        }
    }

    cout<<"Your entered elements are: \n";
    Board();

    if (solve()){
        Board();
    }
    else {
        cout<<"No solution exist.\n";
    }

    return 0;
}