#include<stdio.h>
#include<stdlib.h>
#include<math.h>


unsigned long long combination(int, int);


int main()
{
	int a, b;
	unsigned long long result;
	printf("������ �μ��� �Է��Ͻÿ�:(a b)");
	scanf("%d %d", &a, &b);

	result = combination(a, b);

	printf("%d Combine %d = %lld\n", a, b, result);

	return 0;
}

unsigned long long combination(int n, int r)
{
	unsigned long long com = 1;
	int i;

	if (n / 2 > r)
		r = n - r;

	for (i = r + 1; i <= n; i++)
		com *= i;
	for (i = 1; i <= n - r; i++)
		com /= i;

	return com;
}