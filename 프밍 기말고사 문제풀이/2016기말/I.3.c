#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500

//전처리기를 불러오고 최대크기를 지정합니다.
int bar[MAXSIZE][12];
//파일로 부터 읽어드린 값을 저장할 바코드 배열을 선언합니다.
int main()
{
	FILE *fp1;
	int i, count = 0;

	//파일을 불러올 변수 fp1,for문에서 횟수를 셀 i변수, 국가 코드가 745인 상품갯수를 셀 count를 선언합니다.

	if ((fp1 = fopen("C:\\Users\\YTH\\Desktop\\a\\barcode.txt", "r")) != NULL)
		printf("파일 읽기완료!!\n");//파일 읽기성공시 완료 출력
	else
	{
		printf("파일 읽기 실패!!!\n");
		exit(1);//파일 읽기 실패시 실패를 화면에 출력하고 프로그램을 종료합니다.
	}

	i = 0;//i(줄값)를 0으로 초기화 합니다.
	while (!feof(fp1))
	{
		if (i == MAXSIZE)// 값을 저장할 배열보다 바코드 데이터가 더 크면
		{
			printf("error!!! buffer is over!!!\n");
			exit(1);//에러출력후 프로그램을 종료합니다.
		}

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d ", &bar[i][0], &bar[i][1], &bar[i][2], &bar[i][3], &bar[i][4], &bar[i][5], &bar[i][6], &bar[i][7], &bar[i][8], &bar[i][9], &bar[i][10], &bar[i][11]);
		//파일을 한줄씩 12자리 바코드를 일거와 바코드 배열에 저장합니다.

		if (bar[i][0] == 7 && bar[i][1] == 4 && bar[i][2] == 5) //검사수가 2인 상품이면
			count++;//갯수 증가

		i++;//줄 값 증가
	}

	printf("국가 코드가 745인 상품 갯수: %d\n", count);//국가 코드가 745인 상품의 갯수를 화면에 출력합니다.

	fclose(fp1);//파일 닫기
	return 0;
}