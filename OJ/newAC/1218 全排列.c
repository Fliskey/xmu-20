#include <stdio.h>
//1218 全排列 

//全局变量 
int n;
int used[20];
int ans[20];

//函数声明
int pl(int); 


//main 
int main(){
	memset(used,0,sizeof(used));
	
	while(scanf("%d",&n) != EOF){
		pl(0);
	}
	return 0;
}

//函数 
int pl(int i){
	if(i == n){
		int is_first = 1;
		for(int j=0 ; j<=n-1 ; j++){
			if(is_first){
				printf("%d",ans[j]);
				is_first = 0;
			}
			else{
				printf(" %d",ans[j]);
			}
		}
		printf("\n"); 
		return 1;
	} 
	for(int j=1 ; j<=n ; j++){
		if(!used[j]){
			//置位 
			used[j] = 1;
			ans[i] = j;
			
			//递归 
			pl(i+1);
			
			//复位 
			ans[i] = 0;
			used[j] = 0;
		}
	}
}
