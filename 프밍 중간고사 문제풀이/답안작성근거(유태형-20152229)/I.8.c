#include <stdio.h>

int main()
{
	int n = 1, sign = 1; //n=1은 항의 순번을 나타내기위해,sign은 부호를 바꿔주기위해 각각 1로 초기화하여 선언합니다.
	double sum = 0;//합은 실수형 0으로 선언합니다.

	while (sum < 0.685)//합이 0.685보다 커지면 반복순환을 멈춥니다.
	{
		sum += sign * (double)n / (double)(n + 1);//합=이전 합+부호*n/(n+1)입니다.
		n++;//n을 1씩 증가시켜줍니다.
		sign = -sign;//부호를 바꿔줍니다.
	}
	printf("합이 0.685보다 커지는 %d 번째항은 %f입니다.\n", n, sum);//화면에 합이 0.685보다 커질때 n과 sum을 출력합니다.
	return 0;
}

