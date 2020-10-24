#include <stdio.h>

//1168 ’“¡„«Æ
int main(){
	
	int n,m;
	int casenum = 1;
	int can_use[104];
	int use[104];
	
	while(scanf("%d %d",&n,&m) && !(n==0 && m==0))
	{
		printf("#Case %d\n",casenum);
		memset(can_use,0,sizeof(can_use));
		
		for(int i=1;i<=n;i++){
			int j;
			scanf("%d",&j);
			can_use[j] = 0;
		}
		
		for(int i=1;i<=m;i++){
			memset(use,0,sizeof(use));
			int j;
			scanf("%d",&j);
			
		}
		
		casenum++;
	}
	return 0;
} 
