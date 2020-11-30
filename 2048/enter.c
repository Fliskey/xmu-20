//-------- 2048GAME:enter --------
//0474-Fliskey

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
//#include "test.h"
#include "Borad_core.h"
#include "Judge.h"
#include "modes.h"

//global variable
const int TARGET=64;
int board[6][6] = {0};
int maxvalue = 0;
int goal = 0;

//function declear
int InitBoard();
int SetRandom();

int Merge(int);
int Move(int);

int ClearBoard();
void ClearS();
int PrintBoard();

int GetInput();
int FailJudge();
int Failed();
int Succeed();
 

//---------------- MAIN FUNCTION ----------------
int main(){
	srand((int)time(NULL)); 
	mode_gaming();

    return 0;
}
