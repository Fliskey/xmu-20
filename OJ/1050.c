#include <stdio.h>
#include <string.h>

int charcp(char *a,char *b){
	int bl = 0;
	for(int i=0; a[i] != '\0'; i++){
		if(!bl){
			if(a[i] > b[i]){
				return 1;
			}
			else{
				if(a[i] < b[i]){
					return 0;
				}
			}
			if(b[i] == '\0'){
				bl = 1;
			}
		}
		else{
			return 0;
		}
	}
}

int main(){
	
	char name[3][200];
	for(int i=0;i<=2;i++){
		scanf("%s",name[i]);
	}
	int n = 3;
	
	for(int i=0;i<n;i++){
		char min[] = "zzzzzzzzzzzzzzz\0";
		int l = 0;
		for(int j=i;j<n;j++){
			if(charcp(min,name[j])){
				strcpy(min,name[j]);
				l = j;
			}
		}
		strcpy(name[l],name[i]);
		strcpy(name[i],min);
	}
	
	for(int i=0;i<=2;i++){
		printf("%s\n",name[i]);
	}
	return 0;
}
