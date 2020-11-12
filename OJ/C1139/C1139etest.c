#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    freopen("in.txt","w",stdout);
    srand((int)time(NULL));
    
    int times = 10000;
    int max = 100000;
    int n;
    int b;
    for(int i=1;i<=times;i++){
        n = rand() % max + 1;
        b = rand() % n +1;
        printf("%d %d\n",n,b);
        int seted[100005] = {0};
        for(int i=1;i<=n;i++){
    		int locate; 
	label:	locate = rand() % n +1;
            if(seted[locate] == 0){
                seted[locate] = 1;
                printf("%d ",locate);
            }
            else{
                goto label;
            }
        }
        printf("\n");
    }

    return 0;
}
