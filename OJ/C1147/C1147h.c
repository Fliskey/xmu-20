#include <stdio.h>

int n;
int k;
int temp[14];
int a1[15],a2[28],a3[15],a4[15];
int judge(int x,int y){
	if(a2[x+y]){
		return 1;
	}
	if(a1[y]){
		return 1;
	}
	int a=x-y;
	if(a<0){
		if(a3[-a]){
			return 1;
		}
	}
	else{
		if(a4[a]){
			return 1;
		}
	}
	return 0;
}
int set(int x,int y,int value){
	a2[x+y]=value;
	a1[y]=value;
	int a=x-y;
	if(a<0){
		a3[-a]=value;
	}
	else{
		a4[a]=value;
	}
}
int n_queen(int x,int y){
	if(x==n){
		k++;
		if(k<=3){
			for(int i=1;i<=n;i++){
				printf("%d ",temp[i]);
			}	
			printf("\n");
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!judge(x+1,i)){
				set(x+1,i,1);
				temp[x+1]=i;
				n_queen(x+1,i);
				set(x+1,i,0);
			}
		}
	}
	
}
int main(){
	scanf("%d",&n);
	n_queen(0,0);
	printf("%d",k);
	return 0;
}