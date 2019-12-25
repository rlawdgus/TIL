#include <iostream>
using namespace std;

int main() {
	int A, B, V, tmp;
	cin >> A >> B >> V;

	cout << (V - B - 1) / (A - B) + 1;

	return 0;
}