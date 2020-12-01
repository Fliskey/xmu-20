#include <stdio.h>
#include <math.h>

int main(){

    int a;
    int is_first = 1;
    while(scanf("%d",&a)){
        if(a == 0){
            break;
        }

        if(is_first == 0){
            printf("\n");
        }

        int count = 0;
        while(a != 0){
            if(a & 1){
                break;
            }
            a = a>>1;
            count++;
        }
        printf("%.0f",pow(2,count));

        is_first = 0;
    }
    return 0;
}
