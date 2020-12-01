#include <stdio.h>
#include <string.h>

double ans[1204];

double search(double n,double x){
    if(ans[(int)n] != 0){
        return ans[(int)n];
    }
    else{
        ans[(int)n] = ((2*n-1)*x*search(n-1,x)-(n-1)*search(n-2,x))/n;
        return ans[(int)n];
    }
}

int main(){
    double n;
    double x;
    while(scanf("%lf %lf",&n,&x) != EOF){
        memset(ans,0,sizeof(ans));
        ans[0] = 1;
        ans[1] = x;
        printf("%.2f\n",search(n,x));
    }
    return 0;
}