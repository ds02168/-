#include <stdio.h>
#include <math.h>//제곱근을 사용하므로 math.h 헤더파일을 불러옵니다.

int main()
{
	int  j, n=0, Max_Value=0, Max_Term, count=0; //약수인지 확인할 j변수, 약수의 갯수를 저장할 n변수, 제일큰 약수의 갯수를 저장할 Max_Value변수, 
	//제일큰 약수를 가진 수를 저장할 Max_Term변수, 카운트할 count변수를 선언해줍니다.
	double i;//약수를 구하고자 하는 값을 저장할 i변수를 선언합니다.

	for (i = 2001005000; i <= 2001015000; i++)//2001005000부터 2001015000까지
	{
		for (j = 1; j < sqrt(i); j++)//j는 1부터 i의 제곱근-1까지
		{
			count++;//카운트 증가
			if ((int)i % j == 0)//i가 j로 나누어지면
				n += 2;//n을 2증가시킵니다.(j자신과 i를 j로 나눴을때의 값)
		}

		if (j == (int)sqrt(i)) //만약 i의 제곱근이 정수이다면
			n++;//n을 1증가시킵니다.

		printf("%d의 제곱근은 %.3f이고 약수의 갯수는 %d입니다.\n", (int)i, sqrt(i), n);
		//약수를 구하고자하는 i의 값과, i의 제곱근(소수점3자리까지)값과, 약수의 갯수를 화면에 출력합니다.
		
		if (Max_Value < n)//i의 약수갯수가 이전까지의 최대 약수갯수보다 크다면 
		{
			Max_Value = n;//Max_Value에 현재의 약수갯수
			Max_Term = (int)i; //Max_Term에 i의 값을 넣어줍니다.
		}
		n = 0;//다음 i의 약수갯수를 구해야하므로 n을 0으로 초기화 해줍니다.
	}

	printf("약수의 갯수가 제일 큰수 %d는 %d개의 약수가 있습니다.\n", Max_Term, Max_Value);//최대약수갯수를 가진 i출력
	printf("계산횟수는 %d입니다.\n", count);//계산횟수를 출력합니다.

	return 0;
}