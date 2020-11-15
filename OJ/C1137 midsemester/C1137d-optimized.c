#include <stdio.h>
#include <string.h>

char shield[22][255];
char barrage[404][255];

void lowletter(char *c){
	if(*c >= 'A' && *c <= 'Z'){
		*c += 32;
	}
}

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF)
	{
		memset(shield,0,sizeof(shield));
		memset(barrage,0,sizeof(barrage));
		
		for(int i=1 ; i<=a ; i++){
			scanf("%s",shield[i]);
			
			for(int j=0 ; shield[i][j] != '\0' ; j++){
				lowletter(&shield[i][j]);
			}
		}//for:a

		scanf("\n");

		for(int i=1 ; i<=b ; i++){
			gets(barrage[i]);
			
			for(int j=0 ; barrage[i][j] != '\0' ; j++){
				char head = barrage[i][j];
				lowletter(&head);

				for(int k=1;k<=a;k++){
					if(head == shield[k][0]){
						int ip;
						int if_same = 1;
						for(ip=0 ; ip<strlen(shield[k]) ; ip++){
							char c1,c2;
							c1 = barrage[i][j+ip];
							c2 = shield[k][ip];
							lowletter(&c1);

							if(c1 != c2){
								if_same = 0;
								break;
							}
						}
						if(if_same){
							goto skip;
						}
					}
				}
			}
			printf("%s\n",barrage[i]);
			skip : continue;
		}//for:b
	}//while
	return 0;
}
