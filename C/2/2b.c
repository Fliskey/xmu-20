#include <stdio.h>
int n;
int ans = -1;
int block[100004] = {0};

int main(){
    scanf("%d",&n);
    scanf("%d",&block[1]);
    if(block[1] == 1){
        printf("NO");
        return 0;
    }
    for(int i=2;i<=n;i++){
        scanf("%d",&block[i]);
    }
    if(block[n] == n){
        printf("NO");
        return 0;
    }

    //if blocks is a line then ans = NO
    int top_line = 1;
    for(int i=2;i<=n;i++){
        int deata = block[i]-block[i-1];
        if(deata > 1){
            top_line = 0;
            break;
        }
        else if(deata < -1){
            top_line = 0;
            break;
        }
        if(block[i] == 1){
            break;
        }
    }
    if(top_line){
        printf("NO");
        return 0;
    }
    
    for(int i=1;i<=n;i++){
        if(block[i] == n){
            int right_line = 1;
            for(int j=i+1;j<=n;j++){
                int deata = block[j] - block[j-1];
                if(deata > 1){
                    right_line = 0;
                    break;
                }
                else if(deata < -1){
                    right_line = 0;
                    break;
                }
                if(j == n){
                    break;
                }
            }
            if(right_line){
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}
