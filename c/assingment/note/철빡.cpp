#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#define MAX 100

using namespace std;

typedef struct { int x, y; }Point; // ��ǥ ����ü
typedef struct {
	bool exist; // �����ϴ��� ���� �ʴ���
	int count, cost; // �� k���� ���� ��� ��� ���� �ִ� ���
	vector<Point> path; // �ִ� ����� �������� ���� ���
}Element;
typedef struct {
	bool mark; // �� ������ X_Marking�� �ִ���
	vector<Element> kList; // �� K�� ���� ����Ʈ
}Board; // �� ���� ����ü

Board board[MAX][MAX]; // ����
int horizontal[MAX][MAX], vertical[MAX][MAX], maxK; // ���� ���� ��� ����Ʈ

void TableInit(int M, int N, int K, Element init) { // DP Table�� ����� ���� �ʱⰪ ����
	maxK = 0;
	board[0][0].kList.resize(K + 1, init);
	Point p = { 0, 0 };
	board[0][0].kList[0].path.push_back(p); // ��� ����
	board[0][0].kList[0].count = 1;
	board[0][0].kList[0].exist = true;
	if (board[0][0].mark) { // �� ������ ��ŷ�Ǿ�������
		board[0][0].kList[1] = board[0][0].kList[0];
		board[0][0].kList[0].exist = false;
		maxK++;
	}
	for (int i = 1; i < M; i++) {
		board[i][0].kList.resize(K + 1, init);
		for (int k = 0; k <= maxK; k++) {
			if (board[i - 1][0].kList[k].exist) { // �� ������ k�� ���ļ� ���� ��ΰ� ������,
				board[i][0].kList[k].cost = board[i - 1][0].kList[k].cost + vertical[i - 1][0];
				board[i][0].kList[k].exist = true;
				board[i][0].kList[k].count = board[i - 1][0].kList[k].count;
				board[i][0].kList[k].path = board[i - 1][0].kList[k].path;
				Point p = { i, 0 };
				board[i][0].kList[k].path.push_back(p); // ��� ����
				if (board[i][0].mark) { // �� ������ ��ŷ�Ǿ�������
					board[i][0].kList[k + 1] = board[i][0].kList[k];
					board[i][0].kList[k].exist = false;
					if (k == maxK) { maxK++; break; }
				}
			}
		}
	}
	for (int j = 1; j < N; j++) {
		board[0][j].kList.resize(K + 1, init);
		for (int k = 0; k <= maxK; k++) {
			if (board[0][j - 1].kList[k].exist) { // �� ������ k�� ���ļ� ���� ��ΰ� ������,
				board[0][j].kList[k].cost = board[0][j - 1].kList[k].cost + horizontal[0][j - 1];
				board[0][j].kList[k].exist = true;
				board[0][j].kList[k].count = board[0][j - 1].kList[k].count;
				board[0][j].kList[k].path = board[0][j - 1].kList[k].path;
				Point p = { 0, j };
				board[0][j].kList[k].path.push_back(p); // ��� ����
				if (board[0][j].mark) { // �� ������ ��ŷ�Ǿ�������
					board[0][j].kList[k + 1] = board[0][j].kList[k];
					board[0][j].kList[k].exist = false;
					if (k == maxK) { maxK++; break; }
				}
			}
		}
	}
}

