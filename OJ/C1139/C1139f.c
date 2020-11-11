#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    int firstin = 1;
    while(scanf("%d",&n) != EOF){
    	if(!firstin){
    		printf("\n");
		}
        int num[24];
        int is_first = 1;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
        }
        
        for(int i=1-1;i<=n-1;i++){
        	int min = num[i];
        	int mini = i;
        	for(int j=i+1;j<=n-1;j++){
        		if(num[j] < min){
        			min = num[j];
        			mini = j;
				}
			}
			int q = num[i];
			num[i] = num[mini];
			num[mini] = q;
		}
		
        
        for(int i=0;i<n;i++){
        	if(num[i] >= 0){
        		if(num[i]%2 == 1){
        			if(is_first){
        				printf("%d",num[i]);
        				is_first = 0;
					}
					else{
						printf(" %d",num[i]);
					}
				}
			}
			else{
				if((0-num[i])%2 == 1){
					if(is_first){
        				printf("%d",num[i]);
        				is_first = 0;
					}
					else{
						printf(" %d",num[i]);
					}
				}
			}
        }
        
		for(int i=0;i<n;i++){
        	if(num[i] >= 0){
        		if(num[i]%2 == 0){
	        		if(is_first){
        				printf("%d",num[i]);
        				is_first = 0;
					}
					else{
						printf(" %d",num[i]);
					}
				}
			}
			else{
				if((0-num[i])%2 == 0){
					if(is_first){
        				printf("%d",num[i]);
        				is_first = 0;
					}
					else{
						printf(" %d",num[i]);
					}
				}
			}
        }
        if(firstin){
        	firstin = 0;
		}
    }
    return 0;
}
