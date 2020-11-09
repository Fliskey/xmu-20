#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void* _a,const void* _b)
{ 
    int *a = (int*) _a;
    int *b = (int*) _b;
    return *a>*b;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int num[24];
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        qsort(num,n,sizeof(int),cmp);
        for(int i=0;i<n;i++){
        	if(num[i]%2 == 1){
        		printf("%d ",num[i]);
			}
        }
		for(int i=0;i<n;i++){
        	if(num[i]%2 == 0){
        		printf("%d ",num[i]);
			}
        }
        printf("\n");
    }
    return 0;
}
