#include <stdio.h>
#include <stdlib.h>
//헤더파일을 불러옵니다.

int main()
{
	int num, i, rank[4] = { 0, 0, 0, 0 };//선수번호를 저장하는 num변수 심판을 세는 i변수, 등수를 저장하는 rank배열을 선언합니다.
	double  s[8], best = 0, worst = 10.0, sum = 0, score = 0, high[4] = { 0, 0, 0, 0 };//점수를 저장하는 s배열, 최고점수 best, 최저점수 worst
	//8명의 심판의 점수합 sum변수, 최종점수 score변수, 가장높은 점수를 저장하는 high배열을 선언합니다.
	FILE *fp1;

	if ((fp1 = fopen("C:\\Users\\YTH\\Desktop\\a\\judge.txt", "r")) != NULL)//파일 불러오기에 성공하면
		printf("파일 읽기 완료!\n");//화면 출력

	else//실패하면
	{
		printf("파일 읽기 오류 \n");
		exit(1);
	}//화면출력후 종료합니다.

	while (!feof(fp1)) //파일이 유효할 동안
	{
		best = 0;//최고점수는 항상 0점으로 초기화 해줍니다.
		worst = 10.0;//최저점수는 항상 10점(만점)으로 초기화 해줍니다.
		fscanf(fp1, "%d   %lf   %lf   %lf   %lf   %lf   %lf   %lf   %lf", &num, &s[0], &s[1], &s[2], &s[3], &s[4], &s[5], &s[6], &s[7]);
		//파일로부터 한줄씩 선수번호와 8명의 심판의 점수를 읽어들입니다.
		for (i = 0; i < 8; i++) //8명의 심판원에서
		{
			if (s[i] > best)//이전 점수들 보다 높으면
				best = s[i];//best변수에 점수를 저장합니다.

			if (s[i] < worst)//이전 점수들 보다 낮으면
				worst = s[i];//worst변수에 점수를 저장합니다.

		}

		for (i = 0; i < 8; i++)//심판 8명의 
		{
			sum += s[i];//점수들을 sum변수에 더해줍니다.
		}

		score = (sum - worst - best) / 6;
		//8명의 총점수에 최저점수와 최고점수를 빼고 6으로 나누면 나머지 6명의 심판의 평균점수가 됩니다.

		if ((score >= high[3]) && (score >= high[2]) && (score >= high[1]))//기존의 1,2,,3등보다 점수가 높거나 같으면
		{
			high[2] = high[1];
			rank[2] = rank[1];//1등은 2등으로
			rank[3] = rank[2];
			rank[3] = rank[2];//2등은 3등으로
			high[1] = score;
			rank[1] = num;//1등에 점수와 선수번호를 저장합니다.
		}

		else if ((score >= high[3]) && (score >= high[2]) && (score < high[1]))//2등,3등보다 점수가 높거나 같고 1등보다 점수가 낮으면
		{
			high[3] = high[2];
			rank[3] = rank[2];//2등을 3등으로
			high[2] = score;
			rank[2] = num;//2등에 점수와 선수번호를 저장합니다.
		}

		else if ((score >= high[3]) && (score < high[2]) && (score < high[1]))//3등보다 점수가 높거나 같고 1,2등등보다 점수가 낮으면
		{
			high[3] = score;
			rank[3] = num;//3등에 점수와 선수번호를 저장합니다.
		}


		sum = 0;
		score = 0;//8개의 점수 합과 최종점수를 0으로 초기화해줍니다(다음 선수의 점수도 구해야 하기 때문)
	}

	for (i = 1; i < 4; i++)
		printf("%d등은 %d번선수 %.3f점\n", i, rank[i], high[i]); //등수별로 선수번호와 점수를 출력합니다.


	fclose(fp1);

	return 0;
}
