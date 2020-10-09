#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void*a, const void*b) {
	return *(int*)a-*(int*)b;
}
int chcomp(const void*a, const void*b){
	return strcmp((char *)a,(char *)b);
}

int main(){
	int n;
	scanf("%d",&n);
	char nm[10004][10004] = {0}; //name
	int nb[10004] = {0} ; //number
	for(int i=0;i<n;i++){
		scanf("%s",&nm[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&nb[i]);
	}
	
	qsort(nb,n,sizeof(int),comp);
	qsort(nm,n,sizeof(nm[0]),chcomp);
	
	for(int i=0;i<n;i++){
		printf("%s %d\n",nm[i],nb[i]);
	}
	 
	return 0;
} 
