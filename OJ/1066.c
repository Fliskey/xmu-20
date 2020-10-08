#include <stdio.h>

int main(){
	int x;
	int a=0,p=0,f=0;
	while(scanf("%d",&x) && x>0){
		if(x>=85)	a++;
		else	if(x>=60)	p++;
		else	f++;
	}
	printf(">=85:%d\n60-84:%d\n<60:%d",a,p,f);
	return 0;
}
