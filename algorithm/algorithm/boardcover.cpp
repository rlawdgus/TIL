#include <fstream>
#include <vector>
using namespace std;

vector< vector< char > > board;

int main() {
	ifstream inp("boardcover.inp");
	ofstream out("boardcover.out");

	int C, H, W;

	inp >> C;
	while (C--) {
		inp >> H >> W;


	}

	inp.close();
	out.close();
	return 0;
}