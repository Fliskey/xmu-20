#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    double count = 0;
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=1;k<=100;k++){
                int value = i+j+k;
                if(value > x){
                    count+=1;
                }
            }
        }
    }
    double ans = 0;
    ans = count/10000.0;
    printf("%.1f%c",ans,'%');
    return 0;
}