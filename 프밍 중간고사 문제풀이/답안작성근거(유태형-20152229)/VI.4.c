#include<stdio.h>


int main()
{
	int T, W, E, N, Y, S, V, H, I, R, TWENTY, THIRTY, SEVENTY, count = 0, num = 0;
	//�� �ڸ� ���� T,W,E,N,Y,S,V,H,I,R ������ ���� �����ϴ� TWENTY,THIRTY,SEVENTY������ ���Ƚ���� �����ϴ� count ����,���� ������ �����ϴ� num ������ �����մϴ�.
	Y = 0;//Y�� 0����
	while (Y < 10)//10����
	{
		if ((Y*3)%10 != Y)//���� Y*3�� ���� 1���ڸ����� Y�� �ƴϸ�
		{
			Y++;//Y�� 1������Ű��
			continue;//ó������ ���ư��ϴ�.
		}//�� 1���ڸ��� Y�̹Ƿ� Y�� 0�Ǵ� 5�Դϴ�.

		T = 3;//T�� TWENTY�� THIRTY�� ù°�ڸ��ν� T�� 3���������� 10�� �Ѿ���ϹǷ� T�� �ּ� 3�Դϴ�.(T�� 2�϶� W�� H�� 9���� 3*T<10�Դϴ�.)
		while (T < 10)//10����
		{
			if (T == Y)//�� �ڸ����� �ٸ��ϴ�.
			{
				T++;
				continue;
			}
			N = 0;//N�� 0����
			while (N < 10)//10����
			{

				if (N == 2)//N�� 2���ƴ϶������Ƿ� N�� 2�϶�
				{
					N++;//N�� 1���� ��Ű��
					continue;//ó������ �ǵ��ư��ϴ�.
				}

				if (N == Y || N == T)//�� �ڸ����� �ٸ��ϴ�.
				{
					N++;
					continue;
				}

				R = 0;//R�� 0����
				while (R < 10)//10����
				{
					if (R == Y || R == T || R == N)//�� �ڸ����� �ٸ��ϴ�.
					{
						R++;
						continue;
					}
					E = 0;//E�� 0����
					while (E < 10)//10����
					{
						if (E == Y || E == T || E == N || E == R)//�� �ڸ����� �ٸ��ϴ�.
						{
							E++;
							continue;
						}
						W = 0;//W�� 0����
						while (W < 10)//10����
						{
							if (W == Y || W == T || W == N || W == R || W == E)//�� �ڸ����� �ٸ��ϴ�.
							{
								W++;
								continue;
							}
							H = 0;//H�� 0����
							while (H < 10)//10����
							{
								if (H == Y || H == T || H == N || H == R || H == E || H == W)//�� �ڸ����� �ٸ��ϴ�.
								{
									H++;
									continue;
								}
								I = 0;//I�� 0����
								while (I < 10)//10����
								{
									if (I == Y || I == T || I == N || I == R || I == E || I == W || I == H)//�� �ڸ����� �ٸ��ϴ�.
									{
										I++;
										continue;
									}
									V = 0;//V�� 0����
									while (V < 10)//10����
									{
										if (V == Y || V == T || V == N || V == R || V == E || V == W || V == H || V == I)//�� �ڸ����� �ٸ��ϴ�.
										{
											V++;
											continue;
										}
										S = 1;//S�� SEVENTY�� ù°�ڸ��̸� 0�� �ɼ� �����Ƿ� 1����
										while (S < 10)//10����
										{
											if (S == Y || S == T || S == N || S == R || S == E || S == W || S == H || S == I || S == V)//�� �ڸ����� �ٸ��ϴ�.
											{
												S++;
												continue;
											}

											TWENTY = T * 100000 + W * 10000 + E * 1000 + N * 100 + T * 10 + Y;
											SEVENTY = S * 1000000 + E * 100000 + V * 10000 + E * 1000 + N * 100 + T * 10 + Y;
											THIRTY = T * 100000 + H * 10000 + I * 1000 + R * 100 + T * 10 + Y;
											//�� �ڸ��� ö�ڸ� �����Ͽ� ���簪�� TWENTY,SEVENTY,THIRTY������ �����մϴ�.

											if (TWENTY + TWENTY + THIRTY == SEVENTY)//���� �´ٸ�
											{
												printf(" %d\n",TWENTY);
												printf(" %d\n",TWENTY);
												printf(" %d\n",THIRTY);
												printf("--------\n");
												printf("%d\n",SEVENTY);
												printf("\n\n\n");//ȭ�鿡 ����մϴ�.
												num++;//���� ���� ����
											}

											count++;//���Ƚ������
											S++;//S����
										}
										V++;//V����
									}
									I++;//I����
								}
								H++;//H����
							}
							W++;//W����
						}
						E++;//E����

					}
					R++;//R����

				}
				N++;//N����

			}
			T++;//T����

		}
		Y++;//Y����

	}

	printf("���� ����: %d, ���Ƚ�� : %d\n", num, count);//���� ������ ���Ƚ�� ���
	return 0;

}