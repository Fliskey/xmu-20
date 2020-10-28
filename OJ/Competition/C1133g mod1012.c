#include <stdio.h>
//C1133g mod1012

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int ans = 1;
	while(b != 0){
		ans *= a;
		ans %= 1012;
		b--;
	}
	printf("%d",ans);
	return 0;
}
