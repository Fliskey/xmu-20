#include <stdio.h>

int main(){
	char c[1008611];
	int n;
	while(scanf("%d",&n) != EOF){
		gets(c);
		int sk = 0;
		int md = 1;
		for(int i=0;c[i]!='\0';i++){
			if(c[i] == '('){
				sk++;
			}
			if(c[i] == ')'){
				if(sk == 0){
					md = 0;
				}
				else{
					sk--;
				}
			}
			c[i] = 0;
		}
		if(sk){
			md = 0;
		}
		if(md){
			printf("Yes\n");
		}	
		else{
			printf("No\n");
		}
		
	}
	
	return 0;
}
