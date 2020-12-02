//-------- 2048GAME:modes --------

/*--------------------------------------\
|										|
|	Author:	Yuxiang Wang(Fliskey)		|
|	ID:		13720192200474				|
|	Email:	Fliskey@qq.com				|
|										|
|	Last update time:	Dec.2 2020		|
|										|
\--------------------------------------*/

#define MAX(x,y) x>y?x:y
#define RESTART 351
#define QUIT 352
#define HOME 353
#define CONTI 354
#define REDO 355
#define SAVE 356
#define LOAD 357

extern int borad[6][6];
extern int goal;
extern const int TARGET;
extern int save_point;
extern int max_save_number;

int mode_gaming();
int PrintScreen();
int Print_gaming_menu();
int Input_menu();
int End_choose();


//gaming mode
int mode_gaming(){
	extern int maxvalue;
    maxvalue = InitBoard();
    goal = 0;
	save_point = 0;

	save_push();

	ClearS();
    PrintScreen();
	
	while(1){
		int der = GetInput();
		if(der == PAUSE){
			Print_gaming_menu();
			int pause_in = Input_menu();
			switch(pause_in){
				case RESTART:{
					ClearS();
					PrintScreen();
					return RESTART;
				}
				case CONTI:{
					ClearS();
					PrintScreen();
					break;
				}
				case QUIT:{
					return QUIT;
				}
				case REDO:{
					int re = save_pop();
					if(re == 0){
						ClearS();
						PrintScreen();
						printf("Redo Failed!\n");
						break;
					}
					else{
						ClearS();
						PrintScreen();
						printf("Redo Succeed!\n");
						break;
					}
				}
				case SAVE:{
					save_to_disk();
					ClearS();
					PrintScreen();
					printf("Save Succeed!\n");
					break;
				}
				case LOAD:{
					int loadvalue = load_from_disk();
					
					
					ClearS();
					PrintScreen();
					if(loadvalue == 0){
						printf("Load Failed! No save file!\n");
						break;
					}
					else{
						printf("Load Succeed!\n");
						save_point = 0;
					}
					break;
				}
				default:{
					printf("There is an unknown ERROR!\n");
					printf("Please connect Fliskey@qq.com to report! Thank you!\n");
					break;
				}
			}
		}
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
			PrintScreen();
			
			save_push();

		//	printf("max:%d\n",maxvalue);
			if(maxvalue == TARGET){
				Succeed();
				return End_choose();
			}

			int jg = FailJudge();
			if(jg){
				Failed();
				return End_choose();
			}
		//	printf("perform:%d\n",perform);
		}
	}
}

int PrintScreen(){
	printf("-------- Gaming --------\n");
	printf("Max value:%-6d Goal:%-6d\n",maxvalue,goal);
	PrintBoard();
	printf("   Press 'P' to pause\n");
}

int Print_gaming_menu(){
	ClearS();
	printf("-------- Pause --------\n\n");
	PrintBoard();
    printf("\nPress a Key to select:\n");
	printf("- Z: Redo\n");
    printf("- R: Restart\n");
	printf("- S: Save Game\n");
	printf("- L: Load Game\n");
	printf("- Q: Quit Game\n");
    printf("- C: Game continue\n");
}

int Input_menu(){
	while(1){
		char c = getch();
	//	printf("-%c-\n",c);
		switch(c){
			case 'R':{
				return RESTART;
			}
			case 'r':{
				return RESTART;
			}
			case 'Q':{
				return QUIT;
			}
			case 'q':{
				return QUIT;
			}
			case 'Z':{
				return REDO;
			}
			case 'z':{
				return REDO;
			}
			case 'C':{
				return CONTI;
			}
			case 'c':{
				return CONTI;
			}
			case 'S':{
				return SAVE;
			}
			case 's':{
				return SAVE;
			}
			case 'L':{
				return LOAD;
			}
			case 'l':{
				return LOAD;
			}
			default:{
				break;
			}
		}
	}
	return 0;	
}

int End_choose(){
	printf("\nPress a key to select\n");
	printf("- R: Restart\n");
	printf("- Q: Quit Game\n"); 

	while(1){
		char c = getch();
		switch(c){
			case 'R':{
				return RESTART;
			}
			case 'r':{
				return RESTART;
			}
			case 'Q':{
				return QUIT;
			}
			case 'q':{
				return QUIT;
			}
			default:{
				break;
			}
		}
	}
}
