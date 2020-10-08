#include<stdio.h>

int main(){
	char s1[102]={0},s2[102]={0};
	while( scanf("%s %s",s1,s2)!= EOF){
		int s1len = 0,s2len = 0;
		for(int i=0;s1[i] != '\0'; i++){
			s1len++;
		}
		for(int i=0;s2[i] != '\0'; i++){
			s2len++;
		}
		if (s1len < s2len){
			for(int i=0;i<=s2len;i++){
				char s3;
				s3 = s1[i];
				s1[i] = s2[i];
				s2[i] = s3;
			}
			int s3len;
			s3len = s1len;
			s1len = s2len;
			s2len = s3len;
		}
		int l1,l2;
		l1 = s1len;
		l2 = s2len;
		int ans[610];
		int k = 0;
		for(int i = 1 ; i<=l1 ; i++){
			int a = s1[l1-i]-48;
			int b = s2[l2-i]-48;
			if(b < 0)  b = 0;
			int c = a+b;
			if(k == 1)  c+=1;
			if(c >= 10){
				k = 1;
				c -= 10;
			}
			else  k = 0;
			ans[l1-i] = c;
		}
		if(k == 1)  printf("1");
		for(int i = 0 ; i<=l1-1 ; i++){
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
} 
