#include <stdio.h>

//1404 Êý×Ö·´×ªNOIP
char a[19];
int main(){
	scanf("%s",a);
	
	int l = 0;
	for(l=0; a[l]!='\0'; l++);
	
	
	int j = 0;
	
	if(a[0] == '-'){
		printf("-");
		j++;
	}
	
	while(a[l-1] == '0'){
		if(l-1 != j){
			l--;
		}
	}
	
	for(int i=l-1; i>=j; i--){
		printf("%c",a[i]);
	}
	
	return 0;
} 
