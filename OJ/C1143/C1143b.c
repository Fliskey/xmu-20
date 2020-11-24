#include <stdio.h>
#include <string.h>

int main(){
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	
    char cpt[2004];
    memset(cpt,0,sizeof(cpt));
    while(1){
        char c;
        char word[12];
        int s_point = 0;
        int rstdin = EOF; 
        while(rstdin = scanf("%c",&c) && c != '#'){
        	if(rstdin == EOF){
        		return 0;
			}
            cpt[s_point++] = c;
        }
        cpt[s_point] = '\0';
        scanf("%s",word);
        printf("%s\n%s\n\n",cpt,word);
    }
    return 0;
}
