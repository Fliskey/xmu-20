#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		
		int save;
		int mindiv = 0;
		
		for(int j=1;j<=n;j++){
			scanf("%d",&save);
			mindiv += save -1;
		}
		
		if(mindiv %2 == 1){
			printf("Win\n");
		}
		else{
			printf("Lose\n");
		}
		
	}
	return 0;
}
