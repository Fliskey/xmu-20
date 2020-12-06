#include <stdio.h>
#include <string.h>

char skill[103][103];
int num[103][103];
int numi[103] = {0};

int swap(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int t,m,n;
    scanf("%d %d %d",&t,&m,&n);
    for(int i=1;i<=t;i++){
        scanf("%s",skill[i]);
    }
    for(int i=1;i<=m;i++){
        int cnti;
        scanf("%d",&cnti);
        for(int j=1;j<=cnti;j++){
            char sname[103];
            scanf("%s",sname);
            int value;
            scanf("%d",&value);
            for(int k=1;k<=t;k++){
                if(strcmp(sname,skill[k]) == 0){
                    num[k][numi[k]++] = value;
                    break;
                }
            }
        }
    }

    for(int i=1;i<=t;i++){
        for(int j=0;j<=numi[i]-1;j++){
            int min = num[i][j];
            int mini = j;
            for(int k=j+1;k<=numi[i]-1;k++){
                if(num[i][k] < min){
                    min = num[i][k];
                    mini = k;
                }
            }
            swap(&num[i][j],&num[i][mini]);
        }
        int sum = 0;
        int count = 1;
        while(count<=n){
            int now = num[i][numi[i]-count];
            if(now <= 0){
                break;
            }
            sum += now;
            count++;
        }
        printf("%d\n",sum);
    }
    return 0;
}