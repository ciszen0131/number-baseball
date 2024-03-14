#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int answer[3] = { 0, 0, 0 };
int strike(int order, int my_num[3], int answer[3]);

void init() {
	int random = 0;
	int overlap1 = 1;
	int overlap2 = 0;

	while (overlap1 == 1) {
		for (int i = 0; i < 3; i++) {
			random = rand() % 10;
			answer[i] = random;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < i; j++) {
				if (answer[j] == answer[i]) {
					overlap2 = 1;
				}
			}
		}
		if (overlap2 == 0) {
			overlap1 = 0;
		}
		else {
			overlap2 = 0;
		}
	}
}

int main() {
	srand(time(NULL));
	int first_num = 0;
	int second_num = 0;
	int third_num = 0;
	int b = 0;
	int s = 0;
	int o = 0;

	init();
	printf("%d, %d, %d\n", answer[0], answer[1], answer[2]);

	for (int progress = 0; progress < 9; progress++) {

		printf("숫자 3개를 입력하세요.\n");
		scanf("%d%d%d", &first_num, &second_num, &third_num);
		int my_num[3] = { first_num, second_num, third_num };

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (my_num[i] == answer[j]) {
					b++;
					// strike
					if (i==j) {
						b--;
						s++;
					}
				}
				else {
					o++;
				}
			}
		}

		o = o - (s * 2) - (b * 2);
		o = o / 3;

		printf("s = %d\nb = %d\n0 = %d\n", s, b, o);

		if (s == 3) {
			break;
		}
	}

	if (s == 3) {
		printf("통과하셨습니다.");
	}
	else {
		printf("실패하셨습니다. 정답 : %d %d %d", answer[0], answer[1], answer[2]);
	}
	return 0;
}
