#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define NPT "南普陀寺"
#define HLS "胡里山炮台"
#define ZCA "曾厝垵"
#define SXC "上弦场"
#define FRH "芙蓉湖"
#define SYG "思源谷"
#define BCST "白城沙滩"

#define NUM 7
#define MAXNUM 50
#define swap(x,y) (x ^= y, y ^= x, x ^= y)

int dis[NUM+1][NUM+1];
int queue[NUM+2];
int flag[NUM+2];
int stack[NUM+2];

struct vl{
	int fa;
	int len;
}value[NUM+1];

int initdis();
int printmenu();
int getkey(int);
int plan();
int plotcode();
int dijkstra();
int printroute(int,int);
int test();

int from = 0;
int reach[NUM+1];

int main(){
	memset(reach,MAXNUM,sizeof(reach));
	initdis();
//	test();
//	Sleep(10000);
	printf("欢迎使用厦门大学旅游咨询系统！\n\n");
	Sleep(1000);
//	system("CLS");
	int ret_value = 1;
	do{
		printmenu();
		char gk = getkey(1);
		while(gk!='Q' && gk!='P'){
			gk = getkey(1);
		}
		if(gk == 'Q'){
			ret_value = 0;
		}
		else if(gk == 'P'){
			plan();
		}
	}while(ret_value);
	printf("\n感谢使用，祝您旅途愉快！");
	Sleep(1000);
	return 0;
}

int plan(){
	plotcode();
	int a=0 ,b=0;
	printf("\n出发地编号: ");
	char c = getkey(0);
	while(c < 0 || c > 9){
		c = getkey(0);
	}
	a = c;
	printf("%d 目的地编号: ",a);
	
	c = getkey(0);
	while(c < 0 || c > 9){
		c = getkey(0);
	}
	b = c;

	printf("%d\n",b);

	from = a;
	dijkstra();
	printroute(a,b);
	return 0;
}

int plotname(int i){
	switch(i){
		case(1):{
			printf("%s",NPT);
			break;
		}
		case(2):{
			printf("%s",HLS);
			break;
		}
		case(3):{
			printf("%s",ZCA);
			break;
		}
		case(4):{
			printf("%s",SXC);
			break;
		}
		case(5):{
			printf("%s",FRH);
			break;
		}
		case(6):{
			printf("%s",SYG);
			break;
		}
		case(7):{
			printf("%s",BCST);
			break;
		}
		default:{
			return 0;
		}
	}
}

int plotcode(){
	printf("\n景点编号表：\n");
	for(int i=1;i<=NUM;i++){
		printf("%d : ",i);
		plotname(i);
		printf("\n");
	}
}

int getkey(int m){
	char c;
	while(c = getch()){
		if(c-'0' >= 1 && c-'0' <= NUM){
			return c-'0';
		}
		if(c == 'Q' || c == 'q'){
			return 'Q';
		}
		if(c == 'P' || c == 'p'){
			return 'P';
		}
		if(m){
			printf("错误的按键，请重新输入\n");
			m = 0;
		}
	}
}

int printmenu(){
	printf("按键以继续\n");
	printf("Q: 退出系统\n");
	printf("P: 开始规划路线\n");
}

int initdis(){
	memset(dis,0,sizeof(dis));

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

}


int test(){
	for(from = 1; from <=NUM;from++){
		dijkstra();
		for(int to=1;to<=NUM;to++){
			printf("%d %d:",from,to);
			printroute(from,to);
		}
		printf("\n");
	}
}

int dijkstra(){
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=NUM;i++){
		value[i].fa = i;
		value[i].len = 0x7fffffff;
	}
	value[from].len = 0;
	int count = 1;
	int now = from, minv;
	while(count <= NUM){
		flag[now] = 1;
		for(int i=1;i<=NUM;i++){
			if(!flag[i] && i!=now && dis[now][i]){
				if(dis[now][i] + value[now].len < value[i].len){
					value[i].len = dis[now][i] + value[now].len;
					value[i].fa = now;
				}
			}
		}
		minv = 0x7fffffff;
		for(int i=1;i<=NUM;i++){
			if(!flag[i] && i!=now && value[i].len <= minv){
				now = i;
				minv = value[i].len;
			}
		}
		count++;
	}
}

int printroute(int a,int b){
	int si = 1;
	int to = b;
	do{
		stack[si++] = value[b].fa;
		b = value[b].fa;
	}while(b!=value[b].fa && si<=NUM);
	si--;
	printf("从");
	plotname(a);
	printf("到");
	plotname(to);
	printf(":\n\n");
	printf("  --推荐路线：");
	while(si != 0){
		plotname(stack[si--]);
		printf("->");
	}
	plotname(to);
	printf("\n");
	int v = value[to].len;
	printf("  --总里程约%d.%d公里\n\n",v/10,v%10);
	printf("\n");
}
