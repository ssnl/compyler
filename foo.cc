
#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

#define CALL 0;
#define GOTO 1;
#define GTZ 2;
#define PUSH 3;
#define MOVE 4;
#define COMPL 5;
#define COMPG 6;
#define COMPLE 7;
#define COMPGE 8;
#define COMPE 9;
#define COMPNE 10;

class A {
public:
	A(int t) {
		x = t;
	}
	int x;
};

void test(A* a) {
	a->x = 10;
}

int main() {
	stringstream sstm;
	sstm << "hi" << 21;
	string result = sstm.str();
	cout << result << endl;
	return 0;
}