void DP(int M, int N, int K) {
	Element init; // �ʱ�ȭ �� ����
	init.cost = 0; init.count = 0; init.exist = false; init.path.reserve(M * N);
	TableInit(M, N, K, init);
	/* ��� ���� ù° ������ �ʱ� �� ���� */
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < N; j++) {
			board[i][j].kList.resize(K + 1, init);
			for (int k = 0; k <= maxK; k++) {
				if (board[i - 1][j].kList[k].exist || board[i][j - 1].kList[k].exist) { // �� ������ k�� ���ļ� ���� ��ΰ� ������,
					board[i][j].kList[k].exist = true;
					if (board[i - 1][j].kList[k].exist && board[i][j - 1].kList[k].exist) { // k�� ���ļ� ���� ��ΰ� �� �� ������,
						board[i][j].kList[k].count = board[i - 1][j].kList[k].count + board[i][j - 1].kList[k].count;
						/* ������� k�� ���ļ� �� �� �ִ� ����� ���� �� ������ �� */
						if (board[i][j - 1].kList[k].cost + horizontal[i][j - 1] > board[i - 1][j].kList[k].cost + vertical[i - 1][j]) {
							// ���ʿ��� ���� ��찡 �� ����� ������
							board[i][j].kList[k].cost = board[i - 1][j].kList[k].cost + vertical[i - 1][j];
							board[i][j].kList[k].path = board[i - 1][j].kList[k].path;
						}
						else {
							// ���ʿ��� ���� ��찡 ����� �� ������
							board[i][j].kList[k].cost = board[i][j - 1].kList[k].cost + horizontal[i][j - 1];
							board[i][j].kList[k].path = board[i][j - 1].kList[k].path;
						}
					}
					else if (board[i - 1][j].kList[k].exist) { // �� �ʿ��� k�� ���ļ� �������� ���
						board[i][j].kList[k].cost = board[i - 1][j].kList[k].cost + vertical[i - 1][j];
						board[i][j].kList[k].count = board[i - 1][j].kList[k].count;
						board[i][j].kList[k].path = board[i - 1][j].kList[k].path;
					}
					else { // �� �ʿ��� k�� ���ļ� ���� ���
						board[i][j].kList[k].cost = board[i][j - 1].kList[k].cost + horizontal[i][j - 1];
						board[i][j].kList[k].count = board[i][j - 1].kList[k].count;
						board[i][j].kList[k].path = board[i][j - 1].kList[k].path;
					}
					Point p = { i, j };
					board[i][j].kList[k].path.push_back(p); // ��� ����
					if (board[i][j].mark) { // �� ������ ��ŷ�Ǿ�������
						board[i][j].kList[k + 1] = board[i][j].kList[k];
						board[i][j].kList[k].exist = false;
						if (k > 0) if (board[i - 1][j].kList[k - 1].exist || board[i][j - 1].kList[k - 1].exist)
								board[i][j].kList[k].exist = true;
						if (k == maxK) { maxK++; break; }
					}
				}
			}
		}
	}
}

int main() {
	ifstream inp("input.txt");
	ofstream out("output.txt");
	int testcase;
	inp >> testcase;
	for (int T = 1; T <= testcase; T++) {
		int M, N, K;
		inp >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			Point p;
			inp >> p.x >> p.y;
			board[p.x][p.y].mark = true;
		}
		for (int i = 0; i < M; i++) for (int j = 0; j < N - 1; j++) inp >> horizontal[i][j];
		for (int i = 0; i < M - 1; i++) for (int j = 0; j < N; j++) inp >> vertical[i][j];
		DP(M, N, K);
		out << "Test Case No:" << T << '\n';
		for (int k = 0; k <= K; k++) {
			if (board[M - 1][N - 1].kList[k].exist) {
				out << "k:" << k << " count:" << board[M - 1][N - 1].kList[k].count << " cost:" << board[M - 1][N - 1].kList[k].cost << '\n';
				for (int i = 0; i < board[M - 1][N - 1].kList[k].path.size(); i++) {
					out << '(' << board[M - 1][N - 1].kList[k].path[i].x << ',' << board[M - 1][N - 1].kList[k].path[i].y << ')';
					if (i != board[M - 1][N - 1].kList[k].path.size() - 1)
						out << "->";
				}
				out << '\n';
			}
		}
		out << '\n';
		memset(board, 0, sizeof(board)); memset(horizontal, 0, sizeof(horizontal)); memset(vertical, 0, sizeof(vertical));
	}
	inp.close();
	out.close();
	return 0;
}