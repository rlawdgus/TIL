#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct input {
	int weight;
	int height;
	int rank;
};

vector< input > info;

void scoring() {
	int info_size = info.size();

	for (int i = 0; i < info_size; i++) {
		for (int j = i + 1; j < info_size; j++) {
			if (info[i].weight > info[j].weight && info[i].height > info[j].height) info[j].rank++;
			else if (info[i].weight <info[j].weight && info[i].height < info[j].height) info[i].rank++;
		}
	}

	for (int i = 0; i < info_size; i++) cout << info[i].rank << ' ';
}

int main() {
	int N, w, h;

	cin >> N;
	while (N--) {
		cin >> w >> h;
		info.push_back({ w, h, 1 });
	}

	scoring();

	return 0;
}