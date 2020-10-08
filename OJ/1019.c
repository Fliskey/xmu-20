#include <stdio.h>

int main(){
	char s[10086];
	gets(s);
	int zm=0,sz=0,kg=0,qt=0;
	for(int i = 0; s[i] != '\0'; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			zm++;
		}
		else{
			if(s[i] >= 'A' && s[i] <= 'Z'){
				zm++;
			}
			else{
				if(s[i] >= '0' && s[i] <= '9'){
					sz++;
				}
				else{
					if(s[i] == ' '){
						kg++;
					}
					else{
						qt++;
					}		
				}
			}
		}
	}
	printf("%d %d %d %d",zm,sz,kg,qt);
	return 0;
}
