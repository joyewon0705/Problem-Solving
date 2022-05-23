#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define N 17017
typedef struct {
	unsigned char
		d0 : 2, d1 : 2, d2 : 2, d3 : 2;
} dclist;		// 1byte
int getd(dclist dcs, int n);
void putd(dclist* dcs, int n, int d);
void printedit(int i, int j);
char str1[N], str2[N];
int search[2][N + 1] = { 0 };
dclist info[N + 1][N / 4 + 1] = { 0 };

int main(void) {
	int s1, s2, s3;

	scanf("%s", str1);
	scanf("%s", str2);

	for (int j = 1; j <= strlen(str1); j++) {
		search[0][j] = j;
		putd(&info[0][j / 4], j, 1);
	}

	for (int i = 1; i <= strlen(str2); i++) {
		for (int j = 0; j <= strlen(str1); j++) {
			if (j == 0) {
				search[i % 2][j] = i;
				putd(&info[i][0], 0, 3);
				continue;
			}
			if (str1[j - 1] == str2[i - 1]) {
				search[i % 2][j] = search[(i - 1) % 2][j - 1];
				putd(&info[i][j / 4], j, 0);
				continue;
			}

			s1 = search[i % 2][j - 1];
			s2 = search[(i - 1) % 2][j - 1];
			s3 = search[(i - 1) % 2][j];
			if (s2 < s3) {
				if (s1 < s2) {
					search[i % 2][j] = s1 + 1;
					putd(&info[i][j / 4], j, 1);
				}
				else {
					search[i % 2][j] = s2 + 1;
					putd(&info[i][j / 4], j, 2);
				}
			}
			else {
				if (s3 < s1) {
					search[i % 2][j] = s3 + 1;
					putd(&info[i][j / 4], j, 3);
				}
				else {
					search[i % 2][j] = s1 + 1;
					putd(&info[i][j / 4], j, 1);
				}
			}
		}
	}

	printedit(strlen(str2), strlen(str1));

	return 0;
}

void printedit(int i, int j) {

	if (i == 0 && j == 0) return;

	switch (getd(info[i][j / 4], j)) {
	case 0:
		printedit(i - 1, j - 1);
		printf("c %c\n", str2[i - 1]);
		return;
	case 1:
		printedit(i, j - 1);
		printf("d %c\n", str1[j - 1]);
		return;
	case 2:
		printedit(i - 1, j - 1);
		printf("m %c\n", str2[i - 1]);
		return;
	case 3:
		printedit(i - 1, j);
		printf("a %c\n", str2[i - 1]);
		return;
	}
}

int getd(dclist dcs, int n) {
	switch (n % 4) {
	case 0:
		return dcs.d0;
	case 1:
		return dcs.d1;
	case 2:
		return dcs.d2;
	case 3:
		return dcs.d3;
	}
	return 0;
}

void putd(dclist* dcs, int n, int d) {
	switch (n % 4) {
	case 0:
		dcs->d0 = d;
		break;
	case 1:
		dcs->d1 = d;
		break;
	case 2:
		dcs->d2 = d;
		break;
	case 3:
		dcs->d3 = d;
		break;
	}
}

