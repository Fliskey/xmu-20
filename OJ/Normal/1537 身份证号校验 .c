#include <stdio.h>
//1537 身份证号校验 

int main(){
	char sfz[30];
	int xs[17]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	
	while(scanf("%s",&sfz) != EOF){
		int jym = sfz[17];
		int sum = 0;
		for(int i=0;i<=16;i++){
			int value = ((int)sfz[i] - '0') * xs[i];
			sum += value;
		}
		sum %= 11;
	//	printf("%d\n",sum);
		char cr;
		switch (sum){
			case 0:{
				cr = '1';
				break;
			}
			case 1:{
				cr = '0';
				break;
			}
			case 2:{
				cr = 'X';
				break;
			}
			case 3:{
				cr = '9';
				break;
			}
			case 4:{
				cr = '8';
				break;
			}
			case 5:{
				cr = '7';
				break;
			}
			case 6:{
				cr = '6';
				break;
			}
			case 7:{
				cr = '5';
				break;
			}
			case 8:{
				cr = '4';
				break;
			}
			case 9:{
				cr = '3';
				break;
			}
			case 10:{
				cr = '2';
				break;
			}
		}
		if(cr == jym){
			printf("1\n");
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}
