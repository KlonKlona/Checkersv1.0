#include <iostream>
#include <cstdio>
#include "chequer.h"
#include <iomanip>

using namespace std;

void newGame(char **board, int bsize)
{
    for(int i = 0 ; i < bsize ; i++)
        for(int j = 0 ; j < bsize ; j++)
        {
            board[i][j] = '-';
            if((i == 0 || i == 2) && j % 2 == 1) board[i][j] = 'w';
            if(i == 1 && j % 2 == 0 ) board[i][j] = 'w';
            if((i == bsize - 3 || i == bsize - 1) && j % 2 == 0) board[i][j] = 'b';
            if(i == bsize - 2 && j % 2 == 1) board[i][j] = 'b';
        }
    return;
}

char** initBoard(int bsize)
{
    char **board = new char*[bsize];
    for(int i = 0; i < bsize ; i++)
        board[i] = new char[bsize];
    return board;
}

void do_move (char **board, Move play)
{
    char temp = board[play.start.first][play.start.second];
    board[play.start.first][play.start.second] = board[play.end.first][play.end.second];
    board[play.end.first][play.end.second] = temp;
    if(play.lethal)
    {
        board[(play.end.first + play.start.first) / 2][(play.end.second + play.start.second) / 2] = '-';
    }
}

void undo_move(char **board, Move play)
{
    board[play.start.first][play.start.second] = board[play.end.first][play.end.second];
    board[play.end.first][play.end.second] = '-';
    if (play.lethal)
    {
        if (board[play.start.first][play.start.second] == 'w')
            board[(play.end.first + play.start.first) / 2][(play.end.second + play.start.second) / 2] = 'b';
        if (board[play.start.first][play.start.second] == 'b')
            board[(play.end.first + play.start.first) / 2][(play.end.second + play.start.second) / 2] = 'w';
    }
}

vector<Move> findMoves(char **board, int size, bool WhiteTurn)
{

}

void display_board(char **board)//board displayed is similar to tic tac toe except its bigger, has empty spaces
{
    cout << "==================================================================================\n\n\n\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
    cout << "  _________________________________________________________________________________\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "0 |    " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    "  << board[0][3] << "    |    " << board[0][4] << "    |    " << board[0][5] << "    |    " << board[0][6] << "    |    " << board[0][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "1 |    " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    "  << board[1][3] << "    |    " << board[1][4] << "    |    " << board[1][5] << "    |    " << board[1][6] << "    |    " << board[1][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "2 |    " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    "  << board[2][3] << "    |    " << board[2][4] << "    |    " << board[2][5] << "    |    " << board[2][6] << "    |    " << board[2][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "3 |    " << board[3][0] << "    |    " << board[3][1] << "    |    " << board[3][2] << "    |    "  << board[3][3] << "    |    " << board[3][4] << "    |    " << board[3][5] << "    |    " << board[3][6] << "    |    " << board[3][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "4 |    " << board[4][0] << "    |    " << board[4][1] << "    |    " << board[4][2] << "    |    "  << board[4][3] << "    |    " << board[4][4] << "    |    " << board[4][5] << "    |    " << board[4][6] << "    |    " << board[4][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "5 |    " << board[5][0] << "    |    " << board[5][1] << "    |    " << board[5][2] << "    |    "  << board[5][3] << "    |    " << board[5][4] << "    |    " << board[5][5] << "    |    " << board[5][6] << "    |    " << board[5][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "6 |    " << board[6][0] << "    |    " << board[6][1] << "    |    " << board[6][2] << "    |    "  << board[6][3] << "    |    " << board[6][4] << "    |    " << board[6][5] << "    |    " << board[6][6] << "    |    " << board[6][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "7 |    " << board[7][0] << "    |    " << board[7][1] << "    |    " << board[7][2] << "    |    "  << board[7][3] << "    |    " << board[7][4] << "    |    " << board[7][5] << "    |    " << board[7][6] << "    |    " << board[7][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}


