#include <stdio.h>

int is_rightangle(int, int, int);//�ﰢ������ �Ǻ��ϴ� �Լ�

int main()
{
	int x, y, z, count = 0;//������ ���̿� �����ﰢ���� ������ �����ϴ� count����
	FILE *fp;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\triangle.txt", "r")) != NULL)//���� �б⿡ �����ϸ�
		printf("���� �б� �Ϸ�!!!\n");//ȭ�� ���

	else//�����ϸ�
	{
		printf("���� �б� ����!!!\n");
		exit(1);
	}//ȭ�� ����� ����

	while (!feof(fp)) //������ ��ȿ�ϴµ���
	{
		fscanf(fp, "%d %d %d", &x, &y, &z); //�� �ٿ��� 3���� �о���Դϴ�.

		if (is_rightangle(x, y, z))//�����ﰢ���̸�
			count++;//��������
	}

	printf("�����ﰢ���� ������ %d�� �Դϴ�.\n", count);//�����ﰢ���� ������ ȭ�鿡 ����մϴ�.

	fclose(fp);
	return 0;
}

int is_rightangle(int x, int y, int z)//�����ﰢ������ �Ǻ��ϴ� �Լ�
{
	if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x)//ª�� �κ��� ���� ������ ���� �亯�� ������ ���ٸ�
		return 1;//1�� ��ȯ�մϴ�.
	else//�ƴϸ�
		return 0;//0�� ��ȯ�մϴ�.
}