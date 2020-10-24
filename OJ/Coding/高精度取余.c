#include <stdio.h>

int gjdmod(char *s,int x){
	int i = 0;
	int a,b;
	a = s[0] - '0';
	b = x;
	int c;
	while(s[i] != '\0'){
		c = a%b;
		c *= 10;
		i++;
		if(s[i] == '\0'){
			return c/10;
		}
		c += s[i] - '0';
		a = c;
	}
}

int main(){
	
	return 0;
}
