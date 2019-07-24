#include <fstream>
using namespace std;

int memory[93];

int fibonachi(int num) {
	if (num < 2) return num;

	if (memory[num]) return memory[num];
	else {
		memory[num] = fibonachi(num - 1) + fibonachi(num - 2);
		return memory[num];
	}
}

int main() {
	ifstream inp("fibonachi.inp");
	ofstream out("fibonachi.out");

	int num;
	while (1) {
		inp >> num;
		if (num == 100) {
			inp.close();
			out.close();
			return 0;
		}

		out << fibonachi(num) << '\n';
	}
}