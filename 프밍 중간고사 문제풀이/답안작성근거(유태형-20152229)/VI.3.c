#include <stdio.h>


int main()
{
	int A,B,C,D,CB,CC,AAA,ADDA, count = 0;//�� �ڸ��� A,B,C,D����, ���� ���� CC,CB,AAA,ADDA����,���Ƚ���� �� ī��Ʈ ������ �����մϴ�.
	
	A = 1;//A�� AAA,ADDA���� ù°�ڸ����� ���Ƿ� 0�̵ɼ� �����ϴ�.
	while (A < 5)//AAA+AAA0=ADDA���� AA=D(���ڸ�)�̹Ƿ� 2A<10�Դϴ�.���� 5���� Ŭ�� �����ϴ�.
	{
		C = 3;//CB*C=AAA���� C�� 2�϶� B�� ����� ������  3�ڸ��� AAA�� ���� ���ϹǷ� C�� �ּ� 3�Դϴ�.
		while (C < 10)
		{
			if (C == A)//�� �ڸ����� �ٸ��ϴ�.
			{
				C++;
				continue;
			}
			B = 2;//C*B%10�� A�̹Ƿ� B�� 1�̵ɼ������ϴ�(1�϶� A�� �ƴ϶� C�̹Ƿ�)
				while (B < 10)
				{
					if (B == A || B == C)//�� �ڸ����� �ٸ��ϴ�.
					{
						B++;
						continue;
					}

					D = 2;//A+A=D�̹Ƿ� D�� 1�� �ɼ������ϴ�.
					while (D < 10)
					{
						if (D == B || D == A || D == C)//�� �ڸ����� �ٸ��ϴ�.
						{
							D++;
							continue;
						}

						CB = C * 10 + B;//CB����
						CC = C * 10 + C;//CC����
						AAA = A * 100 + A * 10 + A;//AAA����
						ADDA = A * 1000 + D * 100 + D * 10 + A;//ADDA����

						if ((CB*C == AAA) && (AAA * 10 + AAA == ADDA))//CB*C�� AAA�� AAA0+AAA=ADDA�϶�
						{
							printf("   %d\n", CB);
							printf(" X %d\n", CC);
							printf("------\n");
							printf("  %d\n", AAA);
							printf(" %d\n", AAA);
							printf("------\n");
							printf(" %d\n\n", ADDA);//ȭ�� ���

							printf("A:%d, B:%d, C:%d, D:%d\n", A, B, C, D);//A,B,C,D���� ����մϴ�.
						}
						

						D++;//D�� ����
						count++;//ī��Ʈ ����
					}
					B++;//B����
				}
				C++;//C����
		}
		A++;//A����
	}
	printf("���Ƚ�� :%d\n",count);//���Ƚ�� ���
	return 0;
}