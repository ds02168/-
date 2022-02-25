#include <stdio.h>
#include <time.h>

int main()
{

	time_t now; //현재시각을 입력합니다.
	struct tm t;//tm 구조체 t를 선언합니다.

	now = time(NULL);
	t = *localtime(&now);
	t.tm_mday += 33000; //33000일을 더합니다.
	mktime(&t);//시간을 재계산 합니다.



	//기준:2016년 4월 21일
	if ((t.tm_mday + 21) > 31 && (t.tm_mon + 1 == 1, 3, 4, 5, 7, 8, 10, 12))//1,3,5,7,8,10,12월달에 32일 이상이면
		printf("33000일 후 날짜 :%4d.%d.%d\n", t.tm_year + 1900 - 2, t.tm_mon + 2, (t.tm_mday+21) - 31);//31일을 빼주고 1달 증가시킵니다.
	else if ((t.tm_mday + 21) > 30 && (t.tm_mon + 1 == 4, 6, 9, 11))//4,6,9,11월달에 31일 이상이면
		printf("33000일 후 날짜 :%4d.%d.%d\n", t.tm_year + 1900 - 2, t.tm_mon + 2, (t.tm_mday + 21) - 30);//30일을 빼주고 1달을 증가시킵니다.
	else if ((t.tm_mday + 21) > 28 && (t.tm_mon == 2))//2월달에 28일 이상이면
		printf("33000일 후 날짜 :%4d.%d.%d\n", t.tm_year + 1900 - 2, t.tm_mon + 2, (t.tm_mday + 21) - 28);//28일을 빼주고 1달을 증가시킵니다.
	else
	printf("33000일 후 날짜 :%4d.%d.%d\n", t.tm_year+1900-2 , t.tm_mon+1 , t.tm_mday+21);//해당사항 없을시 그대로 출력

	/*
	tm 구조체는 1900년 정각을 기준으로 시작됬으므로 1900년을 더해주어야 합니다.
	2016년 4월 21 일기준이므로
	2018년 에서 2년을 빼줍니다.

	같은 4월이므로 그대로 해줍니다.

	일수는 달마다 다르므로 위에 조건대로 해줍니다.
	
	
	*/
	return 0;
}