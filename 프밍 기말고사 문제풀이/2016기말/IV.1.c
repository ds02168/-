#include <stdio.h>
#include <stdlib.h>
//헤더파일을 불러옵니다.

int main()
{
	int num, i;//선수번호를 저장하는 num변수 심판을 셀 i변수를 선언합니다.
	double  s[8], best = 0, worst = 10.0, sum = 0, score = 0;//8명의 심판의 점수를 저장할 s변수, 가장 높은 점수를 저장하는 best변수 가장 낮은 점수를 저장하는 worst변수
	//8명의 총점수를 저장하는 sum변수, 종합하여 평균 점수를 저장하는 score점수를 선언합니다.
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

		if (num == 1)//선수번호가 1번이면
			printf("%d번 선수의 점수는 %.3f 입니다.\n", num, score); //번호와 점수를 화면에 출력합니다.

		sum = 0;
		score = 0;//8개의 점수 합과 최종점수를 0으로 초기화해줍니다(다음 선수의 점수도 구해야 하기 때문)
	}

	fclose(fp1);

	return 0;
}
