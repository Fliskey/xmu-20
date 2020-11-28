#include <stdio.h>
#include <string.h>

int main(){
		
    int point;
    int ch;
    char cpt[2004];
    char block[14];

    point = 0;
    memset(cpt,-1,sizeof(cpt));
    memset(block,-1,sizeof(block));
    int need_end;
start:
    need_end = 1;
    while(ch = getchar()){
        if(ch == '#'){
            need_end = 0;
            break;
        }
        if(ch == '\n' || ch == '\r'){
            continue;
        }
        cpt[point++] = ch;
    }
    if(need_end){
        return 0;
    }

    scanf("%s",block);
    int len_block = strlen(block);
    char head_block = block[0];

    int count = 0;
    for(int i=0;i<=point - len_block;i++){
        if(cpt[i] == head_block){
            int ip = 1;
            while(cpt[i+ip] == block[ip] && ip++<len_block);
            if(ip == len_block){
                count++;
            }
        }
    }

    printf("%d time(s)",count);
    if(ch = getchar()){
    	if(ch == EOF){
    		return 0;
		}
        printf("\n");
		
        point = 0;
        memset(cpt,-1,sizeof(cpt));
        memset(block,-1,sizeof(block));

        cpt[point++] = ch;
        goto start;
    }

    return 0;
}
