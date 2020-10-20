#include <stdio.h>

int main(){
	double m;
	int n;
	scanf("%lf %d",&m,&n);
	double ft = m, jg = -m;
	for(int i=1;i<=n;i++){
		jg += 2*m;
		m /= 2;
		ft /= 2;
	}
	printf("%.2f %.2f",ft,jg);
	return 0;
} 
