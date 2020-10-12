#include <stdio.h>

int a[30],b[30];
char sa[30],sb[30];
int ans[30];

int jf(int *x,int *y,int xl,int yl,int *anss){
	for(int i=0;i<=yl;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	
	for(int i=0 ; i<xl ; i++){
		anss[yl-i] += x[xl-i-1] + y[yl-i-1];
		anss[yl-i-1] += anss[yl-i] % 10;
		anss[yl-i] %= 10;
	}
	
	for(int i=0;i<=yl;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	
	for(int i=0 ; i<yl-xl ; i++){
		anss[yl-xl-i] += y[yl-xl-i-1];
		anss[yl-xl-i-1] += anss[yl-xl-i] % 10;
		anss[yl-xl-i] %= 10;
	}
	
	for(int i=0;i<=yl;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	
	return 0;
}

int main(){
	while(scanf("%s %s",&sa,&sb) != EOF){
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		memset(ans,0,sizeof(ans));
		int la = 0;
		int lb = 0;
		int i;
		for(i=0 ; sa[i]!='\0' ; i++){
			a[i] = sa[i] - '0';
		}
		la = i;
		
		for(i=0 ; sb[i]!='\0' ; i++){
			b[i] = sb[i] - '0';
		}
		lb = i;
		
		if(lb > la){
			jf(a,b,la,lb,ans);
			for(int i=0;i<=lb;i++){
				printf("%d",ans[i]);
			}
		}
		else{
			jf(b,a,lb,la,ans);
			for(int i=0;i<=la;i++){
				printf("%d",ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
