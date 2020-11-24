#include <stdio.h>

int sol(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    else{
        int sum = 0;
        for(int i=1;i<=3;i++){
            if(n>=i){
                sum += sol(n-i);
            }
        }
        return sum;
    }
}

int main(){
    int n;
    int is_first = 1;
    while(scanf("%d",&n) != EOF){
        if(is_first == 0){
            printf("\n");
        }

        int value = sol(n);
        printf("%d",value);

        if(is_first){
            is_first = 0;
        }
    }
    return 0;
}