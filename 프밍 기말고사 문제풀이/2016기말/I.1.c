#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500

//��ó���⸦ �ҷ����� �ִ�ũ�⸦ �����մϴ�.
int bar[MAXSIZE][12];
//���Ϸ� ���� �о�帰 ���� ������ ���ڵ� �迭�� �����մϴ�.
int main()
{
	FILE *fp1;
	int i;

	//������ �ҷ��� ���� fp1,for������ Ƚ���� �� i������ �����մϴ�.

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
		
		if (bar[i][0] == 9 && bar[i][1] == 2 && bar[i][2] == 5 && bar[i][3] == 4 && bar[i][4] == 5 && bar[i][5] == 6 && bar[i][6] == 7 && bar[i][7] == 8 && bar[i][8] == 9 && bar[i][9] == 5 && bar[i][10] == 0 && bar[i][11] == 4)
		{ //���ڵ尡 925456789504�� ��쿡
			printf("���ڵ� ��ȣ 925456789504�� �˻���� %d�Դϴ�.\n", bar[i][11]);
			break;//�˻���� ����ϰ� while�� Ż���մϴ�.
		}
		i++;//�� �� ����
	}


	fclose(fp1);//���� �ݱ�
	return 0;
}