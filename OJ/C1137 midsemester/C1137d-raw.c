#include <stdio.h>
#include <string.h>

char pbc[22][255];
char liuyan[404][255];

int main(){
	
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF){
		memset(pbc,0,sizeof(pbc));
		memset(liuyan,0,sizeof(liuyan));
		
		for(int i=1;i<=a;i++){
			scanf("%s",pbc[i]);
			
			for(int j=0;pbc[i][j] != '\0';j++){
				if(pbc[i][j] >= 'A' && pbc[i][j] <= 'Z'){
					pbc[i][j] += 32;
				}
			}
		//	printf("%s\n",pbc[i]);
		}
		scanf("\n");
		for(int i=1;i<=b;i++){
			int tiaoguo = 0;
			gets(liuyan[i]);
		//	printf("-%s\n",liuyan[i]);
			for(int j=0;liuyan[i][j] != '\0';j++){
				char head = liuyan[i][j];
				if(head >= 'A' && head <= 'Z'){
					head += 32;
				}
				for(int k=1;k<=a;k++){
					if(head == pbc[k][0]){
						int ip;
						int yizhi = 1;
						for(ip=0;ip<strlen(pbc[k]);ip++){
							char c1,c2;
							c1 = liuyan[i][j+ip];
							c2 = pbc[k][ip];
							if(c1 >= 'A' && c1 <= 'Z'){
								c1 += 32;
							}
							if(c1 != c2){
								yizhi = 0;
								break;
							}
						}
						if(yizhi){
							tiaoguo = 1;
							break;
						}
					}
					if(tiaoguo){
						break;
					}
				}
				
				if(tiaoguo){
					break;
				}
			}
			if(tiaoguo){
				continue;
			}
			printf("%s\n",liuyan[i]);
		}
		
	}
	return 0;
}
