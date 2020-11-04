#include <stdio.h>

char c[20];

int main(){
	memset(c,0,sizeof(c));
	
	while(scanf("%s",&c) != EOF){
		int l = 0;
		while(c[l] != '.'){
			l++;
		}
		int xsd = l;
		l += 10;
		c[l]++;
		
		while(c[l] == ':'){
			
			c[l] = '0';
			l--;
			
			if(c[l] == '\0'){
				c[l] = '0';
			}
			
			c[l]++;
		}
		if(l == xsd){
			l--;
			c[l]++;
			while(c[l] == ':'){
				c[l] = '0';
				l--;
				if(l >= 0)	c[l]++;
			}
		}
		
		if(c[0] == '1' && c[1] == '0' && c[2] == '0'){
			printf("100.0000000000");
		}
		else{
			if(l == -1)	printf("1");
			for(int i = 0 ; i < xsd ; i++){
				printf("%c",c[i]);
			}
			printf(".");
			for(int i = xsd+1 ; i<= xsd+10 ; i++){
				printf("%c",c[i]);
			}
		}
		printf("\n");
		
		memset(c,-1,sizeof(c));//½áÎ²³õÊ¼»¯ 
	}
	return 0;
}
