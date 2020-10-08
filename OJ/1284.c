#include <stdio.h>
#define mint 210000000

//全局变量 
int sz[mint] = {0}; //模拟用 
int sw[102] = {0}; //石子位置
int swl = 0; //sw配套迭代器 
int L,S,T,M;

int smin = 200;
int stmin[mint] = {200};//从stmin出发最少石子数 

int sstone(int i,int szs){  //i标志当前青蛙位置，szs当前石子数 
	printf("i:%d szs:%d smin:%d\n",i,szs,smin);
	
	if(i >= L || i > sw[swl-1]){
		if(szs < smin){
			smin = szs;
		}
		return smin;
	}
	else{
		int lmin = 200;//当前循环的最小值弹回上一层 
		int lll = 0;//临时存放sstone返回值 
		for(int j = T; j >= S ; j--){
			if(sz[i+j] == 1){
				if(szs + 1 <= smin){
					lll = sstone(i+j, szs+1);
					if(lll < lmin){
						lmin = lll;
					}
				}
				else{
					continue;
				}
			}
			else{
				lll = sstone(i+j, szs);
				if(lll < lmin){
					lmin = lll;
				}
			}
		}
		return lmin;
	}
}

int main(){

	scanf("%d",&L);
	scanf("%d %d %d",&S,&T,&M);
	for(int i = 1; i <= M ; i++){
		int a;
		scanf("%d",&a);
		sz[a] = 1;
		sw[swl] = a;
		swl++;
	} 
	printf("%d",sstone(0,0));
	return 0;
} 
