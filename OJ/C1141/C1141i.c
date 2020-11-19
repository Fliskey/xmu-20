#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int last;
    int ans[20004];
    int ansi = 0;
    if(n == 0){
        printf("0");
        return 0;
    }
    while(n != 0){
        last = n;
        if(n < 0){
            if(n%2 == 0){
                n /= -2;
            }
            else{
                n = n/-2 + 1;
            }
        }
        else{
            n /= -2;
        }
        int remain = last - n*-2;
        ans[ansi++] = remain;
    }
    ansi--;
    while(ansi >= 0){
        printf("%d",ans[ansi]);
        ansi--;
    }
    return 0;
}