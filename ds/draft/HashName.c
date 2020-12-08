#include <stdio.h>
#include <math.h>
#define MIN_M(k,x) k*(2*x-1)/(2*x-2)


int prime(int x){
    if(x == 1||x == 0){
        return 1;
    }
    for(int i=2;i<=(int)sqrt(x);i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int find_min_prime(int x){
    for(int i=x;i<i*2;i++){
        if(prime(i) == 1){
            return i;
        }
    }
    return 0;
}

int main(){
    int m;
    m = find_min_prime(MIN_M(30,2));
    printf("%d",m);
    return 0;
}