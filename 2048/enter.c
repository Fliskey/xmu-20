//-------- 2048GAME:enter --------
//0474-Fliskey

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//functions declear
#include "Borad_core.h"
#include "Judge.h"
#include "modes.h"
#include "Save.h"

//global variable
const int TARGET=32;
int board[6][6] = {0};
int maxvalue = 0;
int goal = 0;

int save_goals[1004];
int save_board[1004][6][6];
int save_maxvalue[1004];
int save_point = 0;
int max_save_number = 1000;
 

//---------------- MAIN FUNCTION ----------------
int main(){
	srand((int)time(NULL)); 
	while(mode_gaming() == RESTART);
	
    return 0;
}
