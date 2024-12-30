#include <iostream>
#include <string>
#include <sstream> 
#include <set>

using namespace std;

int main() {
    string line, full_text;

    while (getline(cin, line)) {
        full_text += line + " "; 
    }

    stringstream ss(full_text); 
    string word;
    int count = 0;

    while (ss >> word) {
        ++count;
    }
   
    cout << count << endl;

    return 0;
}

