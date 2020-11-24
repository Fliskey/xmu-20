#include <stdio.h>
#include <string.h>

int main(){
    int n,k;
    int is_first = 1;
    while(scanf("%d %d",&n,&k) != EOF){
        if(is_first == 0){
            printf("\n");
        }
        double ans = 1;
        for(int i=1;i<=n;i++){
            ans *= i;
        }
        char num[24];
        sprintf(num,"%.0f",ans);

        int len = strlen(num);
        len--;
        while(num[len] == '0'){
            len--;
        }
        if(len+1 <= k){
            for(int i=0;i<=len;i++){
                printf("%c",num[i]);
            }
        }
        else{
            for(int i=k-1;i>=0;i--){
                printf("%c",num[len-i]);
            }
        }
       
        if(is_first){
            is_first = 0;
        }
    }
    return 0;
}
