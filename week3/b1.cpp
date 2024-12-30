#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<int> st;
    string command;

    while (true) {
        cin >> command;
        
        if (command == "PUSH") {
            int v;
            cin >> v;
            st.push(v);
        } 
        else if (command == "POP") {
            if (!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            } else {
                cout << "NULL" << endl;
            }
        } 
        else if (command == "#") {
            break;
        }
    }

    return 0;
}

