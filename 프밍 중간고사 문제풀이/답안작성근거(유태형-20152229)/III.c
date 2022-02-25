#include <stdio.h>

double calculation(int);//함수 정의

int main()
{
	int electric, total; //전기량,청구요금을 각각 electric,total 변수로 선언합니다.
	double a, b, pay;//부가가치세,전력기반요금을 각각 a와 b로 double형 변수로 선언합니다.

	printf("이번달 사용한 전기량을 입력하시오:");
	scanf("%d", &electric);//이번달 전기 사용량을 입력받습니다.

	pay = (int)calculation(electric);//함수를 호출하여 전기사용량에 따른 전기요금(원 미만 절삭을 위해 int형으로 변환)을 구합니다.
	a = pay / 10 + 0.5;//부가가치세=전기요금에 10프로이고 4사5입을 위해 0.5를 더해줍니다.
	b = (pay * 3.7 / 100);//전력기반요금=전기요금의 3.7퍼센트입니다.
	total = (int)pay + (int)a + (int)b-((int)b)%10;//청구요금=전기요금+부가가치세+전력기반요금입니다.
	//전력기반 요금 10원미만 절삭을 위해 전력기반요금-(전력기반요금을 10으로 나눈 나머지)
	total = total - total % 10;//청구요금을 10원미만으로 절삭합니다.(청구요금-청구요금을 10으로 나눈 나머지)

	printf("사용한 전기량 : %dKwh\n전기요금 : %d원\n부가가치세 : %d원\n전력기반요금 : %d원\n청구금액=%d원\n", electric, (int)pay, (int)a, (int)b, total);
	//전기 사용량 전기요금, 부가가치세, 전력기반요금, 청구금액의 영수증을 출력합니다.
	return 0;
}


double calculation(int electric)
{
	double pay;//함수에서 쓸 전기요금 변수를 선언합니다.(지역변수)

	if (electric <= 100)//100kwh일때
		pay = 410 + 61.20*electric; //전기요금
	else if (electric <= 200) // 101kwh~200kwh일때
		pay = 930 + 61.20 * 100 + 127.10*(electric - 100); //전기요금
	else if (electric <= 300)//201kwh~300kwh일때
		pay = 1610 + 61.20 * 100 + 127.10 * 100 + 188.60*(electric - 200);//전기요금
	else if (electric <= 400)//301kwh~400kwh일때
		pay = 3830 + 61.20 * 100 + 127.10 * 100 + 188.60 * 100 + 278.60*(electric - 300);//전기요금
	else if (electric <= 500)//401kwh~500kwh 일때
		pay = 7190 + 61.20 * 100 + 127.10 * 100 + 188.60 * 100 + 278.60 * 100 + 411.70*(electric - 400);//전기요금
	else if (electric <= 800)//501kwh~800kwh 일때
		pay = 13990 + 61.20 * 100 + 127.10 * 100 + 188.60 * 100 + 278.60 * 100 + 411.70 * 100 + 726.20*(electric - 500);//전기요금
	else//801kwh보다 더 많이 썻을때
		pay = 99990 + 61.20 * 100 + 127.10 * 100 + 188.60 * 100 + 278.60 * 100 + 411.70 * 100 + 726.20 * 100 + 11990.20*(electric - 800);//전기요금

	return pay;//전기요금 값을 반환 합니다.

}

