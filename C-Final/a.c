#include <stdio.h>

int main(){
    double m,v;
    scanf("%lf %lf",&m,&v);
    double ek = v*v*m*0.5;
    printf("%.1f",ek);
    return 0;
}