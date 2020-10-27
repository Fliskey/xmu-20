#include <stdio.h>
//C1133i Ê±¼äÍÆÒÆ 

int rn(int y){
	if(y % 100 == 0){
		if(y % 400 == 0){
			return 1;
		}
		return 0;
	}
	else if(y % 4 == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	
	freopen("in.txt","r",stdin);
	
	int year,month,day;
	int hour,min,sec;
	
	char zf;
	
	int ts;
	int ph,pm,ps;
	
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
	
	scanf("%d-%d-%d %d:%d:%d %c %d %d:%d:%d",&year,&month,&day,&hour,&min,&sec,&zf,&ts,&ph,&pm,&ps);
	
	if(rn(year) == 1){
		mth[2] = 29;
	}
	else{
		mth[2] = 28;
	}
	
	if(zf == '+'){
		sec += ps;
		while(sec >= 60){
			sec -= 60;
			min++;
		}
		
		min += pm;
		while(min >= 60){
			min -= 60;
			hour++;
		}
		
		hour += ph;
		while(hour >= 24){
			hour -= 24;
			ts++;
		}
		
		while(ts != 0){
			ts--;
			day++;
			if(day > mth[month]){
				day = 1;
				month++;
				if(month == 13){
					month = 1;
					year++;
					if(rn(year)){
						mth[2] = 29;
					}
					else{
						mth[2] = 28;
					}
				}
			}
		}
		
	}
	
	if(zf == '-'){
		sec-= ps;
		while(sec < 0){
			sec += 60;
			min--;
		}
		
		min -= pm;
		while(min < 0){
			min += 60;
			hour--;
		}
		
		hour -= ph;
		while(hour < 0){
			hour += 24;
			ts++;
		}
		
		
		while(ts != 0){
			day--;
			if(day == 0){
				month--;
				if(month == 0){
					year--;
					if(rn(year)){
						mth[2] = 29;
					}
					else{
						mth[2] = 28;
					}
					month = 12;
				}
				day = mth[month];
			}
			ts--;
		}
	}
	
	printf("%04d-%02d-%02d %02d:%02d:%02d",year,month,day,hour,min,sec);
	
	
	return 0;
}
