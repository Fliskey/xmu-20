#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define NPT 1
#define HLS 2
#define ZCA 3
#define SXC 4
#define FRH 5
#define SYG 6
#define BCST 7

#define NUM 7
#define MAXNUM 0x7fffffff

int dis[NUM+1][MUN+1];
int nodeQueue[NUM+1];

struct{
	int fa;
	int len;
}value[NUM+1];

int initdis();
int printmenu();
int getkey();
int plan();
int plotcode();
int dijkstra();

int from = 0;
int reach[NUM+1];

int main(){
	memset(reach,MAXNUM,sizeof(reach));
	initdis();
	printf("Welcome to xmu tourism system!\n");
	Sleep(1000);
	system("CLS");
	int ret_value = 1;
	do{
		printmenu();
		char gk = getkey();
		if(gk == 'Q'){
			ret_value = 0;
		}
		else if(gk == 'P'){
			plan();
		}
		
	}while(ret_value);
	printf("Thank you for using! Have a good trip!");
	Sleep(1000);
	return 0;
}

int plan(){
	plotcode();
	int a=0 ,b=0;
	char c = getkey();
	while(c < 0 || c > 9){
		c = getkey();
	}
	a = c;
	
	c = getkey();
	while(c < 0 || c > 9){
		c = getkey();
	}
	b = c;

	printf("from %d to %d:",a,b);
	
}

int plotcode(){
	printf("1 : 南普陀寺\n");
	printf("2 : 胡里山炮台\n");
	printf("3 : 曾厝垵\n");
	printf("4 : 上弦场\n");
	printf("5 : 芙蓉湖\n");
	printf("6 : 思源谷\n");
	printf("7 : 白城沙滩\n");
}

int getkey(){
	char c;
	while(c = getch()){
		if(c >= '0' && c <= '9'){
			return c-'0';
		}
		if(c == 'Q' || c == 'q'){
			return 'Q';
		}
		if(c == 'P' || c == 'p'){
			return 'P';
		}
		printf("Wrong Key! Press again!\n");
	}
}

int printmenu(){
	printf("Press a key to continue\n");
	printf("Q: Quit the system\n");
	printf("P: Planning tourist routes")
}

int initdis(){
	for(int i=1;i<=NUM;i++){
		dis[i][i] = 0;
	}
	dis[1][5] = dis[5][1] = 7;
	dis[1][6] = dis[6][1] = 11;
	
	dis[2][3] = dis[3][2] = 24;
	dis[2][6] = dis[6][2] = 12;
	dis[2][7] = dis[7][2] = 5;
	
	dis[3][7] = dis[7][3] = 28;
	
	dis[4][5] = dis[5][4] = 7;
	dis[4][6] = dis[6][4] = 12;
	dis[4][7] = dis[7][4] = 9;
	
	dis[5][6] = dis[6][5] = 7;
	dis[5][7] = dis[7][5] = 13;
	
	dis[6][7] = dis[7][6] = 13;
}

int dijkstra(){
	memset(nodeQueue,MAXNUM,sizeof(nodeQueue));
	int qi = 1;
	nodeQueue[qi] = ;
	for(int i=1;i<=NUM;i++){
		value[i].fa = i;
		value[i].len = MAXNUM;
	}
	while(qi <= NUM){
		int now = nodeQueue[qi];
		for(int i=1;i<=NUM;i++){
			int d = dis[now][i];
			if(d){
				if(value[now].len + d > )
			}
		}
	}
}