#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,b;
    int num[100004] = {0};
    while(scanf("%d %d",&n,&b) != EOF){
        memset(num,0,sizeof(num));

        int b_locate = 0;

        for(int i=1; i<=n; i++){
            scanf("%d",&num[i]);
            
            if(num[i] == b){
                b_locate = i;
            }
        }
        
        unsigned long long ans = 0;
        int below_b = 0;
        int above_b = 0;
        for(int i=b_locate; i>=1; i--){//left edge
            
            if(num[i] > b)  above_b++;
            if(num[i] < b)  below_b++;

            int save_above_b = above_b;
            int save_below_b = below_b;

            for(int j=b_locate; j<=n; j++){//right edge 

                if(num[j] > b)  above_b++;
                if(num[j] < b)  below_b++;

                if(above_b == below_b)  ans++;
            }

            above_b = save_above_b;
            below_b = save_below_b;
        }
        printf("%lu\n",ans);
    }
    return 0;
}
