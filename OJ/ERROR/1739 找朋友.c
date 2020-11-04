#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void*a, const void*b) {
	return *(int*)a-*(int*)b;
}
int ccomp(const void*a, const void*b){
	return strcmp((char *)a,(char *)b);
}

int main(){
	int n;
	scanf("%d",&n);
	char *name[10004] ; //name
	
	int number[10004] ; //number
	for(int i=0;i<n;i++){
		name[i] = malloc(10004 * sizeof(char));
		scanf("%s",&name[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	
	qsort(number,n,sizeof(int),comp);
	qsort(name,n,sizeof(10004),ccomp);
	
	for(int i=0;i<n;i++){
		for(int j=0; name[i][j] != '\0' ; j++){
			printf("%s",name[i]);
		}
		printf("%d\n",number[i]);
	}
	 
	return 0;
} 
