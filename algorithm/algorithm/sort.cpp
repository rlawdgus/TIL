#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int value;
	int value2;
};

vector< node > board;

bool compare(node a, node b) {	//false�� �� ����
	if (a.value2 == b.value2) return a.value < b.value;	//��������
	return a.value2 < b.value2;
}

int main() {
	board.push_back({ 1, 1 });
	board.push_back({ 1, 5 });
	board.push_back({ 1, 6 });
	board.push_back({ 1, 9 });
	board.push_back({ 1, 2 });
	board.push_back({ 1, 10 });
	board.push_back({ 3, 6 });
	board.push_back({ 5, 1 });

	sort(board.begin(), board.end(), compare);

	return 0;
}