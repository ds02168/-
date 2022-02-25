#include <stdio.h>
#include <math.h>//제곱근을 써야하므로 math.h 헤더파일을 불러옵니다.



int main()
{
	int  n = 0, divisor1 = 0, divisor2 = 0 ;//서로소의 갯수를 셀 n변수, 두수의 약수의 갯수를 셀 divisor1,divisor2를 각각 선언합니다.
	long int count = 0, j,a,b;//계산횟수를 셀 count변수,약수인지 확인하는 j변수, 소수를 저장할 a,b변수를 선언합니다.
	long double i,k;//소수인지 구하고자 하는 값을 각각 i,k변수에 저장합니다.

	for (i = 1020304050; i <= 1020305050; i++)//1020304050   ~    1020305050까지 
	{

		for (j = 2; j < sqrt(i); j++)//소수인지 구하므로 2부터 제곱근 까지
		{
			if ((int)i%j == 0)//약수이면
				divisor1 += 2;//j와 i를 j로 나눈값 2개씩 더합니다.

			count++;//계산횟수 1증가
		}
		if ((int)sqrt(i) == j)//제곱근이 정수이면
			divisor1++;//약수 1증가

		if (divisor1 == 0)//소수이면
		{
			a = (int)i;//소수값을 a에 저장합니다.

			for (k = 1020304050; k <= 1020305050; k++)// 두번째 소수를 구합니다.
			{
				for (j = 2; j < sqrt(k); j++)//소수인지 구하므로 2부터 제곱근 까지
				{
					if ((int)k%j == 0)//약수이면
						divisor2 += 2;//j와 i를 j로 나눈값 2개씩 더합니다.
					count++;//계산횟수 1증가
				}
				if ((int)sqrt(k) == j)//제곱근이 정수이면
					divisor2 ++;//약수 1증가

				if (divisor2 == 0)//소수이면
				{
					b = (int)k;//소수값을 b에 저장합니다.

					if (b != a)//두 소숫값 a와 b가 같은지 비교합니다.
					{//아닐시
						printf("%ld와 %ld는 서로소 입니다.\n", (int)i, (int)k);//두 소수값을 출력합니다.
						n++;//서로소 1증가
					}
				}

				divisor2 = 0;//약수 초기화
			}
		}

		divisor1 = 0;//약수 초기화
	}

	printf("\n\n중복 제외 서로소의 갯수 : %d, 계산횟수 : %ld\n", (n/2), count);//(A,B),(B,A)를 하나로 처리해야하므로 2로 나눕니다, 계산횟수를 출력합니다.
	return 0;
}