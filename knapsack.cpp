#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;

    // Number of items
    cout << "Enter number of items: ";
    cin >> n;

    // Knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> weight(n);
    vector<int> value(n);

    // Input weights
    cout << "Enter weights of " << n << " items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    // Input values
    cout << "Enter values of " << n << " items: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // 0/1 Knapsack
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {

            // Don't take the item
            dp[i][w] = dp[i - 1][w];

            // Take the item if it fits
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    cout << "Maximum value = " << dp[n][capacity] << endl;

    return 0;
}
