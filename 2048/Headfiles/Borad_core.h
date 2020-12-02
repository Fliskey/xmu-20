//-------- 2048GAME:Borad_core --------

/*--------------------------------------\
|										|
|	Author:	Yuxiang Wang(Fliskey)		|
|	ID:		13720192200474				|
|	Email:	Fliskey@qq.com				|
|										|
|	Last update time:	Dec.2 2020		|
|										|
\--------------------------------------*/

//define const
//direction
#define UP 12
#define DOWN 22
#define LEFT 32
#define RIGHT 42
#define PAUSE 11

//global var
extern int board[6][6];
extern int maxvalue;
extern int goal;


//declear function
#define MAX(x,y) x>y?x:y
int InitBoard();
int SetRandom();

int Merge(int);
int Merge_cldfunc(int*,int*,int*,int,int,int);
int Move(int);
int Move_cldfunc(int,int,int,int,int*,int);

int ClearBoard();
void ClearS();
int PrintBoard();

int GetInput();


//---------------- realize function ----------------

//-------- init & setrandom --------
int InitBoard(){
    goal = 0;
    ClearBoard();
	int x1,x2;
    x1 = SetRandom();
    x2 = SetRandom();
	int maxvalue = MAX(x1,x2);
//	printf("%d\n",maxvalue);
    return maxvalue;
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
		//	printf("%d\n",value);
			return value;
		}
		else{
			printf("ERROR!\n");
		}
	}
}

//-------- merge --------
int Merge(int direction){
	int if_merged = 0;		
	for(int i=1;i<=4;i++){
		int value = 0;
		int locate = 0;
		for(int j=1;j<=4;j++){
			switch(direction){
				case UP:{
					Merge_cldfunc(&value,&if_merged,&locate,j,i,direction);
					break;
				}
				case DOWN:{
					Merge_cldfunc(&value,&if_merged,&locate,4-j+1,i,direction);
					break;
				}
				case LEFT:{
					Merge_cldfunc(&value,&if_merged,&locate,i,j,direction);
					break;
				}
				case RIGHT:{
					Merge_cldfunc(&value,&if_merged,&locate,i,4-j+1,direction);
					break;
				}
			}
		}
	}
	return if_merged; 
}

int Merge_cldfunc(int *value,int *if_merged,int *locate,int row,int clo,int direction){
	if(board[row][clo]){
		if(*value == board[row][clo]){
			*if_merged = 1;
			*value *= 2;
			goal += *value;
			maxvalue = MAX(maxvalue,*value);
            if(direction == UP || direction == DOWN){
                board[*locate][clo] = *value;
            }
            else{
                board[row][*locate] = *value;
            }
			board[row][clo] = 0;
			*value = 0;
			*locate = 0;
		}
		else{
			*value = board[row][clo];
            if(direction == UP || direction == DOWN){
                *locate = row;
            }
			else{
                *locate = clo;
            }
		}
	}
}

//-------- move --------
int Move(int direction){
    int if_moved = 0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            switch(direction){
                case UP:{
                    Move_cldfunc(j,i,1,0,&if_moved,direction);
                    break;
                }
                case DOWN:{
                    Move_cldfunc(4-j+1,i,-1,0,&if_moved,direction);
                    break;
                }
                case LEFT:{
                    Move_cldfunc(i,j,0,1,&if_moved,direction);
                    break;
                }
                case RIGHT:{
                    Move_cldfunc(i,4-j+1,0,-1,&if_moved,direction);
                    break;
                }
            }
        }
    }
	return if_moved;
}

int Move_cldfunc(int row,int clo,int rp,int cp,int *if_moved,int direction){
    int rowp = row;
    int clop = clo;
    while(board[row][clo] == 0 && row<=4 && row>0 && clo<=4 && clo>0){
        row+=rp;
        clo+=cp;
    }
    if(direction == UP || direction == DOWN){
        if(rowp == row)     return 0;
    }
    else{
        if(clop == clo)     return 0;
    }
    if(row == 5 || row == 0 || clo == 5 || clo == 0)    return 0;
    board[rowp][clop] = board[row][clo];
    *if_moved = 1;
    board[row][clo] = 0;
    return 0;
}

//-------- clear & print --------
int ClearBoard(){
    memset(board,-1,sizeof(board));
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			board[i][j] = 0;
		}
	}
    return 1;
}

void ClearS(){
	system("cls");
}

int PrintBoard(){
	printf("\n");
	for(int i=1;i<=4;i++){
		printf("    ");
		for(int j=1;j<=4;j++){
			printf("%-5d",board[i][j]);
		} 
		printf("\n");
	}
	printf("\n");
}

//-------- get input --------
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
		case 'p':{
			return PAUSE;
		}
		case 'P':{
			return PAUSE;
		}
		default:{
			return 0;
			break;
		}
	}
}
