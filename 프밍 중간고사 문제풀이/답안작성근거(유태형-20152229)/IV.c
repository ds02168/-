/* 원본 소스입니다.
#include <stdio.h>
int main()
{
int number, sum;
printf(" 숫자를 입력하시오: ");
scanf("%d", &number);
while(number > 10) {
sum = 0;
while(number != 0) {
sum += number % 10;
number /= 10;
}
number = sum;
}
printf("결과:%d\n", number);
}*/


// 수정한 소스
#include <stdio.h>
int main()
{
	int number, sum; //원래값과 각자리수값을 합할 number변수와 sum변수를 선언합니다.

	printf(" 숫자를 입력하시오: ");
	scanf("%d", &number);//구하고자 하는 값을 입력 받습니다.

	while (number >= 10) //number가 2자리 수일때      *****number>10이면 10일때 2자리수이지만 바로 결과값이 나오므로 >=로 바꿔줍니다.******
	{
		sum = 0;//합은 0으로 초기화 합니다. 각자리의 수의 합이 10이 넘어갈수있으므로 sum은 0으로 초기화 해줍니다.
		while (number != 0) //number 변수의 값이 아닐때
		{
			sum += number % 10;//number변수의 끝자리의 값을 sum에 더합니다.
			number /= 10;//number변수를 10으로 나눠주서 끝자리를 없앱니다.
		}
		number = sum;//각자리의 수의 합을 number변수로 넘겨주어 1자리면 나오고 2자리면 나옵니다.
	}
	printf("결과:%d\n", number);//최종 결과값을 화면에 출력합니다.
	return 0;
}