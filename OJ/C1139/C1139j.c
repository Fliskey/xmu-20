#include <stdio.h>
#include <math.h>

double a,b,c,d;
double fx(double x){
	double ans = 0;
	ans += a*x*x*x;
	ans += b*x*x;
	ans += c*x;
	ans += d;
    return ans;
}

int main(){
    
    int is_first = 1;
    while(scanf("%lf %lf %lf %lf",&a,&b,&c,&d) != EOF){
    	if(!is_first){
    		printf("\n");
		}

        double value[204];
        memset(value,0,sizeof(value));
        for(int i=-100;i<=100;i++){
            value[i+100] = fx(i);
        //	printf("%d:%.2f\n",i,value[i+100]);
        }

        double ans[204];
        int ansn = 0;
        memset(ans,0,sizeof(ans));

        if(value[0] == 0){
			ans[++ansn] = -100;
		}
		
        for(int i=-99;i<=100;i++){
            if(value[i+100] == 0){
            	ans[++ansn] = i;
			}
			else if(value[i+100] * value[i-1+100] < 0){
				//ans is between i&i-1
				int count = 0;
				double l,r;
				l = i-1;
				r = i;
				double fl = value[i-1+100];
				double fr = value[i+100];
				double m;
				double fm;
				while(count <= 20){
					m = (l+r)/2.0;
				//	printf("%.2f\n",m);
					fm = fx(m);
					if(fm * fl < 0){
						fr = fm;
						r = m;
					}
					else if(fm * fr < 0){
						fl = fm;
						l = m;
					}
					else if(fm == 0){
						ans[++ansn] = m;
					//	printf("%d:%.6f\n",count,m);
					}
					count++;
				}
				ans[++ansn] = m;
			}
        }
        printf("%.2f %.2f %.2f",ans[1],ans[2],ans[3]);
		is_first = 0;
    }
    return 0;
}
