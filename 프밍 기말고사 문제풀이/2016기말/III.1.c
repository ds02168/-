#include <stdio.h>
#include <stdlib.h>

//헤더 파일을 불러옵니다.
int main(void) {

	int y, m, d, g; // 년도를 저장하는 y변수, 달을 저장하는 m변수, 일을 저장하는 d변수, 세대를 저장하는 g변수를 선언합니다.
	int boy = 0;//남자아이 수를 저장하는 boy변수를 선언합니다.
	int girl = 0;//여자아이 수를 저장하는 girl변수를 선언합니다.

	FILE *fp;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\ssn.txt", "r")) != NULL) //파일을 불러오기에 성공하면
		printf("파일 읽기 완료!!!\n");//성공 화면 출력
	else//실패 하면
	{
		printf("파일 읽기 실패!!!\n");
		exit(1);
	}//화면 출력후 프로그램을 종료 합니다.

	while (!feof(fp))//파일이 유효하는동안
	{
		fscanf(fp, "%2d%2d%2d%1d ", &y, &m, &d, &g);//파일의 차례로 2정수는 y로저장 그다음 2정수는 m로 저장 그다음 2정수는  d로 저장 그다음 1정수는 g에 저장합니다.

		if (y >= 0) //2000년생 이상이고
		{
			if (g == 3 || g== 7)//세대 번호가 3(내국인)이거나 7(외국인)이면
				boy++;//남자 아이수 추가
			else if (g == 4 || g == 8)//세대 번호가 4(내국인)이거나 8(외국인)이면
				girl++;//여자 아이수 추가
		}
	}

	printf("2000년 이후 테어난 남자아이들 수:%d, 여자아이들 수:%d\n", boy, girl);//화면에 남자아이수와 여자아이수를 출력합니다.

	fclose(fp);
	return 0;
}
