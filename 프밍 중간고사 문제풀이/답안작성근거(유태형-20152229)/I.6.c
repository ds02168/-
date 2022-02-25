#include <stdio.h>

int main()
{
	int year, n=0, count = 0;//년도를 저장할 year변수와 횟수를 저장할 n변수, 카운트 변수를 선언합니다.

	for (year = 1999; year <= 2116; year++)//년도가 1999년부터 2116년까지 반복합니다.
	{
		if ((year % 4 == 0 && year != 0) || (year % 400 == 0)) //윤년이면
			n++; //윤년횟수를 증가합니다.
		
		count++;//카운트 증가
	}
	printf("1999년부터 2116년까지의 윤년은 %d번 있습니다.\n계산횟수 : %d\n", n,count);//윤년횟수와 계산횟수를 화면에 출력합니다.
	return 0;
}