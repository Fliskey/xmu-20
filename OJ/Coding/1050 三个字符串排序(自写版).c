#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//1050 三个字符串排序 

int scmp(char s1[],char s2[]){ //s1比s2小则返回1 
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	for(int i=0 ; s1[i] != '\0' ; i++){
		if(s1[i] > s2[i]){
			return -1;
		}
		if(i > l2){
			return -1;
		}
	}
	return 1;
}

int main(){
	char s[4][100005];
	while(scanf("%s %s %s",s[0],s[1],s[2]) != EOF){
		qsort(s,3,sizeof(s[0]),scmp);
	}
	return 0;
} 
