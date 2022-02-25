#include <stdio.h>

int main()
{
	int a, b, c, d, abcd, dcba, count = 0;//각 자리수 변수 a,b,c,d와 원하는값을 저장하는 a,b,c,d변수 역순으로 값을가지는 dcba변수, 카운트할 count변수를 선언합니다.
	
	a = 0;//a는 번호판과 전화번호 이므로 0이 될수 있습니다.
	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{	
			if (b == a)//각 자리수가 전부 다르므로 b가 a와 같을땐 다시 돌아갑니다.
			{
				b++;//b를 1증가시킵니다.
				count++;//카운트 증가
				continue;//다시 돌아가기
			}
			c = 0;
			while (c < 10)
			{
				if (c >= a || c == b)//첫째자리수a 가 셋쩨자리수 c보다 크고 각 자리수가 모두 다른값이므로 c는 a보다 작아야하고 b랑 같은값이어선 안됩니다.
				{
					c++;//c를 1증가시킵니다.
					count++;//카운트증가
					continue;//다시 돌아가기
				}
				d = 0;
				while (d < 10)
				{
					if (d == c || d == b || d == a)//각 자리수가 모두 다르므로 d가 a,b,c와 같아선 안됩니다.
					{
						d++;//d증가
						count++;//카운트 증가
						continue;//다시돌아가기
					}
					abcd = a * 1000 + b * 100 + c * 10 + d;//구하고자하는값
					dcba = d * 1000 + c * 100 + b * 10 + a;//역순
					if (abcd + dcba == 10769)//구하고자 하는값과 역순값의 합이 10769일때
						printf("조건에 만족하는 값 : %d\n", abcd);//화면에 출력합니다.


					d++;//d증가
					count++;//카운트 증가

				}
				c++;//c증가
			}
			b++;//b증가
		}
		a++;//a증가
	}


	printf("계산횟수 :%d\n", count);//카운트 횟수를 출력합니다.
	return 0;
}