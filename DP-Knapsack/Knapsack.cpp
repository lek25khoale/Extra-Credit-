#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<vector<int>> dp;
 
// maximum benefit achievable keeping weight <= max_weight
int knapsack(int max_weight, vector<int>& values, vector<int>& weights) {
    int n = weights.size();
    dp.assign(n + 1, vector<int>(max_weight + 1, 0));
 
    for (int item = 1; item <= n; ++item) {
        int item_weight = weights[item - 1];
        int item_value  = values[item - 1];
 
        for (int w = 0; w <= max_weight; ++w) {
            dp[item][w] = dp[item - 1][w];
 
            if (item_weight <= w) {
                int include = item_value + dp[item - 1][w - item_weight];
                if (include > dp[item][w])
                    dp[item][w] = include;
            }
        }
    }
 
    return dp[n][max_weight];
}
 
// trace back through dp to find which items were taken
void find_items(vector<int>& weights, int max_weight, vector<int>& taken) {
    int w = max_weight;
    for (int i = dp.size() - 1; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            taken.push_back(i);
            w -= weights[i - 1];
        }
    }
    reverse(taken.begin(), taken.end());
}
 
int main() {
    vector<int> values  = {1, 6, 18, 22, 28};
    vector<int> weights = {1, 2,  5,  6,  7};
    int max_weight = 11;
 
    cout << "Items:\n";
    for (int i = 0; i < (int)values.size(); ++i)
        cout << "  " << i + 1 << ": weight=" << weights[i] << " value=" << values[i] << "\n";
 
    cout << "\nCapacity: " << max_weight << "\n";
 
    int result = knapsack(max_weight, values, weights);
 
    vector<int> taken;
    find_items(weights, max_weight, taken);
 
    cout << "\nItems taken:\n";
    int total_weight = 0, total_value = 0;
    for (int i : taken) {
        cout << "  " << i << ": weight=" << weights[i - 1] << " value=" << values[i - 1] << "\n";
        total_weight += weights[i - 1];
        total_value  += values[i - 1];
    }
 
    cout << "\nTotal weight: " << total_weight << "\n";
    cout << "Maximum benefit: " << total_value << "\n";
 
    return 0;
}