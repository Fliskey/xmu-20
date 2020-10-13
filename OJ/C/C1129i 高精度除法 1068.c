#include <stdio.h>
#define ULL unsigned long long
ULL ans[200];

//399999 100000 4 ´ð°¸ÊÇ´íµÄ 

int main(){
	ULL a,b,zs;
	int c;
	while(scanf("%ld %ld %d",&a,&b,&c) != EOF){
		memset(ans,0,sizeof(ans));
		ULL ll = 0;
		zs = a/b;
		a %= b;
		
		ans[ll] = zs;
	//	printf("ans[%ld]:%ld\n",ll,zs);
		ll++;
		
		while(c != -1){
			a *= 10;
			zs = a/b;
			ans[ll] = zs;
		//	printf("ans[%ld]:%ld\n",ll,zs);
			ll++;
			a %= b;
			c--;
		}
		
		if(ans[ll-1]>5){
			ans[ll-2]+=1;
		}
		
		ULL zc = ll;
	//	printf("zc:%ld\n",zc);
		
		ll--;
		while(ans[ll] == 10 && ll != 0){
			ans[ll] = 0;
			ll--;
			ans[ll]++;
		}
		
		printf("%ld.",ans[0]);
		for(ULL i=1;i<zc-1;i++){
			printf("%ld",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}
