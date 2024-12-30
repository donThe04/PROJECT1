#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n, a[1000];
bool final = false;

void init() {
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
}

void sinh() {
	int i = n;
	while (i >= 1 && a[i] > a[i + 1]) {
		--i;
	}
	if (i == 0) final = true;
	else {
		int j = n;
		while (a[i] > a[j]) --j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);

	}
}

int main() {
	cin >> n;
	init();

	while (!final) {
		for (int i = 1; i <= n; i++) {
			cout << a[i] <<" ";
		}
		cout << endl;
		sinh();
	}

	return 0;
}

