#include <stdio.h>
#include <string.h>

char line[100004];

int main(){
	
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	
    while(gets(line)){
        int len = strlen(line);
        int count_dot = 0;
        int dot_locate[4];
        dot_locate[0] = 0;
        for(int i=0;i<len;i++){
            if(line[i] == '.'){
                count_dot++;
                if(count_dot > 3){
                    break;
                }
                dot_locate[count_dot] = i;
            }
            else if(line[i] == ' '){
                continue;
            }
            else if(line[i] < '0' || line[i] > '9'){
            	printf("NOT_A_NUMBER\n");
                goto NO;
			}
        }
        if(count_dot != 3){
        	printf("DOT_NOT_EQUAL_3\n");
        	goto NO;
		}
            
        
        int n = 0;

        int i=0;

        for(int j=1;j<=3;j++){
            while(line[i] == ' '){
            	i++;
			}
			int deata = dot_locate[j] - dot_locate[j-1];
			printf("deata%d:%d\n",j,deata);
            if(i-dot_locate[j-1] >= 3){
            	printf("TOO_LONG\n");
            	goto NO;
			}

            for(;i<dot_locate[j];i++){
                n += (int)(line[i] - '0');
                printf("%d %d\n",i,n);
                n*=10;
            }
			i+=2;
            printf("%d ",n);
            n = 0;
        }
        
		printf("\n");
        if(0){
            NO:
                printf("NO\n");
                continue;
        }
    }
    return 0;
}
