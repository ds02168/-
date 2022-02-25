#include <stdio.h>
#include <stdlib.h>

//헤더파일을 불러옵니다.

int valid_date(int, int, int);
int gregorian(int, int, int);

//함수를 선언합니다.
char day[][4] = { "일","월","화","수","목","금","토" };
//요일을 저장하는 배열을 선언합니다.(0=일,1=월,2=화,3=수,4=목,5=금,6=토)
int main()
{
	FILE *fp;//fp는 파일을 읽기형식으로 여는 변수입니다.
	int year, month, date; //년,월,일을 저장하는 변수를 선언합니다.
	
	if ((fp = fopen("C:\\Users\\YTH\\Desktop\\a\\calendar.txt","r")) != NULL)
		printf("파일 읽기 완료!!!\n"); //파일 읽기 성공시 화면 출력
	else
	{
		printf("에러!! 파일 읽기 실패 !!!\n");
		exit(1);//실패시 에러출력후 프로그램을 종료합니다.
	}

	while (!feof(fp))//파일의 끝 동안
	{
		fscanf(fp, "%d %d %d", &year, &month, &date);//한줄씩 읽어 year, month, date에 각 년,월,일 데이터를 저장합니다.

		if (!valid_date(year, month, date))//달력에 존재하는 날짜인지 확인합니다.
		{
			printf("%d년%d일%d일은 없는 날짜입니다.\n", year, month, date);
			continue;//존재하지않는다면 화면에 출력후 다음 줄로 넘어갑니다.
		}

		if (year == 1916 && month == 3 && date == 1)//1916년 3월 1일이 파일에 존재한다면
		{
			printf("%d년 %d월 %d일은 %s요일 입니다.\n", year, month, date, day[gregorian(year, month, date)]);
			exit(1);//화면에 요일을 출력하고 프로그램을 종료 합니다.
		}

	}

	printf("1916년 3월 1일은 데이터 파일에 존재하지 않습니다.\n");//1916년 3월 1일은 데이터에 없음을 출력합니다.
	year = 1916;
	month = 3;
	date = 1;//1916년 3월 1일을 year,month,date에 저장합니다.

	if (!valid_date(year, month, date))//달력에 존재하는 날짜인지 확인합니다.
	{
		printf("%d년%d일%d일은 없는 날짜입니다.\n", year, month, date);
		exit(1);//존재하지않는다면 화면에 출력후 프로그램을 종료합니다.
	}

	printf("%d년 %d월 %d일은 %s요일 입니다.\n", year, month, date, day[gregorian(year, month, date)]);

	//데이터파일에 1916년 3월 1일이 존재하지 않는다면 임의로 넣어주고 요일을 구합니다.
	return 0;
}

int valid_date(int year, int month, int date) // 존재하는 날인지 확인 하는 함수
{
	if (month < 1 || month > 12 || date < 1 || date > 31) // 1~12월이 아니고 1~31일이 아니면
		return 0;//0 반환

	if (month == 2)//2월 일때
	{
		if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && date <= 29)//윤년이고 29일 이하면
			return 1;// 1을 반환
		else if (!(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && date <= 28)//윤년이 아니고 28일 이하면
			return 1;//1을 반환
		else
			return 0;//다른 경우는 0을 반환 합니다.
	}

	else//2월이 아닌경우
	{
		if ((month == 4 || month == 6 || month == 9 || month == 11) && date <= 30)//4,6,9,11월이고 30일 이하면
			return 1;//1을 반환 합니다.
		else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date <= 31)//1,3,5,7,8,10,12월이고 31일 이하면
			return 1;//1을 반환 합니다.
		else//다른 경우
			return 0;//0을 반환합니다.
	}

}

int gregorian(int year, int month, int date) //그레고리력을 구하는 함수
{
	int week;//0~7사이 요일 값을 저장하는 week 변수를 선언합니다.
	if (month == 1 || month == 2) //1월이나 2월이면
	{
		month += 12;//1월일때 13월 2월일때 14월로 합니다.
		year -= 1;//1년을 빼줍니다.
	}

	week = (21 * (year / 100)) / 4 + (5 * (year % 100)) / 4 + (26 * (month + 1)) / 10 + date - 1;//그레고리력을 구합니다.

	return (week % 7);//0~6사이 요일값을 반환합니다.
}
