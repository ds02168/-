#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_angle(int, int, int);
int is_double(int, int, int);
int is_obtuse(int, int, int);

int main()
{
	FILE *fp;
	int a, b, c;
	int nangle = 0, dangle = 0, oangle = 0;
	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\b\\triangle.txt", "r")) != NULL)
		printf("파일읽기 완료!!!\n");
	else
	{
		printf("파일읽기 실패!!!\n");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d", &a, &b, &c);
		if (!is_angle(a, b, c))
		{
			printf("%d %d %d는 삼각형이 아닙니다.!!\n",a,b,c);
			nangle++;
			continue;
		}

		if (is_double(a, b, c))
		{
			printf("%d %d %d는 이등변(정삼각형 제외) 삼각형입니다.\n", a, b, c);
			dangle++;
		}

		if (is_obtuse(a, b, c))
		{
			printf("%d %d %d는 둔각 삼각형 삼각형입니다.\n", a, b, c);
			oangle++;
		}

	}

	printf("삼각형이 아닌 데이터 수: %d\n", nangle);
	printf("이등변삼각형(정삼각형 제외) 데이터 수: %d\n", dangle);
	printf("둔각 삼각형 데이터 수: %d\n", oangle);


	fclose(fp);
	return 0;
}

int is_angle(int a, int b, int c)
{
	if (a + b <= c || a + c <= b || b + c <= a)
		return 0;
	else
		return 1;
}

int is_double(int a, int b, int c)
{
	if ((a == b != c) || (a == c != b) || (b == c != a))
		return 1;
	else
		return 0;
}

int is_obtuse(int a, int b, int c)
{
	if ((a * a + b * b < c*c) || (a * a + c * c < b * b) || (b * b + c * c < a * a))
		return 1;
	else
		return 0;
}