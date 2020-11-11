#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int num[100004];
    while(scanf("%d",&n) != EOF){
        memset(num,0,sizeof(num));
        for(int i=1; i<=n; i++){
            scanf("%d",&num[i]);
        }
        int ans_max = -0x7fffffff;
        int ans_count = -1;
        for(int i=1; i<=n; i++){
            int max = -0x7fffffff;
            int sum = 0;
            int count = 0;
            for(int j=i; j<=n; j++){
                sum += num[j];
                if(sum >= max){
                    max = sum;
                    count = j-i+1;
                }
            }
            if(max == ans_max){
            	if(count > ans_count){
            		ans_max = max;
            		ans_count = count;
				}
            }
            else if(ans_max < max){
                ans_max = max;
                ans_count = count;
            }
            else{
                continue;
            }
        }
        printf("%d %d\n",ans_max,ans_count);
    }
    return 0;
}
