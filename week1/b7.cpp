#include <iostream>
#include <string>

using namespace std;

int main() {
    string P1, P2, T;

    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    size_t pos = 0;
    while ((pos = T.find(P1, pos)) != string::npos) {
        T.replace(pos, P1.length(), P2);
        pos += P2.length(); 
    }
    cout << T << endl;

    return 0;
}

