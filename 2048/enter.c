//-------- 2048GAME:enter --------

/*--------------------------------------\
|                                       |
|   Author: Yuxiang Wang(Fliskey)       |
|   ID:     13720192200474              |
|   Email:  Fliskey@qq.com              |
|                                       |
|   Last update time:   Dec.2 2020      |
|                                       |
\--------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//functions declear
#include "Headfiles/Borad_core.h"
#include "Headfiles/Judge.h"
#include "Headfiles/Save.h"
#include "Headfiles/Modes.h"

//global variable
const int TARGET=2048;
int board[6][6] = {0};
int maxvalue = 0;
int goal = 0;

int save_goals[34];
int save_board[34][6][6];
int save_maxvalue[34];
int save_point = 0;
int max_save_number = 30;
 

//---------------- MAIN FUNCTION ----------------
int main(){
    srand((int)time(NULL)); 
    while(mode_gaming() == RESTART);
    return 0;
}
