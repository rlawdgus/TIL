#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector< vector< int > > board;
queue< int > BFS_visit;
vector< bool > visited(6);

bool compare(int a, int b) {
	return a < b;
}

void reset() {
	for (int i = 0; i < 6; i++) visited[i] = false;
}

void DFS(int start) {	//끊어진 경우 예외처리 해줘야 한다
	visited[start] = true;
	cout << start << ' ';

	int cycle = board[start].size();
	for (int i = 0; i < cycle; i++) {
		if (!visited[board[start][i]]) DFS(board[start][i]);
	}
}

void BFS(int start) {	//끊어진 경우 예외처리 해줘야 한다
	visited[start] = true;
	BFS_visit.push(start);
	start = BFS_visit.front();

	while (BFS_visit.size()) {
		cout << start << ' ';

		int cycle = board[start].size();
		BFS_visit.pop();

		for (int i = 0; i < cycle; i++) {
			if (!visited[board[start][i]]) {
				BFS_visit.push(board[start][i]);
				visited[board[start][i]] = true;
			}
		}
		
		if(BFS_visit.size()) start = BFS_visit.front();
	}
}

int main() {
	board.resize(6);

	board[0].push_back(4);
	board[0].push_back(1);

	board[1].push_back(0);
	board[1].push_back(3);
	board[1].push_back(2);

	board[2].push_back(1);
	board[2].push_back(5);

	board[3].push_back(1);

	board[4].push_back(0);
	board[4].push_back(5);

	board[5].push_back(2);
	board[5].push_back(4);

	for (int i = 0; i < 6; i++) sort(board[i].begin(), board[i].end(), compare);

	DFS(0);
	cout << "\n\n";

	reset();

	BFS(0);
	cout << "\n\n";

	return 0;
}