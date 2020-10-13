#include <stdio.h>

unsigned long long lt[200];

unsigned long long mp(int l){
	if(l == 0){
		return 1;
	}
	else if(l < 0){
		return 0;
	}
	else{
		unsigned long long sum = 0;
		if(lt[l] == 0){
			sum += mp(l-2);
			sum += mp(l-3);
			lt[l] = sum;
		}
		else{
			sum = lt[l];
		}
		return sum;
	}
}

int main(){
	unsigned long long x;
	while(scanf("%d",&x) != EOF){
		memset(lt,0,sizeof(lt));
		unsigned long long ans = mp(x);
		printf("%lld\n",ans);
	}
	return 0;
}
