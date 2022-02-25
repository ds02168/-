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
		printf("�����б� �Ϸ�!!!\n");
	else
	{
		printf("�����б� ����!!!\n");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d", &a, &b, &c);
		if (!is_angle(a, b, c))
		{
			printf("%d %d %d�� �ﰢ���� �ƴմϴ�.!!\n",a,b,c);
			nangle++;
			continue;
		}

		if (is_double(a, b, c))
		{
			printf("%d %d %d�� �̵(���ﰢ�� ����) �ﰢ���Դϴ�.\n", a, b, c);
			dangle++;
		}

		if (is_obtuse(a, b, c))
		{
			printf("%d %d %d�� �а� �ﰢ�� �ﰢ���Դϴ�.\n", a, b, c);
			oangle++;
		}

	}

	printf("�ﰢ���� �ƴ� ������ ��: %d\n", nangle);
	printf("�̵�ﰢ��(���ﰢ�� ����) ������ ��: %d\n", dangle);
	printf("�а� �ﰢ�� ������ ��: %d\n", oangle);


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