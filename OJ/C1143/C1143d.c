#include <stdio.h>

int count = 1;
int is_big_first = 1;

int HNT(int n,char from,char mid,char to){
    if(n == 1){
        if(is_big_first == 0){
            printf("\nStep %d:%c -> %c",count++,from,to);
        }
        else{
            printf("Step %d:%c -> %c",count++,from,to);
            is_big_first = 0;
        }
        
        return 1;
    }
    else{
        HNT(n-1,from,to,mid);
        HNT(1,from,mid,to);
        HNT(n-1,mid,from,to);
    }
}

int main(){
    int n;
    int is_first = 1;
    while(scanf("%d",&n) != EOF){
        if(is_first == 0){
            printf("\n");
        }
        is_big_first = 1;
        count = 1;
        HNT(n,'A','B','C');
        
        if(is_first){
            is_first = 0;
        }
    }
    return 0;
}