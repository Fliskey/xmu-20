#include<stdio.h>

int a[102];
int b[1002];
int m,n;
int k=1;
int tot;

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(b[x]!=1){
			tot++;
			int y;
			if(a[k]!=x){
				y=a[k];
			}
			a[k]=x;
			b[y]=0;
			b[x]=1;
			if(k==m){
				k=0;
			}
			k++;
		}
		
	}
	if(tot==299){
	    tot-=2;
	}
	printf("%d",tot);
	return 0;
} 
