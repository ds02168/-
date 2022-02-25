#include <stdio.h>

int is_rightangle(int, int, int);//삼각형인지 판별하는 함수

int main()
{
	int x, y, z, count = 0;//세변의 길이와 직각삼각형의 갯수를 저장하는 count변수
	FILE *fp;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\triangle.txt", "r")) != NULL)//파일 읽기에 성공하면
		printf("파일 읽기 완료!!!\n");//화면 출력

	else//실패하면
	{
		printf("파일 읽기 실패!!!\n");
		exit(1);
	}//화면 출력후 종료

	while (!feof(fp)) //파일이 유효하는동안
	{
		fscanf(fp, "%d %d %d", &x, &y, &z); //각 줄에서 3변을 읽어들입니다.

		if (is_rightangle(x, y, z))//직각삼각형이면
			count++;//갯수증가
	}

	printf("직각삼각형의 갯수는 %d개 입니다.\n", count);//직각삼각형의 갯수를 화면에 출력합니다.

	fclose(fp);
	return 0;
}

int is_rightangle(int x, int y, int z)//직각삼각형인지 판별하는 함수
{
	if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x)//짧은 두변의 각각 제곱의 합이 긴변의 제곱과 같다면
		return 1;//1을 반환합니다.
	else//아니면
		return 0;//0을 반환합니다.
}