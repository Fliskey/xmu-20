#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}

int main(){
    int n,m;
    int apple[2004] = {0};
    int taotao[2004] = {0};
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++){
        scanf("%d",&apple[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&taotao[i]);
    }

    qsort(taotao,m,sizeof(int),cmp);
    

    int sum = m;

    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<m;j++){
            if(taotao[j] == -1){
                continue;
            }
            if(apple[i]>=taotao[j]){
                taotao[j] = -1;
                sum--;
                break;
            }
        }
        for(int i=0;i<m;i++){
            printf("%d ",taotao[i]);
        }
        printf("\n");
    }
    printf("%d",sum);
    return 0;
}