#include <stdio.h>

int is_triangle(int, int, int);//�ﰢ���� �������� ���ϴ� �Լ�

int main()
{
	int x, y, z, count = 0; //������ ���̸� �����ϴ� x,y,z������ �ﰢ���� �ɼ����� �������� ������ ���� count������ �����մϴ�.
	FILE *fp;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\triangle.txt", "r")) != NULL)//���� �б⿡ �����ϸ�
		printf("���� �б� �Ϸ�!!!\n");//ȭ�� ���

	else//�����ϸ�
	{
		printf("���� �б� ����!!!\n");
		exit(1);
	}//ȭ�� ����� �����մϴ�.

	while (!feof(fp))//������ ��ȿ�ϴ� ����
	{
		fscanf(fp, "%d %d %d", &x, &y, &z);//���Ϸκ��� ������ �����͸� x,y,z������ �����մϴ�.

		if (!is_triangle(x, y, z))//�ﰢ���� �ƴϸ�
			count++;//��������

	}

	printf("�ﰢ���� �ɼ� ���� �������� ������ %d�� �Դϴ�.\n", count); //������ ȭ�鿡 ����մϴ�.

	fclose(fp);
	return 0;
}


int is_triangle(int x, int y, int z)//�ﰢ������ Ȯ���ϴ� �Լ�
{
	if (x <= 0 || y <= 0 || z <= 0)
		return 0; //0�����̸� ���� ��ȯ

	if (x + y <= z || x + z <= y || y + z <= x)//���� �� ������ ���� ū �������� �۰ų� ������
		return 0;//�ﰢ���� �� ���� �����ϴ�.
	else//�׿ܿ�
		return 1;//�ﰢ�� ����
}
