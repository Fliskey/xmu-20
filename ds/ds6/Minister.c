#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 20

void Names(char A[][25],int n)
{
	srand(time(0));
	int i,j,k;
	for(i=0;i<n;i++)
	{
		k=2*(rand()%10+3);	//部门字数
		for(j=0;j<k;j++)
			A[i][j]=rand()%30+176; //汉字区
		A[i][j]='\0';
	}
}

void NameBubble(char A[][25],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(A[j],A[j+1])>0){
                char temp[25];
                strcpy(temp,A[j]);
                strcpy(A[j],A[j+1]);
                strcpy(A[j+1],temp);
            }
        }
    }
}

int main(){
    char Mname[N][25];
    Names(Mname,N);
    printf("排序前：\n");
    for(int i=0;i<N;i++){
        printf("%d:%s\n",i,Mname[i]);
    }
    NameBubble(Mname,N);
    
    printf("\n排序后：\n");
    for(int i=0;i<N;i++){
        printf("%d:%s\n",i,Mname[i]);
    }    

    return 0;
}
