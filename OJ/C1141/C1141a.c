#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[1004],str2[1004];
    while(scanf("%s %s",str1,str2) != EOF){
        int exist = 0;
        int ascii_usd[260][1004];
        memset(ascii_usd,0,sizeof(ascii_usd));

        int len1 = strlen(str1);
        int len2 = strlen(str2);

        for(int i=0; i<len1; i++){
            int value = str1[i];
            int ip = ascii_usd[value][0] + 1;
            ascii_usd[value][0]++;
            ascii_usd[value][ip] = i;
        }

        int ansbegin = 0;
        int anslenth = 0;

        for(int i=0;i<len2; i++){
            int lenth2 = len2-i;
            char head = str2[i];
            int value = head;
            if(ascii_usd[value][0] != 0){
                int number = ascii_usd[value][0];
                for(int j=1; j<=number ; j++){
                    int locate = ascii_usd[value][j];
                    int lenth1 = len1-locate;
                    int min = lenth1 > lenth2 ? lenth2 : lenth1;
                    int tempbegin = locate;
                    int templenth = 0;
                    for(int ip=0; ip<min; ip++){
                        if(str1[locate+ip] == str2[i+ip]){
                            templenth++;
                        }
                        else{
                            break;
                        }
                    }
                    if(templenth > anslenth){
                        anslenth = templenth;
                        ansbegin = tempbegin;
                    }
                }
            }
        }
        if(anslenth != 0){
            for(int i=0; i<anslenth; i++){
                printf("%c",str1[ansbegin+i]);
            }
        }
        else{
            printf("#");
        }
        printf("\n");
    }
    return 0;
}