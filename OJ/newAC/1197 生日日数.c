#include <stdio.h>
//1189 简单的模拟 一万天纪念日 
//1897 输出格式 


int rn(int y){
	if(y % 100 == 0){
		if(y % 400 == 0){
			return 1;
		}
		return 0;
	}
	if(y % 4 == 0){
		return 1;
	}
	return 0;
}

int main(){
	int yy,mm,dd;
	
	
	int mth[14];
	mth[1] = 31;
	mth[2] = 28;
	mth[3] = 31;
	mth[4] = 30;
	mth[5] = 31;
	mth[6] = 30;
	mth[7] = 31;
	mth[8] = 31;
	mth[9] = 30;
	mth[10] = 31;
	mth[11] = 30;
	mth[12] = 31;
	
	while(scanf("%d %d %d",&yy,&mm,&dd) != EOF){
		
		if(rn(yy)){
			mth[2] = 29;
		}
		else{
			mth[2] = 28;
		}
		
		for(int i=1 ; i<=10000 ; i++){
			dd++;
			if(mth[mm] < dd){
				mm++;
				dd = 1;
			}
			if(mm > 12){
				mm -= 12;
				yy++;
				if(rn(yy)){
					mth[2] = 29;
				}
				else{
					mth[2] = 28;
				}
			}
		}
		
		printf("%04d-%02d-%02d\n",yy,mm,dd);
	}
	
	
	
	return 0;
}
