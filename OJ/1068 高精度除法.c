#include <stdio.h>
#define int unsigned long long

int pl(int n,int* p){
	for(int i=0;i<=n;i++){
		printf("%ld",p[i]);
	}
	printf("\n");
	return 1;
}

int main(){
	int list[200] = {0};
	
	int a,b,c;
	
	while(scanf("%ld %ld %ld",&a,&b,&c) != EOF){
		int l = 0;//指向list，作迭代器 
		int k = 0;//存已输出小数位数
		//先输出小数点左边：
		int ans = a/b;
		if(ans == 0){
			list[l] = 0;
			l++;
		}
		else{
			while(ans > 0){
				list[l] = ans%10;
				ans /= 10;
				l++;
			}//每次取个位数 	
		}
		
		for(int i=0;i<=(l-1)/2;i++){
			int j = list[i];
			list[i] = list[l-1-i];
			list[l-1-i] = j;
		}//反转数组 
		int xs = l;//小数点左坐标 
	//	printf("%ld.",ans);
		//再输出小数点右边：
		a = a % b * 10; 
		while(k != c+1){
			list[l] = a/b;
			l++;
		//	printf("%ld",a/b);
			a = a % b * 10;                                                   			k++;
		} 
		int len = l;//总长 
		l--;
	//	printf("%ld ",list[l]);
		
	//	pl(len,list);
		
		if(list[l]>=5){//四舍五入 
			l--; 
			list[l]++;
			while(list[l] >= 10){
				list[l] -= 10;
				l--;
				list[l]++;
			}
		} 
		if(l == 0 && list[l] == 0){
			printf("1");
		}
		else{
			if(list[0] == 0 && list[1] == 0 && xs>1){
				printf("1");
			}
		}
		for(int i=0;i<=xs-1;i++){
			printf("%ld",list[i]);
			list[i] = 0;
		}
		if(c != 0){
			printf(".");
		}
		for(int i=xs;i<=len-2;i++){
			printf("%ld",list[i]);
			list[i] = 0;
		}
		for(int i=len-1;i<=len;i++){
			list[i] = 0;
		}
		printf("\n");
	}
	
	return 0;
}
