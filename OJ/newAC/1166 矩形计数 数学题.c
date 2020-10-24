#include <stdio.h>
//1166 矩形计数 数学题 

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		int ans = (1+n)*n/2 * (1+m)*m/2;
		printf("%d\n",ans);
	} 
	return 0;
}
