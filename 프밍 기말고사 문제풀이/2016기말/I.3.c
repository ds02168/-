#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500

//��ó���⸦ �ҷ����� �ִ�ũ�⸦ �����մϴ�.
int bar[MAXSIZE][12];
//���Ϸ� ���� �о�帰 ���� ������ ���ڵ� �迭�� �����մϴ�.
int main()
{
	FILE *fp1;
	int i, count = 0;

	//������ �ҷ��� ���� fp1,for������ Ƚ���� �� i����, ���� �ڵ尡 745�� ��ǰ������ �� count�� �����մϴ�.

	if ((fp1 = fopen("C:\\Users\\YTH\\Desktop\\a\\barcode.txt", "r")) != NULL)
		printf("���� �б�Ϸ�!!\n");//���� �б⼺���� �Ϸ� ���
	else
	{
		printf("���� �б� ����!!!\n");
		exit(1);//���� �б� ���н� ���и� ȭ�鿡 ����ϰ� ���α׷��� �����մϴ�.
	}

	i = 0;//i(�ٰ�)�� 0���� �ʱ�ȭ �մϴ�.
	while (!feof(fp1))
	{
		if (i == MAXSIZE)// ���� ������ �迭���� ���ڵ� �����Ͱ� �� ũ��
		{
			printf("error!!! buffer is over!!!\n");
			exit(1);//��������� ���α׷��� �����մϴ�.
		}

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d ", &bar[i][0], &bar[i][1], &bar[i][2], &bar[i][3], &bar[i][4], &bar[i][5], &bar[i][6], &bar[i][7], &bar[i][8], &bar[i][9], &bar[i][10], &bar[i][11]);
		//������ ���پ� 12�ڸ� ���ڵ带 �ϰſ� ���ڵ� �迭�� �����մϴ�.

		if (bar[i][0] == 7 && bar[i][1] == 4 && bar[i][2] == 5) //�˻���� 2�� ��ǰ�̸�
			count++;//���� ����

		i++;//�� �� ����
	}

	printf("���� �ڵ尡 745�� ��ǰ ����: %d\n", count);//���� �ڵ尡 745�� ��ǰ�� ������ ȭ�鿡 ����մϴ�.

	fclose(fp1);//���� �ݱ�
	return 0;
}