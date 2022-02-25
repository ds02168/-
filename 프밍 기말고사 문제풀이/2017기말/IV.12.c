#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define MEMBER 20//MEMBER : 플레이어 수
#define GAME 5//GAME : 게임 수
#define FRAME 10//FRAME : 프레임 수

#define VER 16//VER : 기말고사 년도(16년도 데이터파일을 읽을때에는 16, 17년도 데이터파일을 읽을때에는 16을 제외한 숫자를 적어주면됩니다.)

#define BUFF_SIZE 100

#define FILE_NAME "C:\\Users\\YTH\\Desktop\\b\\bowling.txt"//FILE_NAME : 텍스트파일명

int score[FRAME + 4][2];
int total[FRAME + 4];
int score_infor[MEMBER][GAME];
double avg_score[MEMBER];
int game_count[MEMBER] = { 0 };
int member;

char buff[BUFF_SIZE];
char *tok;

int strike(int i);
int not_strike(int i);

void main(void) {
	FILE *fp;
	int i, j, tmp;

	fp = fopen(FILE_NAME, "r");

	while (!feof(fp)) {
		memset(score, 0, sizeof(int)*(FRAME + 4) * 2);
		memset(total, 0, sizeof(int)*(FRAME + 4));
		memset(buff, 0, BUFF_SIZE);

		fgets(buff, BUFF_SIZE - 1, fp);

		tok = strtok(buff, " ");
		member = atoi(tok) - 1;
		i = 1;
		while (i<FRAME + 3) {
			i++;
			if ((tok = strtok(NULL, " ")) != NULL) score[i][0] = atoi(tok);

			if (score[i][0] == 10) {
				if (VER == 16)
					if (i <= FRAME && (tok = strtok(NULL, " ")) != NULL)score[i][1] = atoi(tok);
				if (!strike(i)) break;
			}
			else {
				if (!not_strike(i)) break;
			}
		}
		score_infor[member][game_count[member]] = total[FRAME + 1];
		game_count[member]++;
	}
	for (i = 0; i < MEMBER; i++) {
		tmp = 0;
		for (j = 0; j < GAME; j++) tmp += score_infor[i][j];
		avg_score[i] = tmp / GAME;
	}

	for (i = 0; i < MEMBER; i++) {
		for (j = 0; j < GAME; j++) {
			printf("%d ", score_infor[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < MEMBER; i++) {
		printf("%lf\n", avg_score[i]);
	}



	return 0;
}

int strike(int i) {
	if (score[i - 2][0] == 10 && score[i - 1][0] == 10) total[i - 2] = total[i - 3] + 30;
	else if (score[i - 1][0] != 10 && score[i - 1][0] + score[i - 1][1] == 10) {
		total[i - 1] = total[i - 2] + 20;
		if (i == FRAME + 2) return 0;
	}
	return 1;
}

int not_strike(int i) {
	if (score[i - 2][0] == 10 && score[i - 1][0] == 10) {
		total[i - 2] = total[i - 3] + 20 + score[i][0];
		if (i == FRAME + 3) return 0;
	}
	else if (score[i - 1][0] != 10 && score[i - 1][0] + score[i - 1][1] == 10) {
		total[i - 1] = total[i - 2] + 10 + score[i][0];
		if (i == FRAME + 2 || i == FRAME + 3) return 0;
	}

	if ((tok = strtok(NULL, " ")) != NULL) score[i][1] = atoi(tok);

	if (score[i - 1][0] == 10) {
		if (score[i][0] + score[i][1] == 10) {
			total[i - 1] = total[i - 2] + 20;
			if (i == FRAME + 2) return 0;
		}
		else {
			total[i - 1] = total[i - 2] + 10 + score[i][0] + score[i][1];
			total[i] = total[i - 1] + score[i][0] + score[i][1];
			if (i == FRAME + 2) return 0;
		}
	}
	else if (score[i][0] + score[i][1] < 10) {
		total[i] = total[i - 1] + score[i][0] + score[i][1];
		if (i == FRAME + 1) return 0;
	}
	return 1;
}