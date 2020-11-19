#include <stdio.h>
#include <string.h>

int main(){
    char str1[1004];
    char str2[1004];
    while(scanf("%s %s",str1,str2) != EOF){
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        char head = str2[0];
        int ans = 0;
        if(len2 <= len1){
            for(int i=0; i<=len1-len2; i++){
                if(str1[i] == head){
                    int same = 1;
                    for(int ip=1; ip<len2; ip++){
                        if(str1[i+ip] != str2[ip]){
                            same = 0;
                            break;
                        }
                    }
                    ans += same;
                }
            }
        }
        printf("%d time(s)\n",ans);
        
    }
    return 0;
}