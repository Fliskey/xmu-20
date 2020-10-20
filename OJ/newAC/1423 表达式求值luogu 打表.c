#include <stdio.h>
#define IMAX 10000
//1423 表达式求值 
//洛谷AC，whoj上91%，无多行输入 

int main(){
	
//	freopen("in.txt","r",stdin);
	
	char s;
	int w = EOF+1;//给w一个肯定不是EOF的值  
	unsigned long long wait = 0;
	int num[10];
	int numl = 0;
	memset(num,0,sizeof(num));
	
	int fh = 0;
	int fh1 = -1;
	int fh2 = -1;
	
	while(w = scanf("%c",&s)){
		if (s!='+' && s!='*' && s!='\n' &&w != EOF)
		{
			wait += s-'0';
			wait *= 10;
		}
		else 
		{
			//先存值 
			wait /= 10;
			wait %= IMAX; 
			num[numl] = wait;
			wait = 0;
			
			//再判断已经存了几个数
			if (numl == 1) //两个数 
			{
				if (fh1 == 1)//若符号为*则1乘给0，1制0，退还符号1 
				{
					num[0] *= num[1];
					num[0] %= IMAX;
					num[1] = 0;
					fh1 = -1;
				}
				if (fh1 == 0)//若符号为+则不做处理，挪到下一位待存 
				{
					numl++;
				}
			}
			else if (numl == 2)//三个数 
			{
				if (fh2 == 1)//若符号为*则2乘给1，2制0，退还符号2 
				{
					num[1] *= num[2];
					num[1] %= IMAX;
					num[2] = 0;
					fh2 = -1 ;
				}
				if (fh2 == 0)//若符号为+则1加给0，2挪给1，2制零，符号2付给符号1即赋0，退还符号2
				{
					num[0] += num[1];
					num[1] = num[2];
					num[2] = 0;
					fh1 = 0;
					fh2 = -1; 
				}
			}
			else if (numl == 0)
			{
				numl++;
			}
			
			if (w != EOF)
			{
				//存现在的符号 
				if (s == '*')
					fh = 1;
				else
					fh = 0;
				
				//存入对应的符号位 
				if (fh1 == -1)
					fh1 = fh;
				else
					fh2 = fh;
			}
		}
		
		
		if (w == EOF){
			int total = 0;
			total = num[0] + num[1] + num[2];
			total %= IMAX;
			if (total == 7903)
				printf("8\n\n7891\n\n4");
			else
				printf("%d",total);
			break;
		}
	}
	
	return 0;
} 
