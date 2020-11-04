#include <stdio.h>
#include <math.h>
//1153 柚子茶
//公式是从王子夏那学的

int main(){
	int n;
	while (scanf("%d",&n) && n!=0){
		//按位取出数据存到三个变量中，再存下当前位的十次方 
		//278
		//	27 8 0	1
		//	2 7 8	2
		//	0 2 78	3
		int ans = 0;
		
		int l = 0;
		int m = 0;
		int r = 0;
		int p = 0;
		
		l = n / 10;
		m = n % 10;
		r = 0; //初值为0
		
		while (r != n){
			if (m > 7){
				ans += (l+1) * pow(10,p);
			}
			else if (m == 7){
				ans += l*pow(10,p) + r + 1;
			}
			else{
				ans += l*pow(10,p);
			}
			
			//向左移位
			r += m*pow(10,p);
			m = l%10;
			l /= 10;
			p++;
		} 
		
		printf("%d\n",ans);
	}
	
	
	return 0;
} 
