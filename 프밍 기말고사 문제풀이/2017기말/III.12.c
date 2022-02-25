#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, i, rank[4] = { 0, 0, 0, 0 };
	double  s[8], best = 0, worst = 10.0, sum = 0, score = 0, high[4] = { 0, 0, 0, 0 };
	FILE *fp1;

	if ((fp1 = fopen("C:\\Users\\YTH\\Desktop\\b\\judge.txt", "r")) != NULL)
		printf("파일 읽기 완료!\n");

	else
	{
		printf("파일 읽기 오류 \n");
		return 1;
	}

	while (!feof(fp1))
	{
		best = 0;
		worst = 10.0;
		fscanf(fp1, "%d   %lf   %lf   %lf   %lf   %lf   %lf   %lf   %lf", &num, &s[0], &s[1], &s[2], &s[3], &s[4], &s[5], &s[6], &s[7]);

		for (i = 0; i < 8; i++)
		{
			if (s[i] > best)
				best = s[i];

			if (s[i] < worst)
				worst = s[i];

		}

		for (i = 0; i < 8; i++)
		{
			sum += s[i];
		}

		score = (sum - worst - best) / 6;

		if ((score >= high[3]) && (score >= high[2]) && (score >= high[1]))
		{
			high[2] = high[1];
			rank[2] = rank[1];
			high[1] = score;
			rank[1] = num;
		}

		else if ((score >= high[3]) && (score >= high[2]) && (score < high[1]))
		{
			high[3] = high[2];
			rank[3] = rank[2];
			high[2] = score;
			rank[2] = num;
		}

		else if ((score >= high[3]) && (score < high[2]) && (score < high[1]))
		{
			high[3] = score;
			rank[3] = num;
		}

		if (num == 1)
			printf("%d번 선수의 점수는 %.2f 입니다.\n", num, score);

		sum = 0;
		score = 0;
	}

	for (i = 1; i < 4; i++)
		printf("%d등은 %d번선수 %.2f점\n", i, rank[i], high[i]);


	fclose(fp1);

	return 0;
}
