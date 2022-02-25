#include <stdio.h>
#include <stdlib.h>

int gregorian(int, int, int);

int dates[13][32] = { 0, };
char week[][4] = { "일","월","화","수","목","금","토" };
int weekdates[7] = { 0, };

int main()
{
	int y, m, d, g, i, j;
	FILE *fp;
	int kb = 0, kg = 0, fb = 0, fg = 0;
	int milboy = 0, oldman = 0;
	int newest = 0, oldest = 999999;
	int birth;
	int ny, nm, nd, oy, om, od;
	int many_m = 0, many_d = 0;
	int many_w = 0;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\b\\ssn.txt", "r")) != NULL)
		printf("파일 읽기 완료!!!\n");
	else
		printf("파일 읽기 실패 !!!\n");

	while (!feof(fp))
	{
		fscanf(fp, "%2d%2d%2d-%d", &y, &m, &d, &g);
		birth = y * 10000 + m * 100 + d;

		dates[m][d]++;
		weekdates[gregorian(y, m, d)]++;

		if (g == 1 || g == 3)
			kb++;
		else if (g == 2 || g == 4)
			kg++;
		else if (g == 5 || g == 7)
			fb++;
		else if (g == 6 || g == 8)
			fg++;

		if (g == 3)
			milboy++;

		if ((g == 1 || g == 2) && (y < 50 || y == 50 && m < 6 || y == 50 && m == 6 && d < 25))
			oldman++;

		if (g == 3 || g == 4 || g == 7 || g == 8)
		{
			if (newest < birth)
				newest = birth;
		}

		if (g == 1 || g == 2 || g == 5 || g == 6)
		{
			if (oldest > birth)
				oldest = birth;

		}


	}
	ny = newest / 10000;
	nm = (newest / 100) % 100;
	nd = newest % 100;

	oy = oldest / 10000;
	om = (oldest / 100) % 100;
	od = oldest % 100;

	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (dates[many_m][many_d] < dates[i][j])
			{
				many_m = i;
				many_d = j;
			}
		}
	}

	for (i = 0; i < 7; i++)
	{
		if (weekdates[many_w] < weekdates[i])
			many_w = i;
	}

	printf("한국출신 남자: %d, 여자 :%d, 외국출신 남자: %d, 여자 :%d \n", kb, kg, fb, fg);
	printf("2000년 1월 1일 이후 태어난 한국인 남자아이들의 수: %d\n", milboy);
	printf("1950년 6월 25일 이전에 태어나신 어르신들의 수: %d\n", oldman);
	printf("가장 나이가 어린 아이의 생년월일:%d, %s요일\n최고령자의 생일 사이의 날 수는 몇일:%d, %s요일\n", (newest + 20000000), week[gregorian(ny, nm, nd)], (oldest + 19000000), 
		week[gregorian(oy, om, od)]);
	printf("생일(년도는 관계 없음)이 같은 날이 가장 많은 날은 몇월 몇일이고 몇 명이 생일이 같은가?: %d월 %d일, %d명\n", many_m, many_d, dates[many_m][many_d]);
	printf("데이터에 있는 사람들은 무슨 요일에 가장 많이 태어났고, 몇 명인가?: %s요일, %d명\n", week[many_w], weekdates[many_w]);


	fclose(fp);
	return 0;
}

int gregorian(int ny, int nm, int nd)
{
	int a, c, weekday;
	a = ny;
	c = nm;

	if (nm == 1 || nm == 2)
	{
		c += 12;
		a -= 1;
	}

	weekday = (21 * (a / 100)) / 4 + (5 * (a % 100)) / 4 + (26 * (c + 1)) / 10 + nd - 1;

	return weekday % 7;
}