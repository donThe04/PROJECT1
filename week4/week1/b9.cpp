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
    int m = s.size() - 1;
    vector<int> v;

    if (s.size() != 10 || s[4] != '-' || s[7] != '-') {
        cout << "INCORRECT" << endl;
        return 0;
    }
    while (getline(ss, w, '-')) {
        for (int i = 0; i < w.size(); i++) {
            if (!isdigit(w[i])) {
                cout << "INCORRECT" << endl;
                return 0;
            }
        }
        v.push_back(stoi(w));
    }
    if(v[1] > 12 || v[1] < 1 || v[2] > 31 || v[2] < 1) cout <<"INCORRECT";
    else{
    	for(int x : v) cout << x <<" ";
	}

    return 0;
}

   

