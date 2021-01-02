#include <stdio.h>
#include <string.h>

char line[20];
int price[4] = {0,3899,199,99};
int shop[4] = {0};
int total = 0;
int min = 0;

int deata(int sum){
	int max = 0;
	for(int i=0;i<=sum/300;i++){
		for(int j=0;j<=sum/500;j++){
			if(i*300 + j*500 > sum){
				continue;
			}
			int num = i*40 + j*70;
			if(num > max){
				max = num;
			}
		}
	}
	sum -= max;
	if(sum >= 1000){
		sum -= 50;
	}
	else if(sum >= 6){
		sum -= 5;
	}
	return sum;
}

int main(){
	memset(line,0,sizeof(line));
	while(gets(line)){
		total = 0;
		memset(shop,0,sizeof(shop));
		int l = 0;
		
		for(int i=1;i<=3;i++){
			if(line[l] == 0){
				break;
			}
			l++;
			int s = line[l] - '0';
			l++;
			int num = line[l] - '0';
			num *= 10;
			l++;
			num += line[l] -'0';
			l++;
			l++;
			shop[s] += num;
		}
		
		for(int i=1;i<=3;i++){
			total += shop[i] * price[i];
		}
		total = deata(total);
		printf("%d\n",total);
		memset(line,0,sizeof(line));
	}
	return 0;
}
