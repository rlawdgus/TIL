#include<iostream>
#include<string>
using namespace std;

string input;
string::iterator pointer;

bool isFactor();
bool isFinish();
bool Goal();
bool Expr();
bool Eprime();
bool Term();
bool Tprime();
bool Factor();

bool isFactor() {
	return (*pointer >= '0' && *pointer <= '9') || (*pointer >= 'a' && *pointer <= 'z') || (*pointer >= 'A' && *pointer <= 'Z');
}

bool isFinish() {
	return pointer == input.end();
}

bool Goal() {
	return Expr() && pointer == input.end();
}

bool Expr() {
	if (!Term()) return false;
	else if (isFinish()) return true;

	return Eprime();
}

bool Eprime() {
	if (*pointer == '+' || *pointer == '-') {
		if (pointer != input.end()) pointer++;

		if (!Term()) return false;
		else if (isFinish()) return true;

		return Eprime();
	}
	return true;
}

bool Term() {
	if (!Factor()) return false;
	else if (isFinish()) return true;

	return Tprime();
}

bool Tprime() {
	if (*pointer == '*' || *pointer == '/') {
		if (pointer != input.end()) pointer++;

		if (!Factor()) return false;
		else if (isFinish()) return true;

		return Tprime();
	}
	return true;
}

bool Factor() {
	if (isFinish()) return false;
	else if (*pointer == '(') {
		if (pointer != input.end()) pointer++;

		if (!Expr()) return false;
		else if (isFinish()) return false;
		else if (*pointer != ')') return false;
	}
	else if (!isFactor()) return false;

	if (pointer != input.end()) pointer++;
	return true;
}

int main() {
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			input.erase(i--, 1);
		}
	}
	pointer = input.begin();

	cout << (Goal() ? "Good" : "Error") << '\n';
	return 0;
}