#include <stdio.h>

int to16(int x){
	int q = x;
	char ans[5];
	int sl = 0;
	if(q == 0){
		printf("00");
		return 0;
	}
	while(q != 0){
		int ys = q%16;
	//	printf("%d\n",ys);
		if(ys >= 10){
			ans[sl] = ys-10+'A';
		}
		else{
			ans[sl] = ys + '0';
		}
		q/=16;
		sl++;
	}
	if(q < 16){
		ans[sl] = '0';
		sl++;
	}
	
	sl--;
	printf("%c%c",ans[1],ans[0]);
	sl--;
	return 0;
}

int main(){
	int a,b,c;
	
	while(scanf("%d %d %d",&a,&b,&c) != EOF){
		printf("#");
		to16(a);
		to16(b);
		to16(c);
		printf("\n");
	}
	return 0;
}
