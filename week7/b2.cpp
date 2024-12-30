#include <bits/stdc++.h>
using namespace std;

struct Information {
    string CustomerID;
    string ProductID;
    int Price;
    string ShopID;
    int TimePointInSeconds; // Store time as seconds for faster comparison
};

vector<Information> customer;
unordered_map<string, int> shopRevenue;
unordered_map<string, unordered_map<string, int>> customerShopConsumption;
vector<int> prefixSum; // Prefix sum array for total revenue up to each transaction

int timeToSeconds(const std::string& timeStr) {
    int hours, minutes, seconds;
    sscanf(timeStr.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

void input() {
    string customerid, productid, shopid, timepoint;
    int price;
    while (cin >> customerid && customerid != "#") {
        cin >> productid >> price >> shopid >> timepoint;
        int timeInSeconds = timeToSeconds(timepoint);
        
        Information info = {customerid, productid, price, shopid, timeInSeconds};
        customer.push_back(info);
        
        // Update shop revenue and customer-shop consumption maps
        shopRevenue[shopid] += price;
        customerShopConsumption[customerid][shopid] += price;
    }

    // Sort transactions by time for efficient range queries
    sort(customer.begin(), customer.end(), [](const Information &a, const Information &b) {
        return a.TimePointInSeconds < b.TimePointInSeconds;
    });

    // Build the prefix sum array
    prefixSum.resize(customer.size());
    prefixSum[0] = customer[0].Price;
    for (size_t i = 1; i < customer.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + customer[i].Price;
    }
}

int total_number_orders() {
    return customer.size();
}

int total_revenue() {
    return prefixSum.back(); // Total revenue is the last element of prefix sum
}

int revenue_of_shop(const string& shopid) {
    return shopRevenue[shopid];
}

int total_consume_of_customer_shop(const string& cusID, const string& shopid) {
    return customerShopConsumption[cusID][shopid];
}

int total_revenue_in_period(const string& fromTime, const string& toTime) {
    int fromSeconds = timeToSeconds(fromTime);
    int toSeconds = timeToSeconds(toTime);

    // Find the first transaction at or after fromSeconds
    auto lower = lower_bound(customer.begin(), customer.end(), fromSeconds,
        [](const Information &info, int time) {
            return info.TimePointInSeconds < time;
        });

    // Find the last transaction at or before toSeconds
    auto upper = upper_bound(customer.begin(), customer.end(), toSeconds,
        [](int time, const Information &info) {
            return time < info.TimePointInSeconds;
        });

    // If no transactions are in range, return 0
    if (lower == customer.end() || upper == customer.begin()) return 0;

    int startIdx = distance(customer.begin(), lower);
    int endIdx = distance(customer.begin(), upper) - 1;

    // Calculate revenue within the range using the prefix sum array
    if (startIdx > endIdx) return 0; // No valid transactions within range
    return prefixSum[endIdx] - (startIdx > 0 ? prefixSum[startIdx - 1] : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    string command;
    string tmp1, tmp2;
    while (cin >> command && command != "#") {
        if (command == "?total_number_orders") {
            cout << total_number_orders() << endl;
        } else if (command == "?total_revenue") {
            cout << total_revenue() << endl;
        } else if (command == "?revenue_of_shop") {
            cin >> tmp1;
            cout << revenue_of_shop(tmp1) << endl;
        } else if (command == "?total_consume_of_customer_shop") {
            cin >> tmp1 >> tmp2;
            cout << total_consume_of_customer_shop(tmp1, tmp2) << endl;
        } else if (command == "?total_revenue_in_period") {
            cin >> tmp1 >> tmp2;
            cout << total_revenue_in_period(tmp1, tmp2) << endl;
        }
    }

    return 0;
}

