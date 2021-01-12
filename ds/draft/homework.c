#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MySort(int *arr, int n){
    int count[10001] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int point = 0;
    for(int i=0;i<=10000;i++){
        while(count[i]){
            arr[point++]=i;
            count[i]--;
        }
    }
    return 1;
}

int main1(){
    srand(time(0));
    int p[1000];
    for(int i=0;i<1000;i++){
        p[i] = rand()%10001;
        printf("%-5d ",p[i]);
        if((i+1)%20 == 0){
            printf("\n");
        }
    }
    printf("\n");
    MySort(p,1000);
    for(int i=0;i<1000;i++){
        printf("%-5d ",p[i]);
        if((i+1)%20 == 0){
            printf("\n");
        }
    }
    system("pause");
    return 0;
}

#define N 100

typedef struct RNode{
    int key;
    struct RNode *next;
}RNode,*RList;
typedef RList R[N];

int main(){
    RList A;
    A = (RList) malloc (sizeof(RNode));
    
}