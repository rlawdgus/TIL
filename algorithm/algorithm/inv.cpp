#include<fstream>
#include<vector>
using namespace std;

vector< int > input;
vector< int > tmp;
long long cnt;

void Merge(int start, int mid, int end) {
	int s = start, m = mid, index = 0;

	while (s < mid && m < end) {
		if (input[s] < input[m])  tmp[index++] = input[s++];
		else if (input[s] > input[m]) {
			tmp[index++] = input[m++];
			cnt += mid - s;
		}
		else {
			tmp[index++] = input[m++];
		}
	}

	while (s < mid) {
		tmp[index++] = input[s++];
	}
	while (m < end) {
		tmp[index++] = input[m++];
	}

	for (int i = 0; i < end - start; ++i) {
		input[start + i] = tmp[i];
	}
}

void Merge_sort(int start, int end) {
	int mid = (start + end) / 2;
	if (start < mid) {
		Merge_sort(start, mid);
		Merge_sort(mid, end);
		Merge(start, mid, end);
	}
}

int main() {
	ifstream inp("inv.inp");
	ofstream out("inv.out");

	int T, N, n;
	inp >> T;
	while (T--) {
		cnt = 0;
		input.clear();
		tmp.clear();
		inp >> N;

		for (int i = 0; i < N; i++) {
			inp >> n;
			input.push_back(n);
		}
		tmp.resize(N);

		Merge_sort(0, N);
		out << cnt << "\n";
	}

	inp.close();
	out.close();
	return 0;
}