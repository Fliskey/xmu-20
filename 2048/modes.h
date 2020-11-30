//-------- 2048GAME:modes --------
//0474-Fliskey
#define MAX(x,y) x>y?x:y

extern int borad[6][6];
extern int goal;
extern const int TARGET;

//gaming mode
int mode_gaming(){
	extern int maxvalue;
    maxvalue = InitBoard();
    printf("-------- Gaming --------\n");
    printf("Max value:%-5d Goal:%-6d\n",maxvalue,goal);
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
			printf("-------- Gaming --------\n");
			printf("Max value:%-6d Goal:%-6d\n",maxvalue,goal);
			PrintBoard();
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

int mode_gaming_menu(){
    ClearS();
	printf("---- Pause ----\n");
    printf("Press a Key to select:\n");
    printf("R: Restart\n");
    printf("Q: Back to Home\n");
    printf("");
}
