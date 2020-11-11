#include <stdio.h>
#include <string.h>

int left_count[200004] = {0};
int right_count[200004] = {0};
int num[100004] = {0};
int sum[100004] = {0};

int main(){
    int n,b;
    
    while(scanf("%d %d",&n,&b) != EOF){
        memset(num,0,sizeof(num));
        memset(left_count,0,sizeof(left_count));
        memset(right_count,0,sizeof(right_count));
        memset(sum,0,sizeof(sum));

        int b_locate = 0;

        for(int i=1; i<=n; i++){
            scanf("%d",&num[i]);

            if(num[i] > b)      num[i] = 1;
            else if(num[i] < b) num[i] = -1;
            else if(num[i] == b){
                num[i] = 0;
                b_locate = i;
            }
        }
        
        unsigned long long ans = 0;
        
        left_count[100000] = 1;
        right_count[100000] = 1;
        
        for(int i=b_locate-1; i>=1; i--){//left
            sum[i] += sum[i+1] + num[i];
            left_count[sum[i]+100000]++;
        }


        for(int i=b_locate+1; i<=n; i++){//right
            sum[i] += sum[i-1] + num[i];
            int value = 0-sum[i];
            right_count[value+100000]++;
        }

        for(int i=0-n;i<=n;i++){
            ans += left_count[ i+100000 ] * right_count[ i+100000 ];
        }
		
    	printf("%lu\n",ans);
    }
    return 0;
}
