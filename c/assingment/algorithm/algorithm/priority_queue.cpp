#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct board_node {
	int value;
	int value2;
};

struct compare {	//오름차순, true일 때 정렬 //정렬에서 compare은 false일 때 정렬
	bool operator()(board_node a, board_node b) {
		if (a.value2 == b.value2) return a.value > b.value;
		return a.value2 > b.value2;
	}
};

int main() {
	priority_queue< board_node, vector< board_node >, compare > pq;

	pq.push(board_node{ 1, 2 });	//node로 넣어주지 않으면 정렬되지 않는다
	pq.push(board_node{ 1, 3 });
	pq.push(board_node{ 1, 6 });
	pq.push(board_node{ 1, 7 });
	pq.push(board_node{ 1, 1 });
	pq.push(board_node{ 3, 2 });
	pq.push(board_node{ 1, 0 });
	
	while (pq.size() != 0) {
		cout << pq.top().value2;
		pq.pop();
	}

	return 0;
}