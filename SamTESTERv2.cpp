// SamTESTER v1.1
// Author: Saman Mahdanian
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

bool same();
void remove_profile();

int main() {
	int n;
	cout << "\n\nWelcome To SamTESTER v2\nYou Will Need checker.cpp, cprog.cpp and generator.cpp\n";
	cout << "Please make Sure that tester and 3 files are in SAME directory\n";
	cout << "\nHow many test case do you want to generate and test?\nn = " << flush;
	cin >> n; cout << endl;
	system ("g++ checker.cpp -std=c++11 -O2 -o check.out");
	system ("g++ cprog.cpp -std=c++11 -O2 -o result.out");
	system ("g++ generator.cpp -std=c++11 -O2 -o gen.out");
	system ("echo > check_ans.txt");
	system ("echo > result_ans.txt");
	system ("echo > test_case.txt");
	for (int i = 0; i < n; i++) {
		cout << "TESTING test #" << i + 1 << ": " << flush;
		system("rm check_ans.txt");
		system("rm result_ans.txt");
		system("rm test_case.txt");
		cout << "                  \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" << flush;
		system("./gen.out > test_case.txt"); cout << '~' << flush;
		system("./check.out < test_case.txt > check_ans.txt"); cout << '~' << flush;
		system("./result.out < test_case.txt > result_ans.txt"); cout << '~' << flush;
		if (!same()) {
			cout << "Program TEST RESULT: WrongAnswer" << endl;
			cout << "Verdict: test case found! (saved: test_case.txt)" << endl;
			remove_profile();
			return 0;
		} else
			cout << "Passed" << flush << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	}
	remove_profile();
	system("rm test_case.txt");
	cout << "\nProgram TEST RESULT: Passed" << endl;
}

void remove_profile() {
	system ("rm check.out");
	system ("rm result.out");
	system ("rm gen.out");
	system("rm check_ans.txt");
	system("rm result_ans.txt");
}

bool same() {
	ifstream stream1("check_ans.txt");
	ifstream stream2("result_ans.txt");
	string s, t;
	int num = 0;
	while ((stream1 >> s) && (stream2 >> t)) {
		num++;
		if (s != t) {
			cout << num << "\n";
			return false;
		}
	}
	return true;
}

// SamMHD :: Jan7-2019 :: Another Start to doing something new...
