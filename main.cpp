#include <iostream>
#include "game_check.h"
#include <string>
#include "chequer.h"
#include "chequer.cpp"
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    char **board;
    board = initBoard(8);
    newGame(board, 8);
    display_board(board);
    return 0;
}
