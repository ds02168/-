#include <stdio.h>
#include <stdlib.h>

int gregorian(int, int, int);

int dates[13][32] = { 0, };
char week[][4] = { "��","��","ȭ","��","��","��","��" };
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
		printf("���� �б� �Ϸ�!!!\n");
	else
		printf("���� �б� ���� !!!\n");

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

	printf("�ѱ���� ����: %d, ���� :%d, �ܱ���� ����: %d, ���� :%d \n", kb, kg, fb, fg);
	printf("2000�� 1�� 1�� ���� �¾ �ѱ��� ���ھ��̵��� ��: %d\n", milboy);
	printf("1950�� 6�� 25�� ������ �¾�� ��ŵ��� ��: %d\n", oldman);
	printf("���� ���̰� � ������ �������:%d, %s����\n�ְ������ ���� ������ �� ���� ����:%d, %s����\n", (newest + 20000000), week[gregorian(ny, nm, nd)], (oldest + 19000000), 
		week[gregorian(oy, om, od)]);
	printf("����(�⵵�� ���� ����)�� ���� ���� ���� ���� ���� ��� �����̰� �� ���� ������ ������?: %d�� %d��, %d��\n", many_m, many_d, dates[many_m][many_d]);
	printf("�����Ϳ� �ִ� ������� ���� ���Ͽ� ���� ���� �¾��, �� ���ΰ�?: %s����, %d��\n", week[many_w], weekdates[many_w]);


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