#include <stdio.h>
//1375 ×Ö·û´®±à¼­ 

int main(){
	char s[50];
	gets(s);
	
	int len = 0;
	for(len=0;s[len]!='.';len++);
	
	char cmd[10];
	gets(cmd);
	
	switch(cmd[0])
	{
		case 'D':{
			char dl = cmd[2];
			int mod = 0;
			int w = 0;
			for(int i=0;s[i]!='\0' && !mod;i++){
				if(s[i] == dl){
					w = i;
					mod = 1;
				}
			}
			if(!mod){
				printf("Not exist");
				return 0;
			}
			for(int i=0;s[i]!='\0';i++){
				if(i != w){
					printf("%c",s[i]);
				}
			}
			
			break;
		}
		case 'I':{
			char a1,a2;
			a1 = cmd[2];
			a2 = cmd[4];
			
			int mod = 0;
			int w = 0;
			for(int i=0;s[i]!='\0';i++){
				if(s[i] == a1){
					w = i;
					if(!mod){
						mod = 1; 
					}
				}
			}
			if(!mod){
				printf("Not exist");
				return 0;
			}
			
			for(int i=0;s[i]!='\0';i++){
				if(i != w){
					printf("%c",s[i]);
				}
				else{
					printf("%c%c",a2,a1);
				}
			}
			
			break;
		}
		case 'R':{
			char a1,a2;
			a1 = cmd[2];
			a2 = cmd[4];
			int mod = 0;
			for(int i=0;s[i]!='\0';i++){
				if(s[i] == a1){
					s[i] = a2;
					if(!mod){
						mod = 1;
					}
				}
			}
			
			if(!mod){
				printf("Not exist");
				return 0;
			}
			
			for(int i=0;s[i]!='\0';i++){
				printf("%c",s[i]);
			}
			
			break;
		}
	}
	
	return 0;
}
