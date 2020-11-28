#include <stdio.h>

int ncount(int n){
	if(n == 1){
		return 0;
	}
	else{
		int min = 0x7fffff;
		int max = 0;
		for(int i=1;i<=n/2;i++){
			int l = i;
			int r = n-i;
			int sum = 0;
			sum += ncount(l);
			sum += ncount(r);
			if(sum < min){
				min = sum;
			}
			if(sum > max){
				max = sum;
			}
		}
		return min+1;
	}
}

int xcount(int n){
	if(n == 1){
		return 0;
	}
	else{
		int min = 0x7fffff;
		int max = 0;
		for(int i=1;i<=n/2;i++){
			int l = i;
			int r = n-i;
			int sum = 0;
			sum += xcount(l);
			sum += xcount(r);
			if(sum < min){
				min = sum;
			}
			if(sum > max){
				max = sum;
			}
		}
		return max+1;
	}
}

int main(){
	for(int i=1;i<=10000;i++){
		int d = ncount(i) - xcount(i);
		printf("%d\n",i);
		if(d != 0){
			printf("%d\n",d);
		}
	}
	
	return 0;
}
