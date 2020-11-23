//-------- 2048GAME:enter --------
//0474-Fliskey

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "test.h"
#include "Borad_core.h"
#include "Judge.h"

//global variable
int board[6][6] = {0};
int maxvalue = 0;


//---------------- MAIN FUNCTION ----------------
int main(){
	srand((int)time(NULL)); 
	InitBoard();
	PrintBoard();
	
	while(1){
		int der = GetInput();
		int perform = 0;
		perform += Merge(der);
		perform += Move(der);
		if(!perform){
		//	printf("0\n");
			continue;
		}
		else{
			maxvalue = MAX(SetRandom(),maxvalue);
			ClearS();
			PrintBoard();
		//	printf("max:%d\n",maxvalue);
			if(maxvalue == 2048){
				Succeed();
				return 0;
			}

			int jg = FailJudge();
			if(jg){
				Failed();
				return 0;
			}
		//	printf("perform:%d\n",perform);
		}
	}

    return 0;
}