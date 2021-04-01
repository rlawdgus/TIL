#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void input(ifstream& inp, vector< int >& shape, int p) {
	int N;
	for (int i = 0; i < p; i++) {
		inp >> N;
		shape.push_back(N);
	}
}

void polygon(vector< int >& shape, vector< int >& shape2) {
	int size = shape.size();
	for (int i = 0, j = 0; i < size;) {

	}
}

int main() {
	double start = time(NULL);

	ifstream inp("polygon.inp");
	ofstream out("polygon.out");

	int T, p;
	vector< int > shape, shape2;

	inp >> T;
	while (T--) {
		inp >> p;
		input(inp, shape, p);
		input(inp, shape2, p);



		shape.clear();
		shape.clear();
	}

	inp.close();
	out.close();

	double end = time(NULL);
	cout << end - start;
	return 0;
}