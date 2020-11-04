#include <stdio.h>
//1058 ∞Ÿº¶Œ Ã‚ 

int main(){
	int g,m,x;
	g = 0;
	m = 0;
	x = 0;
	for(g=0;g<=20;g++){
		for(m=0;m<=33;m++){
			for(x=0;x<=33;x++){
				int snum = 0;
				int sval = 0;
				snum = g + m + 3*x;
				sval = g*5 + m*3 + x; 
				if(snum == 100 && sval == 100){
					printf("%d %d %d\n",g,m,3*x);
				}
			}
		}
	}
	return 0;
} 
