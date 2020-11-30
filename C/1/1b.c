#include <stdio.h>

int judge(int num[],int n,int target){
    if(n == 1){
        if(num[target] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(target == 1){
            for(int now=0; now<=1; now++){
                if(num[now]>0){
                    num[now]--;
                }
                else{
                	continue;
				} 

                if(now == 1){
                    if(judge(num,n-1,0))
                        return 1;
                    if(judge(num,n-1,1))
                        return 1;
                }
                else{
                    if(judge(num,n-1,0))
                        return 1;
                }
                num[now]++;
            }
        }
        else{
            if(num[0]>0){
                num[0]--;
            }
            else{
            	return 0;
			}
            if(judge(num,n-1,1))
                return 1;
            num[0]++;
        }
    }
    return 0;
}

int main(){
	
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        int in;
        int num[2] = {0};
        for(int j=1;j<=n;j++){
            scanf("%d",&in);
            if(in == 0){
                num[0]++;
            }
            else{
                num[1]++;
            }
            
        }
        int ans = judge(num,n,1);
        if(ans){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
