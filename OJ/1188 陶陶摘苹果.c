#include <stdio.h>

int a[11];
int x,y;
int main(){
	while(scanf("%d",&a[1]) != EOF){
		for(int i=2;i<=10;i++){
			scanf("%d",&a[i]);
		}
		scanf("%d",&y);
		y+=30;
		int k=0;
		for(int i=1;i<=10;i++){
			if(a[i]<=y){
				k++;
			}
		}
		printf("%d\n",k);
	}
	
	return 0;
}
