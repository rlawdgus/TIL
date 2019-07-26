#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][3];
int home[1001][3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		home[0][i] = arr[0][i];
	}
	for (int i = 0; i < n; i++) {
		home[i + 1][0] = min(home[i][1], home[i][2]) + arr[i + 1][0];
		home[i + 1][1] = min(home[i][0], home[i][2]) + arr[i + 1][1];
		home[i + 1][2] = min(home[i][0], home[i][1]) + arr[i + 1][2];
	}
	cout << min(min(home[n][0], home[n][1]), home[n][2]);
	return 0;
}