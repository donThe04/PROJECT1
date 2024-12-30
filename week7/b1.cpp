#include <bits/stdc++.h>
using namespace std;

struct information
{
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
    
};
vector<information> transaction;
unordered_map<string, int> account;
vector<int> prefixSum;
set<string> list_sort;
unordered_map<string, vector<string>> graphs;
void input(){
    string account1,account2,ATM,TIME_POINT;
    int Money;
    while(cin >> account1 && account1 != "#"){
        cin >> account2 >> Money >> TIME_POINT >> ATM;
        information info={account1,account2,Money,TIME_POINT,ATM};
        transaction.push_back(info);
        // Tính t?ng ti?n du?c chuy?n t? tài kho?n account 1
        account[account1] += Money;
        // S?p x?p các account theo th? t? t? di?n bao g?m c? g?i di và nh?n
        list_sort.insert(account1);
        list_sort.insert(account2);
    }
    // Hàm c?ng d?n
        prefixSum.resize(transaction.size());
        prefixSum[0] = transaction[0].money;
        for(size_t i=1; i<transaction.size(); i++){
            prefixSum[i] = prefixSum[i-1] + transaction[i].money;
        }
}
int number_transactions(){
    return transaction.size();
}
int total_money_transaction(){
    return prefixSum.back();
}
void list_sorted_accounts(){
    for(string account : list_sort){
        cout << account <<" ";
    }
}
int total_money_transaction_from(string &acc){
    return account[acc];
}
void buildGraph(){
    for(information acc : transaction){
        graphs[acc.from_account].push_back(acc.to_account);
    }
}
bool dfs(string &acc1, string &acc2, int depth, int k, unordered_set<string>& visited){
    if(depth == k){
        return acc2==acc1;
    }
    // Luu dã du?c tham
    visited.insert(acc2);

    for(auto& curr : graphs[acc2]){
        // N?u tài kho?n chua tham ho?c dó là tài kho?n ban d?u khi d?t d? dài k-
        if(!visited.count(curr) || (curr == acc1 && depth +1 == k)){
            if(dfs(acc1,curr,depth+1,k,visited)){
                return true;
            }
        }
    }
    // H?y dánh d?u tài kho?n hi?n t?i khi quay l?i
    visited.erase(acc2);
    return false;
}
int inspect_cycle(string acc, int k){
    unordered_set<string> visited;
    return dfs(acc, acc, 0, k, visited) ? 1 : 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    string command;
    string tmp1;
    int k;
    buildGraph();
    while (cin >> command && command != "#") {
        if (command == "?number_transactions") {
            cout << number_transactions() << endl;
        } else if (command == "?total_money_transaction") {
            cout << total_money_transaction() << endl;
        } else if (command == "?list_sorted_accounts") {
            list_sorted_accounts();
            cout << endl;
        } else if (command == "?total_money_transaction_from") {
            cin >> tmp1;
            cout << total_money_transaction_from(tmp1) << endl;
        } else if (command == "?inspect_cycle") {
            cin >> tmp1 >> k;
            cout << inspect_cycle(tmp1, k) << endl;
        }
    }
}

