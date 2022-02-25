#include <stdio.h>

int main()
{
	int N, O, R,OR,NOR,count=0;//각 자리수 N,O,R과 임의 수 OR,NOR변수,카운트 변수를 선언합니다.

	N = 1;//N은 첫자리이므로 0이 될수없습니다.
	while (N < 10)
	{
		O = 1;//O도 OR에서 첫째자리수이므로 0이 될수없습니다.
		while (O < 10)
		{
			if (O == N)
			{
				O++;
				continue;
			}
			R = 0;//R은 끝자리로써 0이 될수있습니다.
			while (R < 10)
			{

				if (R == N || R == O || R == 2 || R == 3 || R == 4 || R == 7 || R == 8 || R == 9)//R이 N,O랑 같은 값일수 없고 2,3,4,7,8,9일때 RXR에서 끝자리가 R이 될수없습니다.
				{
					R++;//R증가
					continue;//계속합니다.
				}

				OR = O * 10 + R;//O는 10의자리 R은 1의자리입니다.
				NOR = N * 100 + O * 10 + R;//N은 100의 자리 O는 10의 자리 R은 1의 자리입니다.
				if (OR*OR == NOR)//OR곱하기 OR이 NOR일때
				{
					printf("%d X %d = %d\n", OR, OR, NOR);//화면에 출력합니다.
					printf("\n\nN : %d, O : %d, R : %d\n", N, O, R);//N,O,R값을 출력합니다.
				}

				count++;//계산횟수 증가
				R++;//R증가
			}

			O++;//O증가
		}

		N++;//N증가
	}

	printf("계산 횟수 : %d\n", count);//계산횟수 증가
	return 0;

}

/*  25X25=625 답이 나왔습니다.*/