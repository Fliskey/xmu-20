#include <stdio.h>

int main(){
    int n;
    while(scanf("%d ",&n) != EOF){
        n %= 26;
        char c;
        int need_block = 0;
        while(scanf("%c",&c) && c!='\n'){
            if(c == ' '){
                need_block = 1;
                continue;
            }
            else if(c >= 'A' && c <= 'Z'){
                int num = c-'A';
                num += n;
                num %= 26;
                c = num + 'A';
                if(need_block){
                    printf(" ");
                    need_block = 0;
                }
                printf("%c",c);
                continue;
            }
            else if(c >= 'a' && c <= 'z'){
                int num = c-'a';
                num += n;
                num %= 26;
                c = num + 'a';
                if(need_block){
                    printf(" ");
                    need_block = 0;
                }
                printf("%c",c);
                continue;
            }
            else{
                if(need_block){
                    printf(" ");
                    need_block = 0;
                }
                printf("%c",c);
            }
        }
        printf("\n");
    }
    return 0;
}