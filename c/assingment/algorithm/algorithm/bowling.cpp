#include <fstream>
#include <vector>
using namespace std;

int strike(vector< vector< int > > board, int index) {
	if (board[index + 1][0] == 10) {
		if (index == 8) return 10 + board[index + 1][0] + board[index + 1][1];
		return 10 + board[index + 1][0] + board[index + 2][0];
	}
	else return 10 + board[index + 1][0] + board[index + 1][1];
}

int spare(vector< vector< int > > board, int index) {
	return 10 + board[index + 1][0];
}

int scoring(vector< vector< int > > board) {
	int result = 0;

	for (int i = 0; i < 9; i++) {	//9번 프레임까지
		if (board[i][0] == 10) result += strike(board, i);	//스트라이크
		else if (board[i][0] + board[i][1] == 10) result += spare(board, i);	//스페어
		else result += board[i][0] + board[i][1];	//오픈
	}

	if (board[9][0] == 10) result += 10 + board[9][1] + board[9][2];	//마지막프레임 스트라이크
	else if (board[9][0] + board[9][1] == 10) result += 10 + board[9][2];	//마지막프레임 스페어
	else result += board[9][0] + board[9][1];	//마지막프레임 오픈

	return result;
}

int main() {
	ifstream inp("bowling.inp");
	ofstream out("bowling.out");

	int T, num;
	vector< vector< int > > board(10);

	inp >> T;
	while (T--) {
		for (int i = 0; i < 9; i++) {	//9번 프레임까지
			inp >> num;
			board[i].push_back(num);

			if (num < 10) {
				inp >> num;
				board[i].push_back(num);
			}
		}

		inp >> num;
		board[9].push_back(num);

		inp >> num;
		board[9].push_back(num);

		if (board[9][0] + board[9][1] > 9) {	//마지막 프레임에서 스트라이크나 스페어일 때
			inp >> num;
			board[9].push_back(num);
		}

		out << scoring(board) << '\n';
		board.clear();
		board.resize(10);
	}

	inp.close();
	out.close();
	return 0;
}