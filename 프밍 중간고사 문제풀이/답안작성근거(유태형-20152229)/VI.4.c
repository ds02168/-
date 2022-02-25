#include<stdio.h>


int main()
{
	int T, W, E, N, Y, S, V, H, I, R, TWENTY, THIRTY, SEVENTY, count = 0, num = 0;
	//각 자리 숫자 T,W,E,N,Y,S,V,H,I,R 변수와 값을 저장하는 TWENTY,THIRTY,SEVENTY변수와 계산횟수를 저장하는 count 변수,값의 갯수를 저장하는 num 변수를 선언합니다.
	Y = 0;//Y는 0부터
	while (Y < 10)//10까지
	{
		if ((Y*3)%10 != Y)//만약 Y*3한 수의 1의자리수가 Y가 아니면
		{
			Y++;//Y를 1증가시키고
			continue;//처음으로 돌아갑니다.
		}//각 1의자리가 Y이므로 Y는 0또는 5입니다.

		T = 3;//T는 TWENTY와 THIRTY의 첫째자리로써 T가 3개더해지면 10이 넘어가야하므로 T는 최소 3입니다.(T가 2일때 W와 H가 9여도 3*T<10입니다.)
		while (T < 10)//10까지
		{
			if (T == Y)//각 자리수는 다릅니다.
			{
				T++;
				continue;
			}
			N = 0;//N은 0부터
			while (N < 10)//10까지
			{

				if (N == 2)//N은 2가아니라했으므로 N이 2일때
				{
					N++;//N을 1증가 시키고
					continue;//처음으로 되돌아갑니다.
				}

				if (N == Y || N == T)//각 자리수는 다릅니다.
				{
					N++;
					continue;
				}

				R = 0;//R은 0부터
				while (R < 10)//10까지
				{
					if (R == Y || R == T || R == N)//각 자리수는 다릅니다.
					{
						R++;
						continue;
					}
					E = 0;//E는 0부터
					while (E < 10)//10까지
					{
						if (E == Y || E == T || E == N || E == R)//각 자리수는 다릅니다.
						{
							E++;
							continue;
						}
						W = 0;//W는 0부터
						while (W < 10)//10까지
						{
							if (W == Y || W == T || W == N || W == R || W == E)//각 자리수는 다릅니다.
							{
								W++;
								continue;
							}
							H = 0;//H는 0부터
							while (H < 10)//10까지
							{
								if (H == Y || H == T || H == N || H == R || H == E || H == W)//각 자리수는 다릅니다.
								{
									H++;
									continue;
								}
								I = 0;//I는 0부터
								while (I < 10)//10까지
								{
									if (I == Y || I == T || I == N || I == R || I == E || I == W || I == H)//각 자리수는 다릅니다.
									{
										I++;
										continue;
									}
									V = 0;//V는 0부터
									while (V < 10)//10까지
									{
										if (V == Y || V == T || V == N || V == R || V == E || V == W || V == H || V == I)//각 자리수는 다릅니다.
										{
											V++;
											continue;
										}
										S = 1;//S는 SEVENTY의 첫째자리이며 0이 될수 없으므로 1부터
										while (S < 10)//10까지
										{
											if (S == Y || S == T || S == N || S == R || S == E || S == W || S == H || S == I || S == V)//각 자리수는 다릅니다.
											{
												S++;
												continue;
											}

											TWENTY = T * 100000 + W * 10000 + E * 1000 + N * 100 + T * 10 + Y;
											SEVENTY = S * 1000000 + E * 100000 + V * 10000 + E * 1000 + N * 100 + T * 10 + Y;
											THIRTY = T * 100000 + H * 10000 + I * 1000 + R * 100 + T * 10 + Y;
											//각 자리수 철자를 조합하여 만든값을 TWENTY,SEVENTY,THIRTY변수에 저장합니다.

											if (TWENTY + TWENTY + THIRTY == SEVENTY)//식이 맞다면
											{
												printf(" %d\n",TWENTY);
												printf(" %d\n",TWENTY);
												printf(" %d\n",THIRTY);
												printf("--------\n");
												printf("%d\n",SEVENTY);
												printf("\n\n\n");//화면에 출력합니다.
												num++;//값의 갯수 증가
											}

											count++;//계산횟수증가
											S++;//S증가
										}
										V++;//V증가
									}
									I++;//I증가
								}
								H++;//H증가
							}
							W++;//W증가
						}
						E++;//E증가

					}
					R++;//R증가

				}
				N++;//N증가

			}
			T++;//T증가

		}
		Y++;//Y증가

	}

	printf("값의 갯수: %d, 계산횟수 : %d\n", num, count);//값의 갯수와 계산횟수 출력
	return 0;

}