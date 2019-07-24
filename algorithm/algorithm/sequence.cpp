#include <fstream>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

void input(int n, ifstream &inp, vector< int > &U) {
	int num;
	while (n--) {
		inp >> num;
		U.push_back(num);
	}
}

void print(vector< int > &result, ofstream &out) {
	int size = result.size();
	for (int i = 0; i < size; i++) out << result[i] << '\n';
}

bool compare(int a, int b) { return a < b; }

void sequence(vector< int > &S, vector< int > &C, vector< int > &result, ofstream &out) {
	sort(S.begin(), S.end(), compare);
	
	int n = S.size();
	for (int i = n - 1; i >= 0; i--) {
		result[i] = S[C[i]];
		S.erase(S.begin() + C[i], S.begin() + C[i] + 1);
	}

	print(result, out);
}

int main() {
	double start = time(NULL);

	ifstream inp("sequence.inp");
	ofstream out("sequence.out");

	int n;
	vector< int > S;
	vector< int > C;
	vector< int > result;
	
	inp >> n;
	input(n, inp, S);
	input(n, inp, C);
	result.resize(n);
	sequence(S, C, result, out);

	inp.close();
	out.close();

	double end = time(NULL);
	cout << end - start;
	return 0;
}