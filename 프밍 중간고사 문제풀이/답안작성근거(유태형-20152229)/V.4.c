#include <stdio.h>
#include <math.h>//제곱근 함수를 사용하므로 math.h헤더를 포함합니다.

int main()
{
	int j, count = 0;//약수인지 확인하는 j변수, 카운트할 count함수를 선언합니다.
	double i = 1231231000;//약수를 구하고자하는 값을 i에 저장합니다.
	long long int sum = 0;//약수의 합을 저장하는 sum변수를 선언합니다.(int 자료형 사용시 오버플로우 발생)


	for (j = 1; j < sqrt(i); j++)//j는 i의 제곱근까지
	{
		if ((int)i%j == 0)//만약 j가 i의 변수라면
		{
			sum = sum + j + ((int)i / j);//sum 변수에 j와 i를 j로 나눈값을 각각 더해줍니다.
			printf("약수 %d   %d\n", j, (int)i / j);//약수들을 출력합니다.
		}

		count++;//카운트 1증가
	}
	if (j == (int)sqrt(i))//만약 i의 제곱근이 정수이면
		sum += j;//sum에 제곱근을 더해줍니다.(약수)
	sum -= (int)i;//자기자신을 합에서 제외시켜 줍니다.
	printf("제곱근의 수는 %.3f입니다.\n", sqrt(i));//제곱근 출력

	printf("약수의 총합은 %lld(자기자신 제외)입니다.\n", sum);//총합을 출력합니다.

	printf("계산횟수 : %d\n", count);//횟수출력
	return 0;

}