//-------- 2048GAME --------
//0474-Fliskey

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

//define const : direction
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


//global variable
int board[6][6];


//declear function
int InitBoard();
int SetRandom();
int ClearBoard();
int PrintBoard();

//main function
int main(){
    
    return 0;
}



//-------- function realize --------

int SetRandom(){
	int puted = 0;
	
	int tried[6][6];
	int remain = 16;
	
	memset(tried,0,sizeof(tried));
	
	while(!puted){
		int t=rand()%16;
		int i = t/4 +1;
		int j = t%4 +1;
		
		if(remain == 0){
			printf("CAN'T PUT!\n");
			return 0;
		}
		
		if(tried[i][j]){
			continue;
		}
		else if(board[i][j]){
			if(!tried[i][j]){
				tried[i][j] = 1;
				remain--;
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
    memset(board,0,sizeof(board));
    return 1;
}

int InitBoard(){
    ClearBoard();
    SetRandom();
    SetRandom();
    return 1;
}

int PrintBoard(){

}