#include <stdio.h>
#include <math.h>

int ans[100004];
int max = 1;

int search(int n){
	for(int i=max;i<=n;i++){
		int sq = (int)sqrt(i);
        if(sq*sq == i){
            ans[i] = 1;
            continue;
        }
        int value1 = 0;
        for(int no1=sq;no1>=1 && i-no1*no1 > 0;no1--){
            int remain1 = i-no1*no1;
            int sqrm1 = (int)sqrt(remain1);
            if(sqrm1*sqrm1 == remain1){
                value1 = 0;
                continue;
            }
            int value2 = 1;
            for(int no2=sqrm1;no2>=1 && remain1-no2*no2 > 0;no2--){
                int remain2 = remain1-no2*no2;
                value2 &= ans[remain2];
            }
            if(value2){
                value1 = 1;
                break;
            }
        }
        ans[i] = value1;
	}
	max = n+1;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        search(n);
        if(ans[n]){
        	printf("Win\n");
		}
		else{
			printf("Lose\n");
		}
    }
    return 0;
}
