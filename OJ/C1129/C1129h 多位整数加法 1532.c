#include <stdio.h>

int a[600],b[600];
char sa[600],sb[600];
int ans[600];

int jf(int *x,int *y,int xl,int yl,int *anss){
	
	for(int i=0 ; i<xl ; i++){
			
		anss[yl-i] += x[xl-i-1] + y[yl-i-1]; 
		
		while(anss[yl-i] >= 10){
			anss[yl-i-1]++;
			anss[yl-i] -= 10;
		}
		
		printf("i:%d\nx:",i);
		for(int i=0;i<xl;i++){
			printf("%d ",x[i]);
		}
		printf("\ny:");
		for(int i=0;i<yl;i++){
			printf("%d ",y[i]);
		}
		printf("\nans:");
		for(int i=0;i<=yl;i++){
			printf("%d ",ans[i]);
		}
		printf("\n\n");
		
		
	}
	
	for(int i=0 ; i<yl-xl ; i++){
		anss[yl-xl-i] += y[yl-xl-i-1];
		while(anss[yl-xl-i] >= 10){
			anss[yl-xl-i-1]++;
			anss[yl-xl-i] -= 10;
		}
		
		printf("i:%d\nx:",i);
		for(int i=0;i<xl;i++){
			printf("%d ",x[i]);
		}
		printf("\ny:");
		for(int i=0;i<yl;i++){
			printf("%d ",y[i]);
		}
		printf("\nans:");
		for(int i=0;i<=yl;i++){
			printf("%d ",ans[i]);
		}
		printf("\n\n");
		
	}
	
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
			if(ans[0] == 1){
				printf("1");
			}
			for(int i=1;i<=lb;i++){
				printf("%d",ans[i]);
			}
		}
		else{
			jf(b,a,lb,la,ans);
			if(ans[0] == 1){
				printf("1");
			}
			for(int i=1;i<=la;i++){
				printf("%d",ans[i]);
			}
		}
		
		printf("\n");
	}
	return 0;
}
