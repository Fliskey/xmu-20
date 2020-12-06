#include <stdio.h>

int map[103][103] = {0};

int xmin = 101;
int ymin = 101;
int xmax = 0;
int ymax = 0;

int check(int x,int y){
    if(x < xmin){
        xmin = x;
    }
    if(y < ymin){
        ymin = y;
    }
    if(x > xmax){
        xmax = x;
    }
    if(y > ymax){
        ymax = y;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t>=1){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x1,y1;
            scanf("%d %d",&x1,&y1);
            check(x1,y1);

            int x2,y2;
            scanf("%d %d",&x2,&y2);
            check(x2,y2);



            for(int j=1;j<=i;j++){
                if(i == j)  continue;
            }
        }
        t--;
    }
    return 0;
}