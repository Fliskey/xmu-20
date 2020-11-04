//不高兴的津津 

#include <stdio.h>

int a[15]={0},m=0,c,k=0;
int main(){
	for(int i=1;i<=7;i++){
		scanf("%d %d",&a[i],&a[15-i]);
		c=a[i]+a[15-i];
		if(c>m){
			m=c;
			k=i;
		}	
	}
	printf("%d",k);
	return 0;
}
