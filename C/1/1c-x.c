#include <stdio.h>
#include <string.h>

int locate[28][1004] = {0};
int ci[28] = {0};
int ced[28] = {0};

int main(){
	
	
	freopen("in.txt","r",stdin);
	
	int n;
	scanf("%d",&n);
	while(n>=1){
		memset(locate,0,sizeof(locate));
		memset(ci,0,sizeof(ci));
		
		char s[1004];
		scanf("%s",s);
		
		int len = 0;
		for(;s[len] != '\0';len++){
			char c = s[len];
			int ip = c-'a';
			locate[ip][ci[ip]++] = len;
		}
		
		for(int i=1;i<=26;i++){
			printf("%c:",'a'+i-1);
			for(int j=0;j<=ci[i-1]-1;j++){
				printf("%d ",locate[i-1][j]);
			}
			printf("\n");
		}
		
		for(int i=0;i<=len-2;i++){
			int ip = s[i] - 'a';
			if(ci[ip] == 0){
				continue;
			}
			
		}
		
		n--;
	}
	return 0;
}
