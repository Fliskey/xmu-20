//1370 二进制数问题 
#include <stdio.h>

int main(){
	int n;
	int a = 0,b = 0;
	for(int i=1;i<=1000;i++){
		int o = 0,z = 0;
		
		int q = i;
		while(q != 0){
			if(q % 2 == 1){
				o++;
			}
			else{
				z++;
			}
			q/=2;
		}
		if(o>z){
			a++;
		}
		else{
			b++;
		}
	}
	printf("%d %d",a,b);
	return 0;
}
