#define _CRT_SECURE_NO_WARNINGS
//#define TEST
//#define BUILD_TEST_FILE
#define FORMAL /*正式的代码*/
//#define DEBUG

#include <stdio.h>

#ifdef BUILD_TEST_FILE
#include <time.h>
#include <stdlib.h>
int get_rand_range(int min, int max);
int get_rand_year();
int get_rand_month();
int get_rand_day(int y,int m);
int get_rand_add_d();
#endif

//直接按yyyymmdd存标志，日期可以直接比较
//用两个mark数组存
int date_mark[5] = { 20190501 ,19890108 ,19261225 ,19120730 , 18680908 };
int chro_mark[5] = { 'R','H','S','T','M' };

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; //每月天数

int is_leap_year(int y);

int get_date(char chro, int y, int m, int d);
char get_chro_asset(int date);
int get_chro_year(int date, int chro_asset);

int add_date(int date, int add_d);
void format_print(int date);

/* 
* Author:	Fliskey
* Date:		2021/10/12 1:08
*/

int main() {
#ifdef BUILD_TEST_FILE
	freopen("debug_in.txt", "w", stdout);
	srand(time(0));
	const int TGN = 100;	//test_group_num
	for (int i = 0; i < TGN; i++) {
		int y = get_rand_year();
		int m = get_rand_month();
		int d = get_rand_day(y, m);
		int add_d = get_rand_add_d();
		int date = y * 10000 + m * 100 + d;
		format_print(date);
		printf(" %d\n", add_d);
	}
	fclose(stdout);
#endif // BUILD_TEST_FILE

#ifdef TEST	//自测
	freopen("testout.txt", "w", stdout);
	int start_date = 18680908;
	int add_d = 0;
	int now_date = start_date;
	do {
		 now_date = add_date(start_date, add_d);
		 printf("%d ", now_date);
		 format_print(now_date);
		 add_d++;
		 
	} while (now_date <= 20211012);

	fclose(stdout);
#endif // TEST

#ifdef FORMAL	//正式代码
#ifdef DEBUG	//测样例
	freopen("debug_out.txt", "w", stdout);
	freopen("debug_in.txt", "r", stdin);
#endif
	char chro;	//Chronicle纪年
	int y, m, d;	//年月日
	int add_d;	//增加天数
	while (scanf("%c%d/%d/%d %d ", &chro, &y, &m, &d, &add_d) != EOF) {
		int date = get_date(chro, y, m, d);
		date = add_date(date, add_d);
		format_print(date);
	}
#ifdef DEBUG
	fclose(stdin);
	fclose(stdout);
#endif
#endif // FORMAL

	return 0;
}

#ifdef BUILD_TEST_FILE
int get_rand_range(int min, int max) {
	return rand() % (max - min + 1) + min;
}
int get_rand_year() {
	return get_rand_range(1869, 2021);
}
int get_rand_month() {
	return get_rand_range(1, 12);
}
int get_rand_day(int y, int m) {
	int d_max = (m == 2 ? (is_leap_year(y) ? 29 : 28) : mon[m]);
	return get_rand_range(1, d_max);
}
int get_rand_add_d() {
	return get_rand_range(0, 55916);
}

#endif // BUILD_TEST_FILE

int is_leap_year(int y) {
	if (y % 100 == 0) {
		if (y % 400 == 0) {
			return 1;
		}
		return 0;
	}
	else if (y % 4 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int get_date(char chro, int y, int m, int d) {
	int date = 0;
	switch (chro) {
	case 'M':
		date += 18680000;
		break;
	case 'T':
		date += 19120000;
		break;
	case 'S':
		date += 19260000;
		break;
	case 'H':
		date += 19890000;
		break;
	case 'R':
		date += 20190000;
		break;
	}
	date += (y-1) * 10000;
	date += m * 100;
	date += d;
	return date;
}

char get_chro_asset(int date) {
	for (int chro_asset = 0; chro_asset < 5; chro_asset++) {
		if (date >= date_mark[chro_asset]) {
			return chro_asset;
		}
	}
}

int get_chro_year(int date, int chro_asset){
	int stand_year = date_mark[chro_asset] / 10000;
	int now_year = date / 10000;
	return now_year - stand_year + 1;
}

int add_date(int date, int add_d) {
	//date需要yyyymmdd格式
	int y = date / 10000;
	int m = date / 100 % 100;
	int d = date % 100;
	int ret_date = 0;	//按yyyymmdd格式的返回值

	mon[2] = (is_leap_year(y) ? 29 : 28);

	while (add_d != 0) {
		if (d + add_d > mon[m]) {
			add_d -= mon[m] - d + 1; //跳到下个月一号
			d = 1;
			m++;
			if (m > 12) {
				m = 1;
				y++;
				mon[2] = (is_leap_year(y) ? 29 : 28);
			}
		}
		else {
			d += add_d;
			add_d = 0;
		}
	}
	ret_date = y * 10000 + m * 100 + d;
	return ret_date;
}

void format_print(int date) {
	int y = date / 10000;
	int m = date / 100 % 100;
	int d = date % 100;
	char chro_asset = get_chro_asset(date);
	char chro = chro_mark[chro_asset];
	int chro_year = get_chro_year(date, chro_asset);

	printf("%c%d/%d/%d", chro, chro_year, m, d);
#ifndef BUILD_TEST_FILE
	printf("\n");
#endif // !BUILD_TEST_FILE

}
