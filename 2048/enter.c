//-------- 2048GAME --------
//0474-Fliskey

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

//define const
//%=2 direction
#define UP 12
#define DOWN 22
#define LEFT 32
#define RIGHT 42


//global variable
int board[6][6];


//declear function
int InitBoard();
int SetRandom();
int ClearBoard();
void ClearS();
int PrintBoard();
int GetInput();

int Merge(int);
int Move(int);

int FailJudge();
int Failed();

int test();
int testboard1();


//---------------- MAIN FUNCTION ----------------
int main(){
    test();
    return 0;
}


//---------------- realize function ----------------

int test(){
	srand((int)time(NULL)); 
	InitBoard();
	PrintBoard();
	
	while(1){
		int der = GetInput();
		int perform = 0;
		perform += Merge(der);
		perform += Move(der);
		if(FailJudge()){
			Failed();
			return 0;
		}
		else if(!perform){
			printf("0\n");
			continue;
		}
		else{
			SetRandom();
			ClearS();
			PrintBoard();
			printf("perform:%d\n",perform);
		}
	}
}

int testboard1(){
	ClearBoard();
	board[1][1] = 8;
	board[2][1] = 4;
	board[3][1] = 4;
	board[4][1] = 4;
}

int FailJudge(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(board[i][j]){
				return 0;
			}
		}
	}
	//if didn't return 0 then:
	
	
}

int SetRandom(){
	int puted = 0;
	
	int tried[6][6];
//	int remain = 16;
	
	memset(tried,0,sizeof(tried));
	
	while(!puted){
		int t=rand()%16;
		int i = t/4 +1;
		int j = t%4 +1;
		
		/*
		if(remain == 0){
			Failed();
			return 0;
		}
		*/
		
		if(tried[i][j]){
			continue;
		}
		else if(board[i][j]){
			if(!tried[i][j]){
				tried[i][j] = 1;
			//	remain--;
			}
			continue;
		}
		else if(!board[i][j]){
			int value = 2*(rand()%2+1);
			board[i][j] = value;
			return 1;
		}
		else{
			printf("ERROR!\n");
		}
	}
	
}

int ClearBoard(){
    memset(board,-1,sizeof(board));
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			board[i][j] = 0;
		}
	}
    return 1;
}

int InitBoard(){
    ClearBoard();
    SetRandom();
    SetRandom();
    return 1;
}

void ClearS(){
	system("cls");
}

int PrintBoard(){
//	system("cls");
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			printf("%-4d",board[i][j]);
		} 
		printf("\n");
	}
	printf("\n");
}

int Merge(int direction){
	int if_merged = 0;
	for(int i=1;i<=4;i++){
		int value = 0;
		int locate = 0;
		for(int j=1;j<=4;j++){
			switch(direction){
				case UP:{
					int row = j;
					int clo = i;
					if(board[row][clo]){
						if(value == board[row][clo]){
							if_merged = 1;
							value *= 2;
							board[locate][clo] = value;
							board[row][clo] = 0;
							value = 0;
							locate = 0;
						}
						else{
							value = board[row][clo];
							locate = row;
						}
					}
					break;
				}
				case DOWN:{
					int row = 4-j+1;
					int clo = i;
					if(board[row][clo]){
						if(value == board[row][clo]){
							if_merged = 1;
							value *= 2;
							board[locate][clo] = value;
							board[row][clo] = 0;
							value = 0;
							locate = 0;
						}
						else{
							value = board[row][clo];
							locate = row;
						}
					}
					break;
				}
				case LEFT:{
					int row = i;
					int clo = j;
					if(board[row][clo]){
						if(value == board[row][clo]){
							if_merged = 1;
							value *= 2;
							board[row][locate] = value;
							board[row][clo] = 0;
							value = 0;
							locate = 0;
						}
						else{
							value = board[row][clo];
							locate = clo;
						}
					}
					break;
				}
				case RIGHT:{
					int row = i;
					int clo = 4-j+1;
					if(board[row][clo]){
						if(value == board[row][clo]){
							if_merged = 1;
							value *= 2;
							board[row][locate] = value;
							board[row][clo] = 0;
							value = 0;
							locate = 0;
						}
						else{
							value = board[row][clo];
							locate = clo;
						}
					}
					break;
				}
			}
		}
	}
	return if_merged; 
}

int Move(int direction){
	int if_moved = 0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			switch(direction){
				//UP or DOWN:loop by cloumns
				case UP:{
					int row = j;
					int clo = i;
					while(board[row][clo] == 0 && row<=4){
						row++;
					}
					if(row !=5 && j != row){
						board[j][i] = board[row][clo];
						if_moved = 1;
						board[row][clo] = 0;
					}
					break;
				}
				case DOWN:{
					int row = 4-j+1;
					int clo = i;
					while(board[row][clo] == 0 && row > 0){
						row--;
					}
					if(row != 0 &&(4-j+1) != row){
						board[4-j+1][i] = board[row][clo];
						if_moved = 1;
						board[row][clo] = 0;
					}
					break;
				}
				
				//LEFT or RIGHT:loop by rows
				case LEFT:{
					int row = i;
					int clo = j;
					while(board[row][clo] == 0 && clo<=4){
						clo++;
					}
					if(clo != 5 && j != clo){
						board[i][j] = board[row][clo];
						if_moved = 1;
						board[row][clo] = 0;
					}
					break;
				}
				case RIGHT:{
					int row = i;
					int clo = 4-j+1;
					while(board[row][clo] == 0 && clo>0){
						clo--;
					}
					if(clo != 0 && (4-j+1) != clo){
						board[i][4-j+1] = board[row][clo];
						if_moved = 1;
						board[row][clo] = 0;
					}
					break;
				}
			}
		}
	}
	return if_moved;
}

int GetInput(){
	char c = getch();
	switch(c){
		//-32 : the head value of direction
		case -32:{
			c = getch();
			int direction = 0;
			switch(c){
				case 72:{
					direction = UP;
					break;
				}
				case 80:{
					direction = DOWN;
					break;
				}
				case 75:{
					direction = LEFT; 
					break;
				}
				case 77:{
					direction = RIGHT;
					break;
				}
			}
			return direction;
		}
		default:{

			break;
		}
	}
}

int Failed(){
	printf("Can't Add Number anymore!\n---- Gameover ----");
}