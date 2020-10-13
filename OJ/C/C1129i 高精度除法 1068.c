#include <stdio.h>
#define ULL unsigned long long
ULL ans[200];

//399999 100000 4 答案是错的 

int main(){
	ULL a,b,zs;
	int c;
	while(scanf("%ld %ld %d",&a,&b,&c) != EOF){
		memset(ans,0,sizeof(ans));
		ULL ll = 0;
		zs = a/b;
		a %= b;
		
		//整数部分单独存到ans[0]里 
		ans[ll] = zs; 
		
		ll++;
		
		while(c != -1){
			a *= 10;
			zs = a/b;
			ans[ll] = zs;
			ll++;
			a %= b;
			c--;
		}
		
		//四舍五入 
		if(ans[ll-1]>5){
			ans[ll-2]+=1;
		}
		
		ULL zc = ll;
		
		//判断是否进位 
		ll -= 2;
		while(ans[ll] == 10 && ll != 0){
			
			ans[ll] = 0;
			ll--;
			ans[ll]++;
			
		}
		if(zc != 2){
			printf("%ld.",ans[0]);
		}
		else{
			printf("%ld",ans[0]);
		}
		
		for(ULL i=1;i<zc-1;i++){
			printf("%ld",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}
