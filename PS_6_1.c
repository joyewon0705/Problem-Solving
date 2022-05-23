#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 101010
#define MAX 1010

typedef struct dot {
	int x;
	int y;
} dot;
dot list[N];
dot convexHull[N];
int c, cnt;
double tmp, max;
double dist(dot a, dot b);
long signArea(dot a, dot b, dot c);
int cmp1(const void* a, const void* b);
int cmp2(const void* a, const void* b);

int main(void) {

	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}

	qsort(list, c, sizeof(dot), cmp1);
	qsort(list + 1, c - 1, sizeof(dot), cmp2);

	convexHull[0] = list[0];
	convexHull[1] = list[1];
	cnt = 2;
	for (int i = 2; i < c; i++) {
		while ((cnt >= 2) && (signArea(convexHull[cnt - 1], convexHull[cnt], list[i]) <= 0)) {
			cnt--;
		}
		cnt++;
		convexHull[cnt] = list[i];
	}

	max = 0;
	for (int i = 0; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			tmp = dist(convexHull[i], convexHull[j]);
			if (max < tmp) max = tmp;
		}
	}

	printf("%lf", sqrt(max));

	return 0;
}

double dist(dot a, dot b) {
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long signArea(dot a, dot b, dot c) {
	return (a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
}

int cmp1(const void* a, const void* b) {
	dot aa = *(dot*)a;
	dot bb = *(dot*)b;
	return (aa.x > bb.x) || ((aa.x == bb.x) && (aa.y >= bb.y));
}

int cmp2(const void* a, const void* b) {
	long c = signArea(list[0], *(dot*)a, *(dot*)b);
	if (c > 0) return 0;
	if (c < 0) return 1;
	else {
		if (dist(list[0], *(dot*)a) < dist(list[0], *(dot*)b)) return 0;
		else return 1;
	}
}

// 참고: https://looview.tistory.com/10

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 101010
#define MAX 1010

typedef struct dot {
	int x;
	int y;
	double m;
} dot;
dot list[N], s = { 0, MAX, 0 };
dot convexHull[N];
int c, cnt;
double tmp, max;
int cmp(const void* a, const void* b);
int signArea(dot a, dot b, dot c);

int main(void) {

	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);

		// y좌표가 가작 작은 점 s 선택
		if (s.y > list[i].y) s = list[i];
	}

	// 점 s와의 기울기 구하기
	for (int i = 0; i < c; i++) {
		if (list[i].x == s.x) {
			if (list[i].y == s.y) list[i].m = -1;
			else list[i].m = MAX;
			continue;
		}
		else list[i].m = (double)(list[i].y - s.y) / (list[i].x - s.x);
		if (list[i].m < 0) list[i].m += MAX * 2;
	}

	// 기울기 기준 오름차순 정렬
	qsort(list, c, sizeof(dot), cmp);

	// convex hull 구하기
	convexHull[0] = list[0];
	convexHull[1] = list[1];
	cnt = 2;
	for (int i = 2; i < c; i++) {
		while ((cnt >= 2) && (signArea(convexHull[cnt - 1], convexHull[cnt], list[i]) < 0)) {
			cnt--;
		}
		cnt++;
		convexHull[cnt] = list[i];
	}

	// 가장 먼 거리 계산
	max = 0;
	for (int i = 0; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			dot a = convexHull[i];
			dot b = convexHull[j];
			tmp = (a.x - b.x) * (a.x - b.x);
			tmp += (a.y - b.y) * (a.y - b.y);
			if (max < tmp) max = tmp;
		}
	}

	printf("%lf", sqrt(max));

	return 0;
}

int cmp(const void* a, const void* b) {
	return (*(dot*)a).m > (*(dot*)b).m;
}

int signArea(dot a, dot b, dot c) {
	return (a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y);
}
*/

/*
#include <stdio.h>
#include <math.h>

#define N 101010

int c;
double max, tmp;
int location[N][2];

int main(void) {
	tmp = max = 0;

	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d %d", &location[i][0], &location[i][1]);
	}

	for (int i = 0; i < c; i++) {
		for (int j = i + 1; j < c; j++) {
			tmp = pow((location[i][0] - location[j][0]), 2);
			tmp += pow((location[i][1] - location[j][1]), 2);
			if (max < tmp) max = tmp;
		}
	}

	printf("%lf", sqrt(max));
		
	return 0;
}
*/