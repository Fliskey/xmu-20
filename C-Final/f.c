#include <stdio.h>
#include <math.h>
int main(){
	double W,H,w,h;
	scanf("%lf %lf %lf %lf",&W,&H,&w,&h);
	double s1,s2;
	s1 = w/W;
	s2 = h/H;
	printf("%.10f %.10f\n",s1,s2);
	int ans1 = 0;
	int times = 0;
	while(s1 != 1){
		s1 *= 2;
		int n = floor(s1);
		ans1 += n;
		times++;
		if(times > 200){
			printf("-1");
			return 0;
		}
	}
	int ans2 = 0;
	times = 0;
	while(s2 != 1){
		s2 *= 2;
		int n = floor(s2);
		ans2 += n;
		times++;
		if(times > 200){
			printf("-1");
			return 0;
		}
	}
	int ans = ans1+ans2;
	printf("%d",ans);
	return 0;
}
