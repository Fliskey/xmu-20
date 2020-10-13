#include <stdio.h>

int a[27];
int pd(int x,int y){
	if(x<=50&&y<x){
		if(x%y==0&&x!=y)
			return 1;
		else
			pd(x,y+1);
	}
	else
		return 0;
}

int main(){
	char s1[104];
	scanf("%s",s1);
	int s1size = 0;
	for(int i=0; s1[i] != '\0'; i++){
		s1size = i;
	}
	for(int i=1;i<= s1size ;i++){
		a[s1[i-1]-96]++;
	}
	int mx=-1,mi=1000;
	for(int i=1;i<=26;i++){
		if (a[i]>mx&&a[i]!=0)
			mx=a[i];
		if (a[i]<mi&&a[i]!=0)
			mi=a[i];
	}
	if (pd(mx-mi,1))
		printf("Lucky Word\n%d",mx-mi);
	else
		printf("No Answer\n0");
}
