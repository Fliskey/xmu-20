#include <stdio.h>
#include <stdlib.h>

int A[1004];

int cmp(const void *x,const void *y){
    return *(int*)x-*(int*)y;
}

int search(int left,int right,int *arr,int *target){
    int mid = (left + right) / 2;
    int value = *target - arr[mid];
    if(!value){
        return mid;
    }
    else if(left > right)
        return -1;
    else if(value > 0)
        return search(mid+1,right,arr,target);
    else
        return search(left,mid-1,arr,target);
}

int main(){
    int n;
    printf("请输入数组元素个数：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d. ",i+1);
        scanf("%d",&A[i]);
    }
    printf("排序前数组：");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    qsort(A,n,sizeof(int),cmp);
    printf("排序后数组：");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    int x;
    printf("请输入待查找的数：");
    scanf("%d",&x);
    int value = search(0,n,A,&x);
    if(value == -1){
        printf("未找到该数！");
    }
    else{
        printf("该数位置为：%d",value+1);
    }
    return 0;
}