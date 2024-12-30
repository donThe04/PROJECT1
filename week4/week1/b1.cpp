#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
	}

	string kt;
	cin >> kt;

	while (cin >> kt) {
		if (kt == "***") break;
		else if (kt == "find-max") cout << *max_element(v.begin(), v.end()) << endl;
		else if (kt == "find-min") cout << *min_element(v.begin(), v.end()) << endl;
		else if (kt == "find-max-segment") {
			int i, j; cin >> i >> j;
			--i; --j;
			cout << *max_element(v.begin() + i, v.begin() + j + 1) << endl;
		}
		else if (kt == "sum") {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += v[i];
			}
			cout << sum << endl;
		}
	}
}

