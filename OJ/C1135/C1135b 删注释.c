#include <stdio.h>

int main(){
	char c;
	
	int spf = 0;//sharp_flag
	int ggf = 0;// //flag
	int gxf = 0;// /*flag
	int gxfwait = 0;// ajuge /*
	int bgin = 0;//begin
	
	int ent = 0;//whether change lines,to print one \n only
	
	while(scanf("%c",&c) != EOF){
		if(bgin){
			if(gxf){
			//	scanf("%c",&c);
				if(c == '*'){
					scanf("%c",&c); 
					if(c == '/'){
						gxf = 0;
					}
				}
			}
			else if(ggf){
			//	scanf("%c",&c);
				if(c == '\n'){
					if(!ent){
						printf("\n");
						ent = 1;
					}
					ent = 1;
					ggf = 0;
				}
			}
			else if(c == '#'){
				scanf("%c",&c);
				if(c == '#'){
					scanf("%c",&c);
					if(c == '#'){
						bgin = 0;
					}
					else{
						if(c != '/' && c != '*'){
							printf("##%c",c);
						}
						else{
						//	scanf("%c",&c);
							if(c == '/'){
								scanf("%c",&c);
								if(c == '/'){
									ggf = 1;
								}
								else if(c == '*'){
									gxf = 1;
								}
							}
						}
					}
				}
				else{
					if(c != '/' && c != '*'){
						printf("#%c",c);
					}
					else{
					//	scanf("%c",&c);
						if(c == '/'){
							scanf("%c",&c);
							if(c == '/'){
								ggf = 1;
							}
							else if(c == '*'){
								gxf = 1;
							}
						}
					}
				}
			}
			else{
			//	scanf("%c",&c);
				if(c != '/' && c != '*'){
					if(c == '\n'){
						if(!ent){
							printf("\n");
							ent = 1;
						}
					}
					else{
						printf("%c",c);
						ent = 0;
					}
				}
				else{
				//	scanf("%c",&c);
					if(c == '/'){
						scanf("%c",&c);
						if(c == '/'){
							ggf = 1;
						}
						else if(c == '*'){
							gxf = 1;
						}
					}
				}
			}
		}
		
		else{
			if(c == '#'){
				scanf("%c",&c);
				if(c == '#'){
					scanf("%c",&c);
					if(c == '#'){
						scanf("%c",&c);
						bgin = 1;
					} 
				}
			}
			
			
		}
	}
	
	
	return 0;
}
