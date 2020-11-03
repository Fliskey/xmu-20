#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[600],b[600];
char sa[600],sb[600];
int ans[600];

int jf(int *x,int *y,int xl,int yl,int *anss){
	
	for(int i=0 ; i<xl ; i++){
		anss[xl-i] += x[xl-i-1] - y[yl-i-1]; 
		while(anss[yl-i] < 0){
			anss[xl-i]--;
			anss[xl-i+1] += 10;
		}
	}
	
	for(int i=0 ; i<yl-xl ; i++){
		anss[xl-yl-i] += y[xl-yl-i-1];
		while(anss[xl-xl-i] < 0){
			anss[xl-xl-i]--;
			anss[xl-xl-i+1] += 10;
		}
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
		
		int abiger = 0;
		if(la > lb){
			abiger = 1;
		}
		else if(la == lb){
			int i;
			for(i=0;i<la;i++){
				if(a[i] > b[i]){
					abiger = 1;
					break;
				}
				if(a[i] < b[i]){
					abiger = 0;
					break;
				} 
			}
			if(i == la){
				printf("0\n");
				continue;
			}
		}
		else{
			abiger = 0;
		}
		
		if(abiger){
			jf(a,b,la,lb,ans);
			int i=0;
			while(ans[i] == 0){
				i++;
			}
			for(;i<=la;i++){
				printf("%d",ans[i]);
			}
		}
		else{
			jf(b,a,lb,la,ans);
			printf("-");
			int i=0;
			while(ans[i] == 0){
				i++;
			}
			for(;i<=lb;i++){
				printf("%d",ans[i]);
			}
		}
		
		printf("\n");
	}
	return 0;
}