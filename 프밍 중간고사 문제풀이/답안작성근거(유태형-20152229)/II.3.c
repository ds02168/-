#include <stdio.h>

int main()
{
	int a, b, c, d, abcd, i, j, x, y, count1 = 0, count2 = 0; //각자리수를 저장할 a,b,c,d변수, 값을 저장할 abcd변수, 최소 공배수, 값을 구하는데 계산횟수를 저장할 count1,count2변수를 선언합니다.
	a = 4, d = 5, x = 5, y = 7; //1000의 자리는 4, 1의 자리는 5이므로 a와 d변수엔 각각 4,5 를 저장하고 5와 7의 최소공배수를 구해야하므로 x는 5 y는 7의 값을 저장합니다.
	
	j = (x > y) ? x : y;//x가 y보다크면 x의값을 아니면 y의 값을 j변수에 입력합니다.

	for (i = j;; i++)//i=j부터 1씩 증가하는 무한반복 for문입니다.
	{
		if ((i%x == 0) && (i%y == 0))//i를 x로 나누어떨어지고 y로도 나누어떨어진다면
			break;//반복문을 종료합니다.
		count1++;//카운트를 1씩 증가시킵니다.
	}

	printf("5와 7의 최소공배수 :%d \n최소 공배수를 구하는 계산 횟수:%d\n\n\n", i ,count1);//최소공배수와 계산횟수를 출력합니다.

	b = 0;//b를 초기화 합니다.
	while (b < 10)
	{
		c = 0;
		while (c < 10)
		{
			abcd = a * 1000 + b * 100 + c * 10 + d; //abcd변수에 값을 입력합니다.

			if (abcd%i== 0)//abcd값이 i(35)로 나누어떨어진다면
				printf("구하고자 하는 값 :%d\n", abcd);//화면에 출력합니다.
			c++;
			count2++;
		}
		b++;
	}

	printf("계산 횟수 :%d\n\n\n총 계산 횟수: %d \n", count2,count1+count2);//값을 구하는 계산횟수와 전부 걸린 횟수 를 화면에 출력합니다.
	return 0;

}