#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001];
int n, m;

int TKNP1(int a[], int l, int r, int x) {
	int vitri = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] > x) r = m - 1;
		else if (a[m] < x) l = m + 1;
		else {
			vitri = m;
			r = m - 1;
		}
	}

	return  vitri;
}

int TKNP2(int a[], int l, int r, int x) {
	int vitri = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] > x) r = m - 1;
		else if (a[m] < x) l = m + 1;
		else {
			vitri = m;
			l = m + 1;
		}
	}

	return vitri;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int dem = 0;

	for (int i = 0; i < n; i++) {
		int x = TKNP1(a, i + 1, n - 1, m - a[i]);
		int y = TKNP2(a, i + 1, n - 1, m - a[i]);
		if (x != -1) dem += y - x + 1;
	}

	cout << dem << endl;

	return 0;

}

