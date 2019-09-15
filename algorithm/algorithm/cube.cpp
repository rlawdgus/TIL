#include <fstream>
#include <string>
using namespace std;

enum {
	TOP, FRONT, LEFT, RIGHT, BACK, BOTTOM
};

void roll(string &cube) {
	char tmp = cube[TOP];
	cube[TOP] = cube[BACK];
	cube[BACK] = cube[BOTTOM];
	cube[BOTTOM] = cube[FRONT];
	cube[FRONT] = tmp;
}

void rotate(string& cube) {
	char tmp = cube[FRONT];
	cube[FRONT] = cube[RIGHT];
	cube[RIGHT] = cube[BACK];
	cube[BACK] = cube[LEFT];
	cube[LEFT] = tmp;
}

void compare(string& cube, string& cube2, int size, string& output) {
	for (int i = 0, j = 0; i < size;) {
		if (cube == cube2) { output = "TRUE\n"; break; }
		else if (j < 3) { rotate(cube2); j++; }
		else if (j == 3) { roll(cube2); j = 0; i++; }
	}
}

int main() {
	ifstream inp("cube.inp");
	ofstream out("cube.out");

	string red = "rrrrrrrrrrrr";
	string green = "gggggggggggg";
	string blue = "bbbbbbbbbbbb";

	string input;
	while (1) {
		inp >> input;

		string cube = input.substr(0, 6);
		string cube2 = input.substr(6);

		string output = "FALSE\n";
		compare(cube, cube2, 3, output);
		
		roll(cube2);
		roll(cube2); 

		if (output == "FALSE\n") {
			compare(cube, cube2, 1, output);
			roll(cube2);
			roll(cube2);
		}

		if (output == "FALSE\n") compare(cube, cube2, 2, output);

		out << output;

		if (input == red || input == green || input == blue) {
			inp.close();
			out.close();
			return 0;
		}
	}
}