/* ���� �ҽ��Դϴ�.
#include <stdio.h>
int main()
{
int number, sum;
printf(" ���ڸ� �Է��Ͻÿ�: ");
scanf("%d", &number);
while(number > 10) {
sum = 0;
while(number != 0) {
sum += number % 10;
number /= 10;
}
number = sum;
}
printf("���:%d\n", number);
}*/


// ������ �ҽ�
#include <stdio.h>
int main()
{
	int number, sum; //�������� ���ڸ������� ���� number������ sum������ �����մϴ�.

	printf(" ���ڸ� �Է��Ͻÿ�: ");
	scanf("%d", &number);//���ϰ��� �ϴ� ���� �Է� �޽��ϴ�.

	while (number >= 10) //number�� 2�ڸ� ���϶�      *****number>10�̸� 10�϶� 2�ڸ��������� �ٷ� ������� �����Ƿ� >=�� �ٲ��ݴϴ�.******
	{
		sum = 0;//���� 0���� �ʱ�ȭ �մϴ�. ���ڸ��� ���� ���� 10�� �Ѿ�������Ƿ� sum�� 0���� �ʱ�ȭ ���ݴϴ�.
		while (number != 0) //number ������ ���� �ƴҶ�
		{
			sum += number % 10;//number������ ���ڸ��� ���� sum�� ���մϴ�.
			number /= 10;//number������ 10���� �����ּ� ���ڸ��� ���۴ϴ�.
		}
		number = sum;//���ڸ��� ���� ���� number������ �Ѱ��־� 1�ڸ��� ������ 2�ڸ��� ���ɴϴ�.
	}
	printf("���:%d\n", number);//���� ������� ȭ�鿡 ����մϴ�.
	return 0;
}