#include <stdio.h>
#include <string.h>

int main(){
	
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char s[1004];
        int cent[1004] = {0};
        
        scanf("%s",s);
        int len = strlen(s);
        
        int ans = 0;
        
        for(int i=0;i<=len-2;i++){
            for(int j=len-i-(len-i)%2;j>=2;j-=2){
            	if(cent[i+j/2]){
            		continue;
				}
            	
                int real = 1;
                for(int ip=0;ip<=j/2-1;ip++){
                	if(i+ip>len-1 || i+ip<0 || i+j-1-ip>len-1 || i+j-1-ip<0 ){
                		real = 0;
                        break;
					}
                    if(s[i+ip] != s[i+j-1-ip]){
                        real = 0;
                        break;
                    }
                }
                if(real){
                	cent[i+j/2] = 1;
                    ans+=j/2;
                }
            }
        }
        if(ans>0){
            printf("%d\n",ans);
        }
        else{
            printf("HelenCai!\n");
        }
    }
    return 0;
}
