#include <stdio.h>

int ifch(char c){
	if(c >= 'a' && c <= 'z')
		return 1;
	if(c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int ifnum(char c){
	if(c >= '0' && c <= '9')
		return 1;
	return 0;
}

int if_(char c){
	if(c == '_')
		return 1;
	return 0;
}

int ifhead(char c){
	int ans = 0;
	ans += ifch(c);
	ans += if_(c);
	if(ans == 1){
		return 1;
	}
	return 0;
}

int ifmid(char c){
	int ans = 0;
	ans += ifch(c);
	ans += ifnum(c);
	ans += if_(c);
	if(ans == 1){
		return 1;
	}
	return 0;
}

int main(){
	
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		
		int s;
		scanf("%d",&s);
		int is_first = 1;
		
		for(int j=1 ; j<=s ; j++){
			char name[20];
			scanf("%s",name);
			
			int ans = 1; 
			if(!ifhead(name[0])){
				ans = 0;
			}
			else{
				for(int k=1 ; name[k]!='\0' ; k++){
					if(!ifmid(name[k])){
						ans = 0;
						break;
					}
				}
			}
			
			if(is_first){
				printf("%d",ans);
				is_first = 0;
			}
			else{
				printf(" %d",ans);
			}
		}
		printf("\n");
		
	}
	return 0;
}