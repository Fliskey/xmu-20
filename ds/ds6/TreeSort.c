#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 20

void printTree(int L[],int k,int l){
    if(l > k){
        return;
    }
    int level = log2(l);
    for(int i=1;i<=level;i++){
        printf("  ");
    }
    printf("%d:%d\n",l,L[l]);
    printTree(L,k,l*2);
    printTree(L,k,l*2+1);
}

void BuildTree(int data[],int L[],int n){
    int h = ceil(log2(n)) + 0.00001;//5
    int k = pow(2,h)-1;//31
    for(int i=1;i<=(k+1)*2-1;i++){//1~63
        L[i] = 0x7fffffff;
    }
    for(int i=1;i<=n;i++){//32~42
        L[i+k] = data[i-1];
    }

    for(int i=h-1 ; i>=0 ; i--){    //4~1
        for(int j=pow(2,i); j<=pow(2,i+1)-1; j++){
            L[j] = L[j*2] < L[j*2+1] ? L[j*2] : L[j*2+1] ;
        }
    }

//    printTree(L,2*k-1,1);

}

void TreeSort(int L[],int n){
    int h = ceil(log2(n)) + 0.00001;
    int k = pow(2,h)-1;
    printf("排序后：\n");
    printf("下标：");
    for(int i=1;i<=n;i++){
        printf("%-3d",i-1);
    }
    printf("\n数值：");
    for(int i=1;i<=n;i++){
    //    printTree(L,2*k-1,1);
        printf("%-3d",L[1]);
        int j=1;
        while(L[2*j] == L[1] || L[2*j+1] == L[1]){
            j*=2;
            if(L[j] != L[1]){
                j++;
            }
        } 
        L[j] = 0x7fffffff;
        int k = j;
        k /= 2;
        while(k > 0){
            L[k] = L[k*2] < L[k*2+1] ? L[k*2] : L[k*2+1];
            k/=2;
        }
    }
    printf("\n");
//    printTree(L,2*k-1,1);
}

int main(){
    srand((int)time(NULL));
    int h = ceil(log2(N)) + 0.00001;
    int len = pow(2,h+1);
    int L[len];
    int data[N];
    for(int i=1;i<=N;i++){
        data[i-1] = rand()%(N*3);
    }
    printf("原始数据：\n");
    printf("下标：");
    for(int i=0;i<N;i++){
        printf("%-3d",i);
    }
    printf("\n");
    printf("数值：");
    for(int i=1;i<=N;i++){
        printf("%-3d",data[i-1]);
    }
    printf("\n");
    
    BuildTree(data,L,N);
    TreeSort(L,N);
    return 0;
}