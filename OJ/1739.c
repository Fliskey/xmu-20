#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void*a, const void*b) {
	return *(int*)a-*(int*)b;
}
int chcomp(const void*a, const void*b){
	return strcmp((char *)a,(char *)b);
}

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
	int n;
	scanf("%d",&n);
	char nm[n][10086]; //name
	int nb[n]; //number
	for(int i=0;i<n;i++){
		scanf("%s",&nm[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&nb[i]);
	}
	
/*	for(int i=0;i<n;i++){
		char min[] = "zzzzzzzzzzzzzzz\0";
		int l = 0;
		for(int j=i;j<n;j++){
			if(charcp(min,nm[j])){
				strcpy(min,nm[j]);
				l = j;
			}
		}
		//swap(nm[i],nm[l]);
		strcpy(nm[l],nm[i]);
		strcpy(nm[i],min);
	//	printf("%s\n",min);
	}*/
	qsort(nb,n,sizeof(int),comp);
	qsort(nm,n,sizeof(nm[0]),chcomp);
	
	for(int i=0;i<n;i++){
		printf("%s %d\n",nm[i],nb[i]);
	}
	 
	return 0;
} 
