#include <stdio.h>
#include <stdlib.h>
//헤더 파일을 불러옵니다.

int main(void) {

	int y, m, d, g;// 년도를 저장하는 y변수, 달을 저장하는 m변수, 일을 저장하는 d변수, 세대를 저장하는 g변수를 선언합니다.
	int many[12][31] = { 0 };//행엔 달을 저장하고 열엔 일자를 저장하는 이중배열을 선언합니다.
	int many_m = 0;//그달에 태어난 사람의 수를 저장하는 변수를 선언합니다.
	int many_d = 0;//그 일에 태어난 사람의 수를 저장하는 변수를 선언합니다.
	int i, j;//달을 세는 i변수, 일을 세는 j변수를 선언합니다.

	FILE *fp;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\ssn.txt", "r")) != NULL)//파일을 불러오기에 성공하면
		printf("파일 읽기 완료!!!\n");//성공 화면 출력

	else//실패 하면
	{
		printf("파일 읽기 실패!!!\n");
		exit(1);
	}//화면 출력후 프로그램을 종료 합니다.

	while (!feof(fp))//파일이 유효하는동안
	{
		fscanf(fp, "%2d%2d%2d%1d ", &y, &m, &d, &g);//파일의 차례로 2정수는 y로저장 그다음 2정수는 m로 저장 그다음 2정수는  d로 저장 그다음 1정수는 g에 저장합니다.

		many[m - 1][d - 1]++;//날짜에 해당하는 배열의 원소에 1을 추가합니다.
	}

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 31; j++) { //1월 1일부터 12월 31일 까지
			if (many[many_m][many_d] < many[i][j]) {//many배열에 있는 원소보다 더큰 원소를 발견하면
				many_m = i;
				many_d = j;//원소의 값을 바꿔줍니다.
			}
		}
	}

	printf("가장 많이 태어난 날짜:%d월 %d일   태어난 사람 수:%d\n", many_m + 1, many_d + 1, many[many_m][many_d]); 
	//가장 많이 태어난 날짜와 사람수를 화면에 출력합니다.

	fclose(fp);
	return 0;
}
