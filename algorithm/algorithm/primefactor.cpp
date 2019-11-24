#include <fstream>
#include <vector>
using namespace std;

vector< int > input;

int arr_sum(vector< int > arr) {
	int result = 0;
	for (int i = 0; i < arr.size(); i++) result += arr.at(i);

	return result;
}

int main() {
	ifstream inp("primefactor.inp");
	ofstream out("primefactor.out");

	int T, num;

	inp >> T;

	while (T--) {
		inp >> num;

		for (int i = 2; i <= num; i++) {
			if (num % i == 0) {
				input.push_back(i);
				num /= i;
				i = 1;
			}
		}

		if (input.size() == 1) out << "Prime Number" << '\n';
		else out << arr_sum(input) << '\n';

		input.clear();
	}

	inp.close();
	out.close();
	return 0;
}