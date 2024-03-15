#include <iostream>
#include <vector>

using namespace std;

/**
 * Brute approach where we find the count of every unique element.
 * Solves question with O(n) space and O(n^2) time.
 */
class Brute {
public:
  vector<int> majorityElement(vector<int> &nums) {

    vector<int> result{};
    vector<pair<int, int>> count{};

    for (int i = 0; i < (int)nums.size(); i++) {
      bool exists = false;

      for (int j = 0; j < (int)count.size(); j++) {
        if (count[j].first == nums[i]) {
          count[j].second++;
          exists = true;
          break;
        }
      }

      if (!exists) {
        count.push_back((pair<int, int>){nums[i], 1});
      }
    }

    for (auto p : count) {
      if (p.second > (int)nums.size() / 3) {
        result.push_back(p.first);
      }
    }

    return result;
  }
};

int main() {

  Brute S;
  vector<int> v1{4, 4, 4, 4, 4, 4, 4};
  for (auto x : S.majorityElement(v1)) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}