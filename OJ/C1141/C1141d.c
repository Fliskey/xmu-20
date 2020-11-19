#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int scmp(const void* _a,const void* _b){
    char* a = (char*) _a;
    char* b = (char*) _b;
    return strcmp(a,b);
}

int main(){
    char names[104][14];
    char line[1004];
    int have_printed = 0;
    while(gets(line)){
        memset(names,0,sizeof(names));
        
        int number = 0;
        int ip = 0;
        for(int i=0; i<strlen(line); i++){
            if(line[i] == ' '){
                if(ip != 0){
                    names[number][ip] = '\0';
                    ip = 0;
                    number++;
                }
                continue;
            }
            names[number][ip++] = line[i];
        }
        if(ip == 0){
            number--;
        }
        else{
            names[number][ip] = '\0';
        }
        
        if(number == -1){
            continue;
        }

        qsort(names,number+1,sizeof(names[0]),scmp);
       
        if(have_printed){
            printf("\n");
        }
        for(int i=0;i<=number;i++){
            if(i == 0){
                printf("%s",names[i]);
                continue;
            }
            printf(" %s",names[i]);
        }
        have_printed = 1;  
    }
    
    return 0;
}