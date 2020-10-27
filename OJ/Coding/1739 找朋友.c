#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1739 ’“≈Û”— 

int scmp(const void* _a,const void* _b){
	char* a = (char*) _a;
	char* b = (char*) _b;
	return strcmp(a,b);
}

int dcmp(const void* _a,const void* _b){
	int* a = (int*) _a;
	int* b = (int*) _b;
	return *a - *b;
}

int num[200004];
char name[200004][31];

int main(){
	freopen("test9.in","r",stdin); 
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	
	for(int i=0 ; i<n ; i++){
		scanf("%s",name[i]);
	}
	
	for(int i=0 ; i<n ; i++){
		scanf("%d",&num[i]);
	}
	
	qsort(num,n,sizeof(num[0]),dcmp);
	qsort(name,n,sizeof(name[0]),scmp);
	
	for(int i=0 ; i<n ; i++){
		printf("%s %d\n",name[i],num[i]);
	}
	
	return 0;
} 
