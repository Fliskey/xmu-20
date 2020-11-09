#include <stdio.h>
#include <math.h>

int main(){
    
    int n;
    while(scanf("%d",&n) != EOF){
        printf("%d=",n);
        int is_first = 1;
        while(n != 1){
            int i = 2;
            int qn = sqrt(n);
        //    printf("%d\n",qn);
            for(i=2;i<=qn;i++){
            //    printf("%d %d\n",n,i);
                if(n%i == 0){
                    if(is_first){
                        is_first = 0;
                        printf("%d",i);
                    }
                    else{
                        printf("*%d",i);
                    }
                    n /= i;
                    goto skip;
                }
            }
            if(i > qn){
                if(is_first){
                    printf("%d",n);
                }
                else{
                    printf("*%d",n);
                }
                break;
            }
            skip : continue;
        }
        printf("\n");
    }
    return 0;
}
