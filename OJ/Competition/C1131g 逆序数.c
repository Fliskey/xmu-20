#include <stdio.h>
//C1113g ÄæÐòÊý

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int nxs = 0;
		while(n != 0){
			nxs += n%10;
			nxs *= 10;
			n /= 10;
		}
		nxs /= 10;
		printf("%d\n",nxs);
	}
	
	
	return 0;
} 