/*
#include <stdio.h>
#include <string.h>
#define N 17000
typedef struct {
	unsigned
		d0 : 2, c0 : 1, d1 : 2, c1 : 1, d2 : 2, c2 : 1, d3 : 2, c3 : 1, d4 : 2, c4 : 1,
		d5 : 2, c5 : 1, d6 : 2, c6 : 1, d7 : 2, c7 : 1, d8 : 2, c8 : 1, d9 : 2, c9 : 1;
} dclist;		// 4byte
typedef struct {
	int direction;
	_Bool change;
} dc;

dc getdc(dclist dcs, int n);
void putdc(dclist* dcs, int n, int d, _Bool c);
void printedit(int i, int j);

char str1[N], str2[N];
int search[2][N + 1] = { 0 };
dclist info[N + 1][N / 10 + 1] = { 0 };

int main(void) {
	int s1, s2, s3;

	scanf("%s", str1);
	scanf("%s", str2);

	for (int i = 1; i <= strlen(str1); i++) {
		search[0][i] = i;
		putdc(&info[0][i / 10], i, 1, 1);
	}
	for (int i = 1; i <= strlen(str2); i++) {
		search[i][0] = i;
		putdc(&info[i][0], 0, 3, 1);
	}

	for (int i = 1; i <= strlen(str2); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[j - 1] == str2[i - 1]) {
				search[i % 2][j] = search[(i - 1) % 2][j - 1];
				putdc(&info[i][j / 10], j, 2, 0);
				continue;
			}

			s1 = search[i % 2][j - 1];
			s2 = search[(i - 1) % 2][j - 1];
			s3 = search[(i - 1) % 2][j];

			if (s2 < s3) {
				if (s1 < s2) {
					search[i % 2][j] = s1;
					putdc(&info[i][j / 10], j, 1, 1);
				}
				else {
					search[i % 2][j] = s2;
					putdc(&info[i][j / 10], j, 2, 1);
				}
			}
			else {
				if (s3 < s1) {
					search[i % 2][j] = s3;
					putdc(&info[i][j / 10], j, 3, 1);
				}
				else {
					search[i % 2][j] = s1;
					putdc(&info[i][j / 10], j, 1, 1);
				}
			}
		}
	}

	printedit(strlen(str2), strlen(str1));

	return 0;
}

void printedit(int i, int j) {
	dc temp;

	if (i == 0 && j == 0) return;

	temp = getdc(info[i][j / 10], j);
	if (!temp.change) {
		printedit(i - 1, j - 1);
		printf("c %c\n", str2[i - 1]);
		return;
	}
	else {
		switch (temp.direction) {
		case 1:
			printedit(i, j - 1);
			printf("d %c\n", str1[j - 1]);
			return;
		case 2:
			printedit(i - 1, j - 1);
			printf("m %c\n", str2[i - 1]);
			return;
		case 3:
			printedit(i - 1, j);
			printf("a %c\n", str2[i - 1]);
			return;
		}
	}

	return;
}

dc getdc(dclist dcs, int n) {
	dc temp = { 0 };

	switch (n % 10) {
	case 0:
		temp.direction = dcs.d0;
		temp.change = dcs.c0;
		break;
	case 1:
		temp.direction = dcs.d1;
		temp.change = dcs.c1;
		break;
	case 2:
		temp.direction = dcs.d2;
		temp.change = dcs.c2;
		break;
	case 3:
		temp.direction = dcs.d3;
		temp.change = dcs.c3;
		break;
	case 4:
		temp.direction = dcs.d4;
		temp.change = dcs.c4;
		break;
	case 5:
		temp.direction = dcs.d5;
		temp.change = dcs.c5;
		break;
	case 6:
		temp.direction = dcs.d6;
		temp.change = dcs.c6;
		break;
	case 7:
		temp.direction = dcs.d7;
		temp.change = dcs.c7;
		break;
	case 8:
		temp.direction = dcs.d8;
		temp.change = dcs.c8;
		break;
	case 9:
		temp.direction = dcs.d9;
		temp.change = dcs.c9;
		break;
	}

	return temp;
}

void putdc(dclist* dcs, int n, int d, _Bool c) {
	switch (n % 10) {
	case 0:
		dcs->d0 = d;
		dcs->c0 = c;
		break;
	case 1:
		dcs->d1 = d;
		dcs->c1 = c;
		break;
	case 2:
		dcs->d2 = d;
		dcs->c2 = c;
		break;
	case 3:
		dcs->d3 = d;
		dcs->c3 = c;
		break;
	case 4:
		dcs->d4 = d;
		dcs->c4 = c;
		break;
	case 5:
		dcs->d5 = d;
		dcs->c5 = c;
		break;
	case 6:
		dcs->d6 = d;
		dcs->c6 = c;
		break;
	case 7:
		dcs->d7 = d;
		dcs->c7 = c;
		break;
	case 8:
		dcs->d8 = d;
		dcs->c8 = c;
		break;
	case 9:
		dcs->d9 = d;
		dcs->c9 = c;
		break;
	}
}

*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 17000

int main(void) {
	int isUse1[N] = { 0 }, isUse2[N] = { 0 }, search[2][N] = { 0 };
	char* str1, * str2, buf[N + 1];
	int i, j, k;

	for (i = 0; i < N; i++) {
		search[0][i] = -1;
		search[1][i] = 17017;
	}

	// 입력
	scanf("%s", buf);
	str1 = (char*)calloc(strlen(buf) + 1, sizeof(char));
	strcat(str1, buf);
	scanf("%s", buf);
	str2 = (char*)calloc(strlen(buf) + 1, sizeof(char));
	strcat(str2, buf);

	// 같은 문자 탐색
	for (j = 0; j < strlen(str2); j++) {
		for (i = 0; i < strlen(str1); i++) {
			if (str2[j] == str1[i]) {
				isUse2[j] = i;
				if (isUse1[i] == 0) {
					isUse1[i] = 1;
					break;
				}
			}
			if (i == strlen(str1) - 1) isUse2[j] = -1;
		}
	}

	// 가장 긴 증가하는 수열 탐색
	for (i = 0, k = 0; i < strlen(str2); i++) {
		if (isUse2[i] == -1) {
			search[0][i] = -1;
			continue;
		}
		for (j = 0; j < i + 1; j++) {
			if (isUse2[i] <= search[1][j]) {
				search[1][j] = isUse2[i];
				search[0][i] = j;
				if (j > k) k = j;
				break;
			}
		}
	}

	for (int i = strlen(str2) - 1; i >= 0; i--) {
		if (search[0][i] == k) {
			k--;
			isUse1[isUse2[i]] = 1;
			isUse2[i] = 1;
			if (k < 0) k = -17017;
		}
		else isUse2[i] = 0;
	}

	// 출력
	i = j = 0;
	while ((i < strlen(str1)) && (j < strlen(str2))) {
		if (isUse1[i] && !isUse2[j]) {
			printf("a %c\n", str2[j]);
			j++;
		}
		else if (!isUse1[i] && isUse2[j]) {
			printf("d %c\n", str1[i]);
			i++;
		}
		else if (!isUse1[i] && !isUse2[j]) {
			printf("m %c\n", str2[j]);
			i++;
			j++;
		}
		else if (isUse1[i] && isUse2[j]) {
			printf("c %c\n", str2[j]);
			i++;
			j++;
		}
	}

	while (i < strlen(str1)) {
		printf("d %c\n", str1[i]);
		i++;
	}
	while (j < strlen(str2)) {
		printf("a %c\n", str2[j]);
		j++;
	}

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 17000

int main(void) {
	bool isUse1[N + 1] = { false }, isUse2[N + 1] = { false };
	char* str1, * str2, buf[N + 1];
	int i, j, k;

	scanf("%s", buf);
	str1 = (char*)calloc(strlen(buf) + 1, sizeof(char));
	strcat(str1, buf);
	scanf("%s", buf);
	str2 = (char*)calloc(strlen(buf) + 1, sizeof(char));
	strcat(str2, buf);

	for (i = 0, k = 0; i < strlen(str2); i++) {
		for (j = k; j < strlen(str1) + 1; j++) {
			if (str2[i] == str1[j]) {
				isUse2[i] = true;
				isUse1[j] = true;
				k = j + 1;
				break;
			}
		}
		if (k == strlen(str1)) break;
	}

	i = j = 0;
	while ((i < strlen(str2)) && (j < strlen(str1))) {
		if (!isUse2[i] && isUse1[j]) {
			printf("a %c\n", str2[i]);
			i++;
		}
		else if (isUse2[i] && !isUse1[j]) {
			printf("d %c\n", str1[j]);
			j++;
		}
		else if (!isUse2[i] && !isUse1[j]) {
			printf("m %c\n", str2[i]);
			i++;
			j++;
		}
		else if (isUse2[i] && isUse1[j]) {
			printf("c %c\n", str2[i]);
			i++;
			j++;
		}
	}

	while (i < strlen(str2)) {
		printf("a %c\n", str2[i]);
		i++;
	}
	while (j < strlen(str1)) {
		printf("d %c\n", str1[j]);
		j++;
	}

	free(str1);
	free(str2);
	str1 = NULL;
	str2 = NULL;

	return 0;
}
*/