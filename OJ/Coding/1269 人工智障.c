#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_mark(char c){
    if(c == ','){
        return 1;
    }
    if(c == '.'){
        return 1;
    }
    if(c == '!'){
        return 1;
    }
    if(c == '?'){
        return 1;
    }
    return 0;
}

int main(){
    
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    
    int n;
    scanf("%d",&n);
    char line[1404];
    scanf("\n");
    for(int i=1;i<=n;i++){
        if(i != 1){
            printf("\n");
        }
        gets(line);
    //    printf("-%s-\n",line); 

        int need_blank = 0;
        char word[1404];
        int word_point = 0;
        int j=0;
        
        for( ; j<strlen(line); j++){
            word_point = 0;
            if(line[j] != ' '){
                for( ; line[j] != ' ' && j<strlen(line); j++){
                    word[word_point++] = line[j];
                }
                if(word_point != 1 && is_mark(word[word_point-1])){
                    word_point--;
                    j-=2;
                }
                else{
                    j-=1;
                }
                word[word_point] = '\0';
                
            //    printf("\n~%s %d~\n",word,word_point);
                
                switch(word[0]){
                    case '.':{
                        printf(".");
                        need_blank = 1;
                        break;
                    }
                    case ',':{
                        printf(",");
                        need_blank = 1;
                        break;
                    }
                    case '?':{
                        printf("!");
                        need_blank = 1;
                        break;
                    }
                    case '!':{
                        printf("?");
                        need_blank = 1;
                        break;
                    }
                    case 'I':{
                        if(need_blank){
                            printf(" ");
                        }
                        if(word_point == 1){
                            printf("you");
                        }
                        else{
                            printf("%s",word);
                        }
                        
                        need_blank = 1;
                        break;
                    }
                    case 'm':{
                        if(need_blank){
                            printf(" ");
                        }
                        if(word[1] == 'e' && word_point == 2){
                            printf("you");
                        }
                        else{
                            printf("%s",word);
                        }
                        need_blank = 1;
                        break;
                    }
                    case 'y':{
                        if(need_blank){
                            printf(" ");
                        }
                        if(word[1] == 'o' && word[2] == 'u' && word_point == 3){
                            printf("I");
                        }
                        else{
                            printf("%s",word);
                        }
                        need_blank = 1;
                        break;
                    }
                    default :{
                        if(need_blank){
                            printf(" ");
                        }
                        printf("%s",word);
                        need_blank = 1;
                    }
                }
                word_point = 0;
            }
        }

    }//for 1~n
    return 0;
}
