#include <stdio.h>

int main()
{
	int B, A, S, E, L, G, M, BASE, BALL, GAMES, count = 0;//���ڸ��� ������ BASE,BALL,GAMES������ �����մϴ�.

	B = 5;//B+B�� ù�ڸ����� G�̹Ƿ� 2*B>=10�̾�� �˴ϴ�. ���� B�� 5�̻��Դϴ�.
	while (B < 10)
	{
		A = 0;
		while (A < 10)
		{
			if (A == B)//�� �ڸ����� �ٸ��ϴ�.
			{
				A++;
				continue;
			}
			E = 1;//E+L�� 1�� �ڸ����� S�̹Ƿ� E�Ǵ� L�� 0�̵ɼ� �����ϴ�.
			while (E < 10)
			{
				if (E == A || E == B)//�� �ڸ����� �ٸ��ϴ�.
				{
					E++;
					continue;
				}
				L = 1;//E+L�� 1�� �ڸ����� S�̹Ƿ� E�Ǵ� L�� 0�̵ɼ� �����ϴ�.
				while (L < 10)
				{
					if (L == E || L == A || L == B)//�� �ڸ����� �ٸ��ϴ�.
					{
						L++;
						continue;
					}
					S = 0;
					while (S < 10)
					{
						if (S == L || S == A || S == B || S == E)//�� �ڸ����� �ٸ��ϴ�.
						{
							S++;
							continue;
						}
						G = 1;//G�� ù°�ڸ����� 0�� �ɼ� �����ϴ�.
						while (G < 10)
						{
							if (G == S || G == A || G == B || G == E || G == L)//�� �ڸ����� �ٸ��ϴ�.
							{
								G++;
								continue;
							}
							M = 0;
							while (M < 10)
							{
								if (M == G || M == A || M == B || M == E || M == L || M == S)//�� �ڸ����� �ٸ��ϴ�.
								{
									M++;
									continue;
								}
								BASE = B * 1000 + A * 100 + S * 10 + E;//BASE �ʱ�ȭ
								BALL = B * 1000 + A * 100 + L * 10 + L;//BALL�ʱ�ȭ
								GAMES = G * 10000 + A * 1000 + M * 100 + E * 10 + S;//GAMES�ʱ�ȭ

								if (BASE + BALL == GAMES)//BASE+BALL=GAME�϶�
								{
									printf(" %d\n+%d\n", BASE, BALL);
									printf("------\n");
									printf("%d\n\n", GAMES);//ȭ�鿡 ����մϴ�.
								}

								M++;//M����
								count++;//ī��Ʈ ����
							}
							G++;//G����
						}
						S++;//S����
					}
					L++;//L����

				}
				E++;//E����
			}
			A++;//A����
		}
		B++;//B����
	}

	printf("���Ƚ�� : %d\n", count);//ī��Ʈ�� ����մϴ�.
	return 0;

}