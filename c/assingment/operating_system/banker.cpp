#include <fstream>
#include <string>
#include <vector>
#define MAX 51
using namespace std;

typedef struct query {
	string qry;
	int process_num;
	int req[MAX];
}query;
vector< query > ready_queue;

void input(int n, int m);
void print(int m);
void release(int num, int n, int m);
void request(string qry, int num, int n, int m);
bool req_check(int n, int m);
bool avl_check(int m);
bool exceed(int n, int m);

ifstream inp("banker.inp");
ofstream out("banker.out");

int available[MAX];
int maximum[MAX][MAX];
int allocation[MAX][MAX];
int need[MAX][MAX];
int tmp[MAX];

int main() {
	int n, m;
	inp >> n >> m;

	input(n, m);

	string qry;
	int num;
	while (1) {
		inp >> qry;

		if (qry == "quit") {
			inp.close();
			out.close();
			return 0;
		}

		else if (qry == "release") { inp >> num; release(num, n, m); }
		else { inp >> num; request(qry, num, n, m); }
	}
}

void input(int n, int m) {
	for (int i = 0; i < m; i++) inp >> available[i];	//avl

	for (int i = 0; i < n; i++) {	//max
		for (int j = 0; j < m; j++) inp >> maximum[i][j];
	}

	for (int i = 0; i < n; i++) {	//allo, need
		for (int j = 0; j < m; j++) {
			inp >> allocation[i][j];
			available[j] -= allocation[i][j];
			need[i][j] = maximum[i][j] - allocation[i][j];
		}
	}
}

void print(int m) {
	for (int i = 0; i < m; i++) out << available[i] << ' ';
	out << '\n';
}

void release(int num, int n, int m) {
	for (int i = 0; i < m; i++) inp >> tmp[i];

	for (int i = 0; i < m; i++) {	//선 릴리즈
		available[i] += tmp[i];
		need[num][i] += tmp[i];
		allocation[num][i] -= tmp[i];
	}

	for (int p = 0; p < ready_queue.size(); p++) {	//레디큐 확인
		int p_num = ready_queue[p].process_num;
		for (int i = 0; i < m; i++) {	//선 리퀘스트
			available[i] -= ready_queue[p].req[i];
			need[p_num][i] -= ready_queue[p].req[i];
			allocation[p_num][i] += ready_queue[p].req[i];
		}

		if (avl_check(m) || req_check(n, m) || exceed(p_num, m)) { //복구
			for (int i = 0; i < m; i++) {
				available[i] += ready_queue[p].req[i];
				need[p_num][i] += ready_queue[p].req[i];
				allocation[p_num][i] -= ready_queue[p].req[i];
			}
		}
		else {	//큐 처리
			ready_queue.erase(ready_queue.begin() + p, ready_queue.begin() + p + 1);
			p--;
		}
	}

	print(m);
}

void request(string qry, int num, int n, int m) {
	for (int i = 0; i < m; i++) inp >> tmp[i];

	for (int i = 0; i < m; i++) {	//선 리퀘스트
		available[i] -= tmp[i];
		need[num][i] -= tmp[i];
		allocation[num][i] += tmp[i];
	}

	if (avl_check(m) || req_check(n, m) || exceed(n, m)) { //복구
		for (int i = 0; i < m; i++) {
			available[i] += tmp[i];
			need[num][i] += tmp[i];
			allocation[num][i] -= tmp[i];
		}

		query q;	//push
		q.qry = qry;
		q.process_num = num;
		for (int i = 0; i < m; i++) q.req[i] = tmp[i];

		ready_queue.push_back(q);
	}

	print(m);
}

bool avl_check(int m) {	//avaliable에 음수가 있다: true
	for (int i = 0; i < m; i++) {
		if (available[i] < 0) return true;
	}
	return false;
}

bool req_check(int n, int m) {	//unsafe: true
	for (int i = 0; i < n; i++) {
		int cnt = 0;

		for (int j = 0; j < m; j++) {
			if (available[j] + allocation[i][j] >= maximum[i][j]) cnt++;
		}

		if (cnt == m) return false;
	}
	return true;

}

bool exceed(int n, int m) {	//need에 음수가 있다: true
	for (int i = 0; i < m; i++) {
		if (need[n][i] < 0) return true;
	}
	return false;
}