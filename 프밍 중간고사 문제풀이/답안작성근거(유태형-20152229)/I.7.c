#include <stdio.h>
#include <math.h> //pow함수를 쓰므로 math.h도 선언하였습니다.

int main()
{
	int binary[32] = { 0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 };// 2진수의 값을 담을 binary배열(32자리 2진수라서 배열크기를 32로하였습니다.)을 선언하였습니다.
	int i;//for문에서 횟수를 저장할 i변수를 선언해였습니다.
	unsigned int result = 0;//32자리 2진수이므로 4바이트가 필요하여 음수2바이트를 사용하지않고 양수로만 4바이트쓰는 unsigned int를 사용하였습니다.

	for (i = 0; i<= 31; i++)//binary 인덱스는 0부터 31까지이므로 i가 31까지 돕니다.
	{
		if (binary[31-i] == 1) //실제 2진수에선 맨오른쪽이 최소자리값이지만 배열 binary의 최소자리값은 왼쪽이라 거꾸로 계산하기위해 31-i로 하였습니다.
			result = result + pow(2, i);//pow함수를 사용하여 binary배열이 1일때 2의 i승을 result변수에 더해줍니다.

	}
	printf("2진수 :");
	for (i = 0; i < sizeof(binary) / sizeof(int); i++)
		printf("%d", binary[i]); //for문을 이용하여 2진수를 출력합니다.

	printf("\n");
	printf("8진수: %o, 16진수: %x, 10진수: %d 입니다.\n", result, result, result); //결과값을 출력하는데 %o는 8진수 %x는 16진수를 출력하는 형식지정문자입니다.
	return 0;

}