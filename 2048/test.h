//-------- 2048GAME:test --------
//0474-Fliskey

extern int board[6][6];
extern int maxvalue;

#define MAX(x,y) x>y?x:y

/*
int test(){
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
}

int testboard1(){
	ClearBoard();
	board[1][1] = 8;
	board[2][1] = 4;
	board[3][1] = 4;
	board[4][1] = 4;
}

int testboard2(){
	ClearBoard();
	board[1][1]=1;board[1][2]=2;board[1][3]=3;board[1][4]=4;
	board[2][1]=5;board[2][2]=6;board[2][3]=7;board[2][4]=8;
	board[3][1]=9;board[3][2]=10;board[3][3]=11;board[3][4]=12;
	board[4][1]=13;board[4][2]=14;board[4][3]=14;board[4][4]=16;
}*/

int testDec1(){
	InitBoard();
	ClearS();
	PrintBoard();
	save_push();
	scanf("\n");
	SetRandom();
	ClearS();
	PrintBoard();
	scanf("\n");
	save_pop();
	ClearS();
	PrintBoard();
	scanf("\n");
	return 0;
}
