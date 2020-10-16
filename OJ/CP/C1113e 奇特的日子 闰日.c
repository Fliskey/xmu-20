#include <stdio.h>
#include <math.h>
//C1113e 奇特的日子 闰日

int mth[14];



int rn(int n){
	if(n % 100 == 0){
		if(n % 400 == 0){
			return 1;
		}
		return 0;
	}
	if(n % 4 == 0){
		return 1;
	}
	return 0;
}

int pfs(int x){
	double kf;
	double kfz;
	
	kf = sqrt(x);
	kfz = floor(kf);
	
	if(kf == kfz){
		return 1;
	}
	return 0;
}


int main(){
	
	mth[1] = 31;
	mth[2] = 29;
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
		
	int y;
	while(scanf("%d",&y) != EOF){
		int bl = 0;
		
		if(rn(y)){
			for(int m = 1 ; m<=12 ; m++){
				
				
				int t = 0;
				t += y;
				t += m*31;
				
				for(int d = 1 ; d<=mth[m] ; d++){
					t += d;
					if(pfs(t)){
						printf("%d %d %d\n",y,m,d);
						
						bl = 1;
						break;
					}
					t -= d;
				}//for d
				
				if(bl){
					break;
				}
				
			}//for m
		}//if rn
		if(bl){
			continue;
		}
		printf("no leap day\n");
	}
	return 0;
} 
