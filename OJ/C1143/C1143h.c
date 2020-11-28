#include <stdio.h>
#include <math.h>

int exponent(int);

int apart(int n,int first_printed){
    int ansi = 0;
    while(n != 0){
        int l2 = log2(n);
        if(first_printed == 1){
            printf("+");
        }
        else{
            first_printed = 1;
        }
        if(l2 == 0){
            printf("2(0)");
        }
        else if(l2 == 1){
            printf("2");
        }
        else{
            printf("2(");
            exponent(l2);
            printf(")");
        }
        n -= pow(2,l2);
    }
    return ansi-1;
}

int exponent(int n){
    int l2 = log2(n);
    if(l2 == 0){
        printf("2(0)");
    }
    else if(n == 2){
        printf("2");
    }
    else{
        apart(n,0);
    }
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        exponent(n);
        printf("\n");
    }
    return 0;
}