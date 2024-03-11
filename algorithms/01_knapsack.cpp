#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// For each item in the knapsack
struct Item {
    int index;
    int profit;
    int weight;
};

// Comparator function for items
bool compareItems(const Item &a, const Item &b) {
    return (double) a.profit / a.weight > (double) b.profit / b.weight;
}

// Function to evaluate the 0/1 knapsack optimal answer
void knapsack_FIFO_branch_and_bound(int W, const vector<Item> &items) {
    int n = items.size();
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);

    int maxProfit = 0;
    vector<int> maxSubset;
    priority_queue<vector<int>> pq;
    pq.push({0, 0, 0}); // Initialize with the root node: weight, level, profit

    while (!pq.empty()) {
        int weight = pq.top()[0];
        int level = pq.top()[1];
        int profit = pq.top()[2];
        pq.pop();

        // If we find a new maximum profit, update maxProfit and maxSubset
        if (level > 0 && weight <= W && profit > maxProfit) {
            maxProfit = profit;
            maxSubset.clear();
            int tempWeight = W;
            for (int i = level - 1; i >= 0; i--) {
                if (tempWeight - sortedItems[i].weight >= 0) {
                    maxSubset.push_back(sortedItems[i].index);
                    tempWeight -= sortedItems[i].weight;
                }
            }
            reverse(maxSubset.begin(), maxSubset.end());
        }

        if (level < n) {
            Item item = sortedItems[level];
            int newWeight = weight + item.weight;
            int newProfit = profit + item.profit;
            if (newWeight <= W && newProfit > maxProfit) {
                maxProfit = newProfit;
                maxSubset.clear();
                int tempWeight = W;
                for (int i = level; i >= 0; i--) {
                    if (tempWeight - sortedItems[i].weight >= 0) {
                        maxSubset.push_back(sortedItems[i].index);
                        tempWeight -= sortedItems[i].weight;
                    }
                }
                reverse(maxSubset.begin(), maxSubset.end());
            }
            vector<int> newNode = {newWeight, level + 1, newProfit};
            pq.push(newNode);
            vector<int> sameNode = {weight, level + 1, profit};
            pq.push(sameNode);
        }
    }

    cout << "Optimal subset of items: {";
    for (int i = 0; i < maxSubset.size(); i++) {
        cout << maxSubset[i];
        if (i < maxSubset.size() - 1) {
            cout << ", ";
        }
    }
    cout << "} with maximum profit: " << maxProfit << endl;
}

int main() {
    int W1 = 8;
    vector<Item> items1 = {{1, 3, 3}, {2, 4, 2}, {3, 5, 3}, {4, 6, 5}};
    knapsack_FIFO_branch_and_bound(W1, items1);

    int W2 = 15;
    vector<Item> items2 = {{1, 5, 2}, {2, 7, 5}, {3, 9, 7}, {4, 10, 8}, {5, 12, 10}};
    knapsack_FIFO_branch_and_bound(W2, items2);

    return 0;
}
