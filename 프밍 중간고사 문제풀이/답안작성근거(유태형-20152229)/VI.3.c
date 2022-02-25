#include <stdio.h>


int main()
{
	int A,B,C,D,CB,CC,AAA,ADDA, count = 0;//각 자리수 A,B,C,D변수, 값을 비교할 CC,CB,AAA,ADDA변수,계산횟수를 셀 카운트 변수를 선언합니다.
	
	A = 1;//A는 AAA,ADDA에서 첫째자리에도 들어가므로 0이될수 없습니다.
	while (A < 5)//AAA+AAA0=ADDA에서 AA=D(한자리)이므로 2A<10입니다.따라서 5보다 클수 없습니다.
	{
		C = 3;//CB*C=AAA에서 C가 2일때 B가 어떤수가 들어가든지  3자리수 AAA가 되지 못하므로 C는 최소 3입니다.
		while (C < 10)
		{
			if (C == A)//각 자리수는 다릅니다.
			{
				C++;
				continue;
			}
			B = 2;//C*B%10이 A이므로 B는 1이될수없습니다(1일때 A가 아니라 C이므로)
				while (B < 10)
				{
					if (B == A || B == C)//각 자리수는 다릅니다.
					{
						B++;
						continue;
					}

					D = 2;//A+A=D이므로 D는 1이 될수없습니다.
					while (D < 10)
					{
						if (D == B || D == A || D == C)//각 자리수는 다릅니다.
						{
							D++;
							continue;
						}

						CB = C * 10 + B;//CB정의
						CC = C * 10 + C;//CC정의
						AAA = A * 100 + A * 10 + A;//AAA정의
						ADDA = A * 1000 + D * 100 + D * 10 + A;//ADDA정의

						if ((CB*C == AAA) && (AAA * 10 + AAA == ADDA))//CB*C가 AAA고 AAA0+AAA=ADDA일때
						{
							printf("   %d\n", CB);
							printf(" X %d\n", CC);
							printf("------\n");
							printf("  %d\n", AAA);
							printf(" %d\n", AAA);
							printf("------\n");
							printf(" %d\n\n", ADDA);//화면 출력

							printf("A:%d, B:%d, C:%d, D:%d\n", A, B, C, D);//A,B,C,D값을 출력합니다.
						}
						

						D++;//D값 증가
						count++;//카운트 증가
					}
					B++;//B증가
				}
				C++;//C증가
		}
		A++;//A증가
	}
	printf("계산횟수 :%d\n",count);//계산횟수 출력
	return 0;
}