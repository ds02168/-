#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int bar[13];
	int i, check = 0;
	int error=0, contry=0;

	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\b\\barcode.txt", "r")) != NULL)
		printf("파일 읽기 완료!!\n");
	else
	{
		printf("파일 읽기 실패!!\n");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d", &bar[0], &bar[1], &bar[2], &bar[3], &bar[4], &bar[5], 
			&bar[6], &bar[7], &bar[8], &bar[9], &bar[10], &bar[11], &bar[12]);

		for (i = 0; i < 12; i++)
		{
			if (i % 2 == 0)
				check += bar[i];
			else if (i % 2 == 1)
				check = check + 3 * bar[i];
		}

		if ((check + bar[12]) % 10 != 0)
			error++;




		if ((bar[0] == 8 && bar[1] == 8 && bar[2] == 0) || (bar[3] == 1 && bar[4] == 0 && bar[5] == 4 && bar[6] == 3))
			contry++;

	}


	printf("데이터에 존재하지 않음, 검사수: %d\n", (10 - (check) % 10));
	printf("데이터 파일에 있는 상품데이터들 중에서 바코드의 검사수가 잘못된 것들의 개수는: %d\n", error);
	printf("국가코드가 880인 나라에서 제조되었거나  제조회사코드가 1043인 업체에서 제조된 상품들의 개수: %d\n", contry);

	fclose(fp);

	return 0;
}