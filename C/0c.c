#include <stdio.h>
#include <string.h>

int main(){
	int n;
	scanf("%d",&n);
	
	char names[504][504];
	char ans[504][504];
	int len[504];
	
	memset(names,0,sizeof(names));
	
	for(int i=1;i<=n;i++){
		scanf("%s",names[i]);
		len[i] = strlen(names[i]);
	}
	
	for(int i=1;i<=n-1;i++){
		char max[504];
		int locate = i;
		strcpy(max,&names[i]);
		for(int j=i+1;j<=n;j++){
			if(len[j] > len[locate]){
				strcpy(max,&names[j]);
				locate = j;
			}
			else if(len[j] == len[locate]){
				if(strcmp(names[j],names[locate])>0){
					strcpy(max,&names[j]);
					locate = j;
				}
			}
		}
		int t = len[i];
		len[i] = len[locate];
		len[locate] = t;
		
		char temp[504];
		strcpy(temp,&names[i]);
		strcpy(&names[i],&names[locate]);
		strcpy(&names[locate],temp);
	}
	
	for(int i=1;i<=n;i++){
		if(i == 1){
			printf("%s",names[i]);
		}
		else{
			printf("\n%s",names[i]);
		}
	}
	
	return 0;
}
