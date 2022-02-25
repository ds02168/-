#include <stdio.h>

int is_triangle(int, int, int);//삼각형이 가능한지 구하는 함수

int main()
{
	int x, y, z, count = 0; //세변의 길이를 저장하는 x,y,z변수와 삼각형이 될수없는 데이터의 갯수를 세는 count변수를 선언합니다.
	FILE *fp;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\triangle.txt", "r")) != NULL)//파일 읽기에 성공하면
		printf("파일 읽기 완료!!!\n");//화면 출력

	else//실패하면
	{
		printf("파일 읽기 실패!!!\n");
		exit(1);
	}//화면 출력후 종료합니다.

	while (!feof(fp))//파일이 유효하는 동안
	{
		fscanf(fp, "%d %d %d", &x, &y, &z);//파일로부터 세변의 데이터를 x,y,z변수에 저장합니다.

		if (!is_triangle(x, y, z))//삼각형이 아니면
			count++;//갯수증가

	}

	printf("삼각형이 될수 없는 데이터의 갯수는 %d개 입니다.\n", count); //갯수를 화면에 출력합니다.

	fclose(fp);
	return 0;
}


int is_triangle(int x, int y, int z)//삼각형인지 확인하는 함수
{
	if (x <= 0 || y <= 0 || z <= 0)
		return 0; //0이하이면 거짓 반환

	if (x + y <= z || x + z <= y || y + z <= x)//작은 두 변수의 합이 큰 변수보다 작거나 같으면
		return 0;//삼각형이 될 수가 없습니다.
	else//그외에
		return 1;//삼각형 가능
}
