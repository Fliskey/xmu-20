#include <stdio.h>
int main(){
	char a[23333];
	gets(a);
	char b[23333];
	int l=0;
	for(int i = 0; a[i] != '\0'; i++){
		switch(a[i]){
			case 'a':{
				b[l] = 'a';
				l++;
				break;
			}
			case 'e':{
				b[l] = 'e';
				l++;
				break;
			}
			case 'i':{
				b[l] = 'i';
				l++;
				break;
			}
			case 'o':{
				b[l] = 'o';
				l++;
				break;
			}
			case 'u':{
				b[l] = 'u';
				l++;
				break;
			}
		}
	}
	for(int i = 0; i<l; i++){
		printf("%c",b[i]);
	}
	return 0;
}
