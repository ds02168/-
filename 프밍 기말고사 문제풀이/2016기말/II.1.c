#include <stdio.h>
#include <stdlib.h>

//��������� �ҷ��ɴϴ�.

int valid_date(int, int, int);
int gregorian(int, int, int);

//�Լ��� �����մϴ�.
char day[][4] = { "��","��","ȭ","��","��","��","��" };
//������ �����ϴ� �迭�� �����մϴ�.(0=��,1=��,2=ȭ,3=��,4=��,5=��,6=��)
int main()
{
	FILE *fp;//fp�� ������ �б��������� ���� �����Դϴ�.
	int year, month, date; //��,��,���� �����ϴ� ������ �����մϴ�.
	
	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\calendar.txt","r")) != NULL)
		printf("���� �б� �Ϸ�!!!\n"); //���� �б� ������ ȭ�� ���
	else
	{
		printf("����!! ���� �б� ���� !!!\n");
		exit(1);//���н� ��������� ���α׷��� �����մϴ�.
	}

	while (!feof(fp))//������ �� ����
	{
		fscanf(fp, "%d %d %d", &year, &month, &date);//���پ� �о� year, month, date�� �� ��,��,�� �����͸� �����մϴ�.

		if (!valid_date(year, month, date))//�޷¿� �����ϴ� ��¥���� Ȯ���մϴ�.
		{
			printf("%d��%d��%d���� ���� ��¥�Դϴ�.\n", year, month, date);
			continue;//���������ʴ´ٸ� ȭ�鿡 ����� ���� �ٷ� �Ѿ�ϴ�.
		}

		if (year == 1916 && month == 3 && date == 1)//1916�� 3�� 1���� ���Ͽ� �����Ѵٸ�
		{
			printf("%d�� %d�� %d���� %s���� �Դϴ�.\n", year, month, date, day[gregorian(year, month, date)]);
			exit(1);//ȭ�鿡 ������ ����ϰ� ���α׷��� ���� �մϴ�.
		}

	}

	printf("1916�� 3�� 1���� ������ ���Ͽ� �������� �ʽ��ϴ�.\n");//1916�� 3�� 1���� �����Ϳ� ������ ����մϴ�.
	year = 1916;
	month = 3;
	date = 1;//1916�� 3�� 1���� year,month,date�� �����մϴ�.

	if (!valid_date(year, month, date))//�޷¿� �����ϴ� ��¥���� Ȯ���մϴ�.
	{
		printf("%d��%d��%d���� ���� ��¥�Դϴ�.\n", year, month, date);
		exit(1);//���������ʴ´ٸ� ȭ�鿡 ����� ���α׷��� �����մϴ�.
	}

	printf("%d�� %d�� %d���� %s���� �Դϴ�.\n", year, month, date, day[gregorian(year, month, date)]);

	//���������Ͽ� 1916�� 3�� 1���� �������� �ʴ´ٸ� ���Ƿ� �־��ְ� ������ ���մϴ�.
	return 0;
}

int valid_date(int year, int month, int date) // �����ϴ� ������ Ȯ�� �ϴ� �Լ�
{
	if (month < 1 || month > 12 || date < 1 || date > 31) // 1~12���� �ƴϰ� 1~31���� �ƴϸ�
		return 0;//0 ��ȯ

	if (month == 2)//2�� �϶�
	{
		if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && date <= 29)//�����̰� 29�� ���ϸ�
			return 1;// 1�� ��ȯ
		else if (!(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && date <= 28)//������ �ƴϰ� 28�� ���ϸ�
			return 1;//1�� ��ȯ
		else
			return 0;//�ٸ� ���� 0�� ��ȯ �մϴ�.
	}

	else//2���� �ƴѰ��
	{
		if ((month == 4 || month == 6 || month == 9 || month == 11) && date <= 30)//4,6,9,11���̰� 30�� ���ϸ�
			return 1;//1�� ��ȯ �մϴ�.
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date <= 31)//1,3,5,7,8,10,12���̰� 31�� ���ϸ�
			return 1;//1�� ��ȯ �մϴ�.
		else//�ٸ� ���
			return 0;//0�� ��ȯ�մϴ�.
	}

}

int gregorian(int year, int month, int date) //�׷������� ���ϴ� �Լ�
{
	int week;//0~7���� ���� ���� �����ϴ� week ������ �����մϴ�.
	if (month == 1 || month == 2) //1���̳� 2���̸�
	{
		month += 12;//1���϶� 13�� 2���϶� 14���� �մϴ�.
		year -= 1;//1���� ���ݴϴ�.
	}

	week = (21 * (year / 100)) / 4 + (5 * (year % 100)) / 4 + (26 * (month + 1)) / 10 + date - 1;//�׷������� ���մϴ�.

	return (week % 7);//0~6���� ���ϰ��� ��ȯ�մϴ�.
}
