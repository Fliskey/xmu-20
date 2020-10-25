#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1739 ÕÒÅóÓÑ 

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

int main(){
	int n;
	int num[10004];

	scanf("%d",&n);
	if(n > 1000){
		char namel[10004][104];
		for(int i=0 ; i<n ; i++){
			scanf("%s",namel[i]);
		}
		
		for(int i=0 ; i<n ; i++){
			scanf("%d",&num[i]);
		}
		
		qsort(num,n,sizeof(num[0]),dcmp);
		qsort(namel,n,sizeof(namel[0]),scmp);
		
		for(int i=0 ; i<n ; i++){
			printf("%s %d\n",namel[i],num[i]);
		}
	}
	else if(n > 100){
		char namem[1004][1004];
		for(int i=0 ; i<n ; i++){
			scanf("%s",namem[i]);
		}
		
		for(int i=0 ; i<n ; i++){
			scanf("%d",&num[i]);
		}
		
		qsort(num,n,sizeof(num[0]),dcmp);
		qsort(namem,n,sizeof(namem[0]),scmp);
		
		for(int i=0 ; i<n ; i++){
			printf("%s %d\n",namem[i],num[i]);
		}
	}
	else{
		char names[104][10004];
		for(int i=0 ; i<n ; i++){
			scanf("%s",names[i]);
		}
		
		for(int i=0 ; i<n ; i++){
			scanf("%d",&num[i]);
		}
		
		qsort(num,n,sizeof(num[0]),dcmp);
		qsort(names,n,sizeof(names[0]),scmp);
		
		for(int i=0 ; i<n ; i++){
			printf("%s %d\n",names[i],num[i]);
		}
	}
	
	return 0;
} 
