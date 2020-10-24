#include <stdio.h>
//1277 生成函数 类斐波那契
//不带优化的递推，容易超时 

int md(char *s,int x){
	int i = 0;
	int a,b;
	a = s[0] - '0';
	b = x;
	int c;
	while(s[i] != '\0'){
		c = a%b;
		c *= 10;
		i++;
		if(s[i] == '\0'){
			return c/10;
		}
		c += s[i] - '0';
		a = c;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		long long int a,b,n;
		char s[20];
		long long int c;
		scanf("%ld %ld %s",&a,&b,&s);
		n = md(s,6);
		if(n <= 2){
			n += 6;
		}
		
		while(n != 2){
			c = b - a;
			a = b;
			b = c;
			n--;
		}
		printf("%ld\n",c);
	} 
	return 0;
} 
