#include <stdio.h>

int main()
{
	int B, A, S, E, L, G, M, BASE, BALL, GAMES, count = 0;//각자리수 변수와 BASE,BALL,GAMES변수를 선언합니다.

	B = 5;//B+B의 첫자리수가 G이므로 2*B>=10이어야 됩니다. 따라서 B는 5이상입니다.
	while (B < 10)
	{
		A = 0;
		while (A < 10)
		{
			if (A == B)//각 자리수는 다릅니다.
			{
				A++;
				continue;
			}
			E = 1;//E+L의 1의 자리수가 S이므로 E또는 L은 0이될수 없습니다.
			while (E < 10)
			{
				if (E == A || E == B)//각 자리수는 다릅니다.
				{
					E++;
					continue;
				}
				L = 1;//E+L의 1의 자리수가 S이므로 E또는 L은 0이될수 없습니다.
				while (L < 10)
				{
					if (L == E || L == A || L == B)//각 자리수는 다릅니다.
					{
						L++;
						continue;
					}
					S = 0;
					while (S < 10)
					{
						if (S == L || S == A || S == B || S == E)//각 자리수는 다릅니다.
						{
							S++;
							continue;
						}
						G = 1;//G는 첫째자리수로 0이 될수 없습니다.
						while (G < 10)
						{
							if (G == S || G == A || G == B || G == E || G == L)//각 자리수는 다릅니다.
							{
								G++;
								continue;
							}
							M = 0;
							while (M < 10)
							{
								if (M == G || M == A || M == B || M == E || M == L || M == S)//각 자리수는 다릅니다.
								{
									M++;
									continue;
								}
								BASE = B * 1000 + A * 100 + S * 10 + E;//BASE 초기화
								BALL = B * 1000 + A * 100 + L * 10 + L;//BALL초기화
								GAMES = G * 10000 + A * 1000 + M * 100 + E * 10 + S;//GAMES초기화

								if (BASE + BALL == GAMES)//BASE+BALL=GAME일때
								{
									printf(" %d\n+%d\n", BASE, BALL);
									printf("------\n");
									printf("%d\n\n", GAMES);//화면에 출력합니다.
								}

								M++;//M증가
								count++;//카운트 증가
							}
							G++;//G증가
						}
						S++;//S증가
					}
					L++;//L증가

				}
				E++;//E증가
			}
			A++;//A증가
		}
		B++;//B증가
	}

	printf("계산횟수 : %d\n", count);//카운트를 출력합니다.
	return 0;

}