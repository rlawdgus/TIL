#include <stdio.h>
#pragma warning(disable : 4996)

typedef struct Card{		//아직 실패
	long long num; //카드수
	int cnt;
}Card;

Card card[1000000];
int card_cnt;

void insert(long long num) {
	int i = 0;
	for (; i < card_cnt; i++) {
		if (card[i].num == num) {
			card[i].cnt++;
			return;
		}
	}

	card[i].num = num;
	card[i].cnt++;
	card_cnt++;

	return;
}

int main() {
	int N;
	long long num;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &num);
		insert(num);
	}

	Card max = card[0];

	for (int i = 0; i < card_cnt; i++) {
		if (card[i].cnt > max.cnt)
			max = card[i];

		else if (card[i].cnt == max.cnt) {
			if (card[i].num < max.num)
				max = card[i];
		}
	}

	printf("%lld\n", max.num);

	return 0;
}