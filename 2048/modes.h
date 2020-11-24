//-------- 2048GAME:modes --------
//0474-Fliskey

extern int borad[6][6];
extern int goal;

//gaming mode
int mode_gaming(){
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

int mode_gaming_menu(){
    ClearS();
    printf("Press a Key to select:\n");
    printf("R: Restart\n");
    printf("Q: Back to Home\n");
    printf("")
}