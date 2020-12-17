#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 30    //可修改
#define swap(x,y) (x ^= y, y ^= x, x ^= y)

int main(){
    srand((int)time(NULL));
    int a[N];
    for(int i=0;i<N;i++){
        int q = rand()%3;
        a[i] = q;
    }
    printf("元素个数：%d\n",N);
    printf("排序前:");
    for(int i=0;i<N;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    int cur = 0;
    int l = 0;
    int r = N-1;
    int countloop = 0;
    while(cur != r+1 && l <= r){
        countloop++;
        if(a[cur] == 0){
            swap(a[cur],a[l]);
            cur++;
            l++;
        }
        else if(a[cur] == 1){
            cur++;
        }
        else if(a[cur] == 2){
            swap(a[cur],a[r]);
            r--;
        }
    }
    printf("排序后:");
    for(int i=0;i<N;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("总共执行 %d 次循环\n",countloop);
    return 0;
}