//-------- 2048GAME:Judge --------
//0474-Fliskey

//global var
extern int board[6][6];
extern const int TARGET;

int FailJudge();
int Failed();
int Succeed();

int FailJudge(){
	int if_merged = 0;
	for(int i=1;i<=4;i++){
		int value[5] = {0};
		int locate[5] = {0};
		for(int j=1;j<=4;j++){
			if(!board[i][j]){
			//	printf("1 %d %d\n",i,j);
				return 0;
			}
			//if didn't return 0 then judge whether can merge
			int row;
			int clo;
			//UP:
			row = j;
			clo = i;
			
				if(value[1] == board[row][clo]){
				//	printf("21 %d %d\n",i,j);
					return 0;
				}
				else{
					value[1] = board[row][clo];
					locate[1] = row;
				}
					
			//DOWN:
			row = 4-j+1;
			clo = i;
			
				if(value[2] == board[row][clo]){
				//	printf("22 %d %d\n",i,j);
					return 0;
				}
				else{
					value[2] = board[row][clo];
					locate[2] = row;
				}
					
			//LEFT:
			row = i;
			clo = j;
			
				if(value[3] == board[row][clo]){
				//	printf("23 %d %d\n",i,j);
					return 0;
				}
				else{
					value[3] = board[row][clo];
					locate[3] = clo;
				}
					
			//RIGHT:
			row = i;
			clo = 4-j+1;
			
				if(value[4] == board[row][clo]){
				//	printf("24 %d %d\n",i,j);
					return 0;
				}
				else{
					value[4] = board[row][clo];
					locate[4] = clo;
				}
		}
	}

	return 1;
}


int Failed(){
	printf("Can't Add Number anymore!\n-------- Gameover --------");
}

int Succeed(){
	printf("You have merged a %d!\n-------- You win --------",TARGET);
}
