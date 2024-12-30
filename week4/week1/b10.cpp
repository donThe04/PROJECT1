#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	stringstream ss(s);
	string w;
	vector<int> v;
	if (s.size() != 8 || s[2] != ':' || s[5] != ':') {
		cout << "INCORRECT ";
	}
	else {
		while (getline(ss, w, ':')) {
			v.push_back(stoi(w));
		}
		if (v[0] < 0 || v[0] > 23 || v[1] < 0 || v[1] > 59 || v[2] < 0 || v[2] > 59) {
			cout << "INCORRECT ";
		}
		else {
			int tg = v[0] * 3600 + v[1] * 60 + v[2];
			cout << tg << endl;
		}

	}
	return 0;
} 

