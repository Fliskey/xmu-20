#include <stdio.h>
#include <string.h>

int main(){
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
    char password[260];
    memset(password,0,sizeof(password));
    int is_first = 1;
    while(gets(password)){
        int l = 0;
        while(password[l]!=0){
            l++;
        }
        password[l] = '\0';
        if(strlen(password)<8){
            printf("Week\n");
            continue;
        }
        int dx = 0;
        int xx = 0;
        int sz = 0;
        int fh = 0;
        for(int i=0;i<strlen(password);i++){
            char c = password[i];
            if(c >= '0' && c <= '9'){
                sz++;
            }
            else if(c >= 'a' && c <= 'z'){
                xx++;
            }
            else if(c >= 'A' && c <= 'Z'){
                dx++;
            }
            else if(c >= 32 && c <= 126){
                fh++;
            }
        }
        int ans = 0;
        if(sz){
            ans++;
        }
        if(xx){
            ans++;
        }
        if(dx){
            ans++;
        }
        if(fh){
            ans++;
        }
        if(ans == 3 || ans == 4){
            printf("Strong\n");
        }
        else{
            printf("Week\n");
        }
        is_first = 0;
        memset(password,0,sizeof(password));
    }
    return 0;
}
