#include <stdio.h>
#include <string.h>

int main(){
    char line1[1004];
    char line2[1004];

    char words1[104][14];
    char words2[104][14];

    int number=0, ip=0;

    gets(line1);
    int i=0;
    while(line1[i] == ' '){
        i++;
    }
    for(; i<strlen(line1); i++){
        if(line1[i] == ' '){
            if(ip != 0){
                words1[number][ip] = '\0';
                ip = 0;
                number++;
            }
            continue;
        }
        else{
            words1[number][ip++] = line1[i];
        }
    }
    if(ip == 0){
        number--;
    }
    else{
        words1[number][ip] = '\0';
    }

    number = 0;
    ip = 0;
    i = 0;

    gets(line2);
    for(; i<strlen(line2); i++){
        if(line2[i] == ' '){
            if(ip != 0){
                words2[number][ip] = '\0';
                ip = 0;
                number++;
            }
            continue;
        }
        else{
            words2[number][ip++] = line2[i];
        }
    }
    if(ip == 0){
        number--;
    }
    else{
        words2[number][ip] = '\0';
    }

    for(i=0; i<=number; i++){
        int len = strlen(words2[i]);
        char head = words2[i][0];
        for(int j=0; words1[j][0] != 0; j++){
            int j_len = strlen(words1[j]);
            if(j_len != len){
                continue;
            }
            else{
                int same = 1;
                for(ip=0; ip<len; ip++){
                    if(words2[i][ip] != words1[j][ip]){
                        same = 0;
                        break;
                    }
                }
                if(same){
                    printf("(%d,%d)",i,j);
                }
            }
        }
    }

    return 0;
}