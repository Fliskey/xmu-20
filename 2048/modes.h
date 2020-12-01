//-------- 2048GAME:modes --------
//0474-Fliskey
#define MAX(x,y) x>y?x:y
#define RESTART 351
#define QUIT 352
#define HOME 353
#define CONTI 354
#define REDO 355

extern int borad[6][6];
extern int goal;
extern const int TARGET;
extern int save_point;
extern int max_save_number;

int mode_gaming();
int PrintScreen();
int Print_gaming_menu();
int Input_menu();


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
				default:{
					printf("ERROR!\n");
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

int PrintScreen(){
	printf("-------- Gaming --------\n");
	printf("Max value:%-6d Goal:%-6d\n",maxvalue,goal);
	PrintBoard();
	printf("   Press 'P' to pause\n");
}

int Print_gaming_menu(){
//	ClearS();
	printf("-------- Pause --------\n");
    printf("Press a Key to select:\n");
    printf("R: Restart\n");
	printf("Q: Quit Game\n");
    printf("C: Game continue\n");
	printf("Z: Redo(%d times limited)\n",max_save_number);
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
			default:{
				break;
			}
		}
	}
	return 0;	
}
