#include <fstream>
#include <algorithm>
using namespace std;

struct lamp {
	int start;
	int dest;
};

lamp lmp[100001];

bool compare_sort(const lamp& a, const lamp& b) {
	return a.start < b.start;
}

bool compare_upper_bound(const lamp& a, const lamp& b) {
	return a.start < b.start;
}

int cnt_lamp(int N, int L, int R) {
	int cnt = 0;
	while (L < R) {
		int index = -1;
		lamp tmp = { L, R };
		index = upper_bound(lmp, lmp + N, tmp, compare_upper_bound) - lmp;

		if (index == -1) return -1;	//맨 처음꺼를 써도 범위가 안되는 경우 (앞에가 남는다)

		int index_tmp = 0;
		bool check = false;
		for (int j = 0; j < index; j++) {
			if (L < lmp[j].dest) {
				if (lmp[index_tmp].dest < lmp[j].dest) {
					index_tmp = j;
				}
				check = true;
			}
		}

		cnt++;
		if (check) L = lmp[index_tmp].dest;
		else return -1;

		//if (index == -1) return -1;	//중간에 비는 경우

		
	}

	return cnt;
}

int main() {
	ifstream inp("light.inp");
	ofstream out("light.out");

	int N, T, L, R;

	inp >> N;
	for (int i = 0; i < N; i++) inp >> lmp[i].start >> lmp[i].dest;
	sort(lmp, lmp + N, compare_sort);

	inp >> T;
	while (T--) {
		inp >> L >> R;
		out << cnt_lamp(N, L, R) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}