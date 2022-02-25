#include <stdio.h>

int main()
{
	int a, b, ababab, count = 0, n = 0;// 자리수 a,b, 구하고자 하는 값을 저장할 ababab, 카운트변수를 선언해줍니다.

	a = 0;//a는 두번째 자리부터 들어가므로 0이 될수있습니다.
	while (a < 10)
	{
		b = 1;//조건에 0이 아니므로 1부터 시작합니다.
		while (b < 10)
		{

			if (b == a)//a와 b는 다른 값이므로 a와 b일때 b를 1증가시키고 되돌아갑니다.
			{
				b++;//b증가
				count++;//count증가
				continue;//돌아가기
			}

			ababab = 3 * 1000000 + a * 100000 + b * 10000 + a * 1000 + b * 100 + a * 10 + b;//ababab 변수에 구하고자 하는 값을 저장합니다.
			
			if (ababab % 6 == 0)//ababab가 6의 약수일때
				n++;


			b++;//b증가
			count++;//count 증가
		}
		a++;//a증가
	}

	printf("6의 배수의 갯수 : %d\n계산 횟수: %d\n",n, count);//화면에 갯수와 계산횟수를 출력합니다.
	return 0;

}