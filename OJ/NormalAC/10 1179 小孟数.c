#include <stdio.h>
#include <stdlib.h>

int up_side_down[10] = {0,1,-1,-1,-1,-1,9,-1,8,6};

int judge_by_x(int n,int x){
    int ncopy = n;
    int ans[20];
    memset(ans,-1,sizeof(ans));
    int ansi = 0;

    while(ncopy){
        int value = ncopy % x;
    	value = up_side_down[value];
        ans[++ansi] = value;
        if(value == -1){
            return 0;
        }
        if(value >= x){
            return 0;
        }
        ncopy /= x;
    }
    printf("%d ",x); 
    int i=1;
    while(ans[i] == 0){
    	i++;
	}
	if(i == ansi+1){
		printf("0\n");
		return 1;
	}
    for(; i<=ansi; i++){
        printf("%d",ans[i]);
    }
    printf("\n");
	return 1;
    
}

int main(){
    int n;
    while(scanf("%d",&n) && n!=-1){
    	printf("%d\n",n);
        for(int i=2;i<=10;i++){
            judge_by_x(n,i);
        }
    }
    return 0;
}
