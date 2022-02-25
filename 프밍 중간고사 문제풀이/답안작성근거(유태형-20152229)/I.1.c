#include <stdio.h>

int main()
{
	double A[2] = { 169.6, 70.9 }, B[2] = { 156.0, 57.0 }; //A와B 의 몸무게와 키,를 배열을 선언하여 초기화해줍니다. 여기서 0번째 인덱스는 키(cm) 1번째 인덱스는 몸무게(kg)입니다.
	double ABMI, BBMI;// A와B의 BMI값을 저장할 변수를 선언합니다.

	ABMI = A[1] / (A[0] * A[0]) * 10000;
	BBMI = B[1] / (B[0] * B[0]) * 10000;//A와B의 각각 BMI(몸무게(kg)/키(cm)^2*10000 를 계산하여 ABMI,BBMI 변수에 입력합니다.

	printf("A의 키: %.1fcm       A의 몸무게: %.1fkg\n", A[0], A[1]);
	printf("B의 키: %.1fcm       B의 몸무게: %.1fkg\n", B[0], B[1]);//A와 B의 키와 몸무게를 화면에 출력합니다.
	printf("A의 BMI %.1f,         B의 BMI %.1f\n", ABMI, BBMI);//A와 B의 계산한 BMI값을 출력합니다.

	return 0;//0으로 main함수를 반환합니다.
}