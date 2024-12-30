#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int denTa = b * b - 4 * a * c;
	if (denTa < 0) cout << "NO SOLUTION " << endl;
	else if (denTa == 0) {
		double x0 = (1.0) * (-1) * (b) / (2 * a);
		cout << fixed << setprecision(2) << x0 << endl;
	}
	else cout << fixed << setprecision(2) << (1.0) * ((-1 * b - sqrt(denTa))) / (2 * a) << " " << fixed << setprecision(2) << (1.0) * ((-1 * b + sqrt(denTa))) / (2 * a) << endl;

	return 0;
}

