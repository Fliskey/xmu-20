#include <stdio.h>

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int maxn = n/3;
		int minn = n/5;
		for(int i = maxn ; i>=minn ; i--){
			int ag_need = 2 * i;
			int gold_need2 = 3 * i;
			int gold_need1 = 0;
			if(ag_need % 4 == 0){
				gold_need1 = ag_need / 2;
			}
			else{
				gold_need1 = (ag_need + 4 - (ag_need%4))/2;
			}
			
		//	printf("%d %d %d\n",ag_need,gold_need1,gold_need2);
			int gold = gold_need1 + gold_need2;
			if(gold <= n){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
