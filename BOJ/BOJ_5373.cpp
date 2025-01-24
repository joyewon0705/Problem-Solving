#include <iostream>

int t, n;
char p, d;
char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
int cube[6][3][3];
int* r[6][4][3] = {
	{ { &cube[3][0][2], &cube[3][0][1], &cube[3][0][0] }, { &cube[5][0][2], &cube[5][0][1], &cube[5][0][0] },
	  { &cube[2][0][2], &cube[2][0][1], &cube[2][0][0] }, { &cube[4][0][2], &cube[4][0][1], &cube[4][0][0] } },
	{ { &cube[3][2][0], &cube[3][2][1], &cube[3][2][2] }, { &cube[4][2][0], &cube[4][2][1], &cube[4][2][2] },
	  { &cube[2][2][0], &cube[2][2][1], &cube[2][2][2] }, { &cube[5][2][0], &cube[5][2][1], &cube[5][2][2] } },
	{ { &cube[0][2][0], &cube[0][2][1], &cube[0][2][2] }, { &cube[5][0][0], &cube[5][1][0], &cube[5][2][0] },
	  { &cube[1][2][0], &cube[1][2][1], &cube[1][2][2] }, { &cube[4][2][2], &cube[4][1][2], &cube[4][0][2] } },
	{ { &cube[0][0][2], &cube[0][0][1], &cube[0][0][0] }, { &cube[4][0][0], &cube[4][1][0], &cube[4][2][0] },
	  { &cube[1][0][2], &cube[1][0][1], &cube[1][0][0] }, { &cube[5][2][2], &cube[5][1][2], &cube[5][0][2] } },
	{ { &cube[0][0][0], &cube[0][1][0], &cube[0][2][0] }, { &cube[2][0][0], &cube[2][1][0], &cube[2][2][0] },
	  { &cube[1][2][2], &cube[1][1][2], &cube[1][0][2] }, { &cube[3][2][2], &cube[3][1][2], &cube[3][0][2] }},
	{ { &cube[0][2][2], &cube[0][1][2], &cube[0][0][2] }, { &cube[3][0][0], &cube[3][1][0], &cube[3][2][0] },
	  { &cube[1][0][0], &cube[1][1][0], &cube[1][2][0] }, { &cube[2][2][2], &cube[2][1][2], &cube[2][0][2] }}
};

int getPlane(char p) {
	switch (p) {
		case 'U': return 0;
		case 'D': return 1;
		case 'F': return 2;
		case 'B': return 3;
		case 'L': return 4;
		case 'R': return 5;
	}
}

void setCube(int p, int d) {
	int tmp;
	
	if (d) {
		tmp = cube[p][0][0];
		cube[p][0][0] = cube[p][2][0];
		cube[p][2][0] = cube[p][2][2];
		cube[p][2][2] = cube[p][0][2];
		cube[p][0][2] = tmp;
		tmp = cube[p][0][1];
		cube[p][0][1] = cube[p][1][0];
		cube[p][1][0] = cube[p][2][1];
		cube[p][2][1] = cube[p][1][2];
		cube[p][1][2] = tmp;

		int tmp[] = { *r[p][0][0], *r[p][0][1], *r[p][0][2] };
		*r[p][0][0] = *r[p][3][0]; *r[p][0][1] = *r[p][3][1]; *r[p][0][2] = *r[p][3][2];
		*r[p][3][0] = *r[p][2][0]; *r[p][3][1] = *r[p][2][1]; *r[p][3][2] = *r[p][2][2];
		*r[p][2][0] = *r[p][1][0]; *r[p][2][1] = *r[p][1][1]; *r[p][2][2] = *r[p][1][2];
		*r[p][1][0] = tmp[0]; *r[p][1][1]= tmp[1]; *r[p][1][2] = tmp[2];
	}
	else {
		tmp = cube[p][0][0];
		cube[p][0][0] = cube[p][0][2];
		cube[p][0][2] = cube[p][2][2];
		cube[p][2][2] = cube[p][2][0];
		cube[p][2][0] = tmp;
		tmp = cube[p][0][1];
		cube[p][0][1] = cube[p][1][2];
		cube[p][1][2] = cube[p][2][1];
		cube[p][2][1] = cube[p][1][0];
		cube[p][1][0] = tmp;

		int tmp[] = { *r[p][0][0], *r[p][0][1], *r[p][0][2] };
		*r[p][0][0] = *r[p][1][0]; *r[p][0][1] = *r[p][1][1]; *r[p][0][2] = *r[p][1][2];
		*r[p][1][0] = *r[p][2][0]; *r[p][1][1] = *r[p][2][1]; *r[p][1][2] = *r[p][2][2];
		*r[p][2][0] = *r[p][3][0]; *r[p][2][1] = *r[p][3][1]; *r[p][2][2] = *r[p][3][2];
		*r[p][3][0] = tmp[0]; *r[p][3][1] = tmp[1]; *r[p][3][2] = tmp[2];
	}
}

int main(void) {

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		for (int a = 0; a < 6; a++) {
			for (int b = 0; b < 3; b++) {
				for (int c = 0; c < 3; c++) {
					cube[a][b][c] = a;
				}
			}
		}

		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			getchar();
			scanf("%c%c", &p, &d);
			setCube(getPlane(p), d == '+' ? 1 : 0);
		}

		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				printf("%c", color[cube[0][a][b]]);
			}
			printf("\n");
		}
	}

	return 0;
}