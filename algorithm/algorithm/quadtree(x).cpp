#include <fstream>
#include <string>
using namespace std;

//인덱스 전역으로

string result;
int index = 0;

void quadtree(string str, int index) {
	if (str[index] == 'x') {
		result += str[index];
		
		index++; index++; index++;
		quadtree(str, index);
		index++;
		quadtree(str, index);
		index--; index--; index--;
		quadtree(str, index);
		index++;
		quadtree(str, index);
	}
	else result += str[index];
}

int main() {
	ifstream inp("quadtree.inp");
	ofstream out("quadtree.out");

	int C;
	string str;

	inp >> C;
	while (C--) {
		inp >> str;
		quadtree(str, 0);
		for (int i = 0; i < str.length(); i++) out << str[i];
		out << '\n';
	}

	inp.close();
	out.close();
	return 0;
}