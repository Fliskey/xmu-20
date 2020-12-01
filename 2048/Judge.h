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
			
			for(int k=1;k<=4;k++){
				switch(k){
					case 1:{
						//UP:
						row = j;
						clo = i;
						break;
					}
					case 2:{
						//DOWN:
						row = 4-j+1;
						clo = i;
						break;
					}
					case 3:{
						//LEFT:
						row = i;
						clo = j;
						break;
					}
					case 4:{
						//RIGHT:
						row = i;
						clo = 4-j+1;
						break;
					}
				}
				if(k <= 2){
					if(value[k] == board[row][clo]){
						return 0;
					}
					else{
						value[k] = board[row][clo];
						locate[k] = row;
					}
				}
				else{
					if(value[k] == board[row][clo]){
						return 0;
					}
					else{
						value[k] = board[row][clo];
						locate[k] = clo;
					}
				}
			}
		}
	}

	return 1;
}


int Failed(){
	printf("-------- Gameover --------\nCan't Add Number anymore!\n");
}

int Succeed(){
	printf("-------- You win --------\nYou have merged a %d!\n",TARGET);
}
