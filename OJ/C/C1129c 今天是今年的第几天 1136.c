#include <stdio.h>

int rn(int n){
	int b = 0;
	if(n % 100 == 0){
		if(n % 400 == 0)
			b = 1;
		else
			b = 0;
	}
	else{
		if(n % 4 == 0)
			b = 1;
		else
			b = 0;
	}
	return b;
}

int md[15];

int main(){
	
	md[1] = 31;
	md[2] = 28;
	md[3] = 31;
	md[4] = 30;
	md[5] = 31;
	md[6] = 30;
	md[7] = 31;
	md[8] = 31;
	md[9] = 30;
	md[10] = 31;
	md[11] = 30;
	md[12] = 31;
	
	int y,m,d;
	while(scanf("%d %d %d",&y,&m,&d) != EOF){
		int sum = 0;
		for(int i=1;i<m;i++){
			sum += md[i];
		}
		sum += d;
		if(m > 2 && rn(y) == 1){
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
