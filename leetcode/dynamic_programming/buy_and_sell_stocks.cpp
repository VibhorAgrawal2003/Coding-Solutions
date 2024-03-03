#include <iostream>
#include <vector>

using namespace std;

/**
 * ONE-PASS ALGORITHM
 * Approach is to traverse the entire array once keeping track
 * of the minimum possible value found. This is when we buy stock.
 * At every new value, we assume we would sell the stock we bought
 * at last minimum value. This is checked with our max profit.
 */

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit{0};
    int mini{INT_MAX};

    for (auto x : prices) {
      if (x < mini) {
        mini = x;
      }

      if ((x - mini) > profit) {
        profit = x - mini;
      }
    }
    return profit;
  }
};

int main() {

  Solution S;
  vector<vector<int>> testcases{};
  testcases.push_back((vector<int>){7, 1, 5, 3, 6, 4});
  testcases.push_back((vector<int>){7, 6, 4, 3, 2, 1});
  testcases.push_back((vector<int>){4, 3, 0, 8, 7, 1});
  testcases.push_back((vector<int>){9, 8, 2, 8, 3, 9, 1});

  for (auto x : testcases) {
    cout << S.maxProfit(x) << "\n";
  }

  return 0;
}