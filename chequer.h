#pragma once
#include "game_check.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>

using namespace std;

class chequer
{
public:
    int pos_x;
    int pos_y;


};

    void newGame(char **board, int size);
    char **initBoard(int bsize);
    void display_board(char **board);
