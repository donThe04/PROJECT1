#include <iostream>
#include <vector>
#include <string>

using namespace std;

int computeHash(const string& s, int m) {
    const int BASE = 256; 
    int hashValue = 0;

    for (char ch : s) {
        hashValue = (hashValue * BASE + ch) % m;
    }
    return hashValue;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> results;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        results.push_back(computeHash(s, m));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}

