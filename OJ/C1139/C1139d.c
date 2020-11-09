#include <stdio.h>

int main(){
    int a,b,c,d;
    while(scanf("%d-%d-%d-%d",&a,&b,&c,&d) == 4){
        int value = 0;
        value += a;
        value += b/100 *2;
        value += b/10%10 *3;
        value += b%10 *4;
        value += c/10000 *5;
        value += c/1000%10 *6;
        value += c/100%10 *7;
        value += c/10%10 *8;
        value += c%10 *9;
        value %= 11;
        if(d == value){
            printf("Right\n");
        }
        else{
            printf("%d-%d-%d-%d\n",a,b,c,value);
        }
    }
    return 0;
}
