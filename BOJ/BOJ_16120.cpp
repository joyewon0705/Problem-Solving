#include <iostream>
#include <cstring>
using namespace std;

#define LEN 1010101

int len, chk;
char str[LEN];

int main(void) {

	scanf("%s", str);

	len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') chk++;
		else if (chk >= 2 && str[i + 1] == 'P') {
			chk--;
			i++;
		}
		else {
			chk = 0;
			break;
		}
	}

	if (chk == 1) printf("PPAP");
	else printf("NP");

	return 0;
}