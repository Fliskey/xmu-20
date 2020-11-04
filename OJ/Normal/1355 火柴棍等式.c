#include <stdio.h>
//1355 火柴棍等式 

int main(){
	int num[10]={6,2,5,5,4,5,6,3,7,6};
	
	
	int n;
	
	while(scanf("%d",&n) != EOF){
		n -= 4;
		int ans = 0;
		
		for(int a=0 ; a<=1000 ; a++){
			//拆出a的根数
			int an = 0;
			int ax = a;
			if(ax == 0){
				an = num[0];
			}
			else
				while(ax != 0){
					int x = ax % 10;
					an += num[x];
					ax /= 10;
				} 
			//如果已经超出根数则取下一个a 
			if(an > n){
				continue;
			}
			
			//取b 
			for(int b=0 ; b<=1000 ;b++){
				
				//拆出b的根数 
				int bn = 0;
				int bx = b;
				if(bx == 0){
					bn = num[0];
				}
				else
					while(bx != 0){
						int x = bx % 10;
						bn += num[x];
						bx /= 10;
					} 
				
				if(bn+an > n){
					continue;
				}
				
				//拆出sum的根数 
				int sum = a+b;
				int sn = 0;
				int sx = sum;
				if(sx == 0){
					sn = num[0];
				}
				else
					while(sx != 0){
						int x = sx % 10;
						sn += num[x];
						sx /= 10;
					} 
				
				
				if(an+bn+sn == n){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	
	}
	
	return 0;
}
