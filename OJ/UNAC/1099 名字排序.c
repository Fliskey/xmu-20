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
	char r[1004];
	gets(r);
	int kk = 0;
	int n = 0;
	char name[104][14];
	for(int i=0;r[i] != '\0';i++){
		if(r[i]!=' '){
			name[n][kk] = r[i];
			kk++;
		}
		else{
			name[n][kk] = '\0';
			kk = 0;
			n++;
		}
	}
	name[n][kk] = '\0';
	n++;
		
	for(int i=0;i<n;i++){
		char min[] = "zzz\0";
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
	for(int i=0;i<n;i++){
		if(i == n-1){
			printf("%s",name[i]);
		}
		else{
			printf("%s ",name[i]);
		}
	}
	return 0;
}
