#include <stdio.h>
#include <math.h>//제곱근을 사용해야하므로 math.h 헤더를 부릅니다.


int Search_Divisor(double, int *, int *);//함수를 정의합니다.(구하고자 하는 값,카운트,100번째 소수값)

int main()
{
	int count = 0, a, b;//카운트 변수,소수의 갯수를 담을 a변수,100번째 소수를 담을 b변수를 선언합니다.
	long double i= 2030401020;//2030401020부터 구해야하므로 i에 2030401020를 저장합니다.

	a = Search_Divisor(i, &count, &b);//함수호출

	printf("소수의 갯수는 %d입니다.\n", a);//소수의 갯수를 출력합니다.
	printf("100번째 소수는 %d입니다. \n", b);//100번째 소수를 출력합니다.
	printf("계산 횟수 : %d\n", count);//계산횟수를 출력합니다.

	return 0;

}


int Search_Divisor(double i, int *count, int *b)//실수형 구하고자하는 값 i변수,계산횟수를 *count, 100번째 값을 담을 *b변수를 선언합니다.
{
	int j, divisor = 0, n = 0;//실수인지 확인할 j변수,약수의 갯수를 확인할 divisor변수, 소수의 갯수를 셀 n변수를 선언합니다.

	for (i = 2030401020; i <= 2030409090; i++)//2030401020부터 2030409090까지
	{

		for (j = 2; j < sqrt(i); j++)//소수를 구하므로 1을 제외한 약수를 구합니다.
		{
			(*count)++;//계산횟수 1증가시킵니다.( 괄호를 쳐서 주소값이 1증가하는걸 방지)

			if ((int)i % j == 0)//약수이면
				divisor += 2;//약수개수 2증가
		}

		if ((int)sqrt(i) == j)//제곱근이 정수이면
			divisor++;//약수갯수 1증가

		if (divisor == 0)//약수가 없을시
		{
			n++;//소수갯수 증가
			if (n == 100)//100번째 소수일시
				*b = (int)i;//포인터를 써서 main함수에있는 b변수에 100번째 소수를 저장합니다.

			printf("%d 번째 소수는 %d입니다.   \n",n, (int)i);//소수들을 출력합니다.

		}
		divisor = 0;//다음 수의 약수갯수를 구하기 위해 약수변수를 초기화합니다.
	}

	return n;

}