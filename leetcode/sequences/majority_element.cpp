#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * This approach considers the idea of a Tug-Of-War.
 * 
 * At every point in the traversal, we take the strongest (most occuring)
 * so far on one side of the tug of war and rest on other side.
 * 
 * The 'count' here stores the difference between strength on both sides.
 * If this touches zero, both sides are balanced in strength.
 * If this would be going negative, then we switch to a new strongest contender.
*/
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int label = nums[0];
    int count = 1;

    for (int i = 1; i < (int)nums.size(); i++) {
      if (label == nums[i]) {
        count++;
      }
      else {
        if (count == 0) {
          label = nums[i];
          count++;
        }
        else {
          count--;
        }
      }
    }
    return label;
  }
};

class Better {
public:
  int majorityElement(vector<int> &nums) {
    vector<int> sorted_nums {nums};
    sort(sorted_nums.begin(), sorted_nums.end());

    int count {0}, item{0};
    int N = (int)nums.size();

    for (auto x : sorted_nums) {
      if (x != item) {
        item = x;
        count = 1;
      }
      else {
        count++;
      }

      if (count > N/2) {
        return item;
      }
    }

    return 0;
  }
};

class Brute {
public:

  int searchCount(vector<pair<int, int>> &count, int x) {
    for (int i = 0; i < (int)count.size(); i++) {
      if (count[i].first == x) {
        return i;
      }
    }
    return -1;
  }

  int majorityElement(vector<int> &nums) {

    vector<pair<int, int>> count{};
    int N = (int)nums.size();

    // Count all occurences
    for (auto x : nums) {
      int i = searchCount(count, x);
      if (i!=-1) {
        count[i].second++;
      }
      else {
        count.push_back((pair<int, int>){x, 1});
      }
    }

    // Look for majority occurence
    for (auto x : count) {
      if (x.second > N/2) {
        return x.first;
      }
    }
    
    return -1;
  }
};

int main() {

  Solution S;

  vector<vector<int>> testcases {};
  testcases.push_back( (vector<int>) {1, 2, 3, 2, 2, 2} );
  testcases.push_back( (vector<int>) {9, 9, 9, 9, 1, 2, 3} );
  testcases.push_back( (vector<int>) {1} );
  testcases.push_back( (vector<int>) {2, 4, 4, 4} );
  testcases.push_back( (vector<int>) {0, 0, 0} );
  testcases.push_back( (vector<int>) {-1, -2, -2, 0, -2, -1, -2} );

  for (auto x : testcases) {
    cout << S.majorityElement(x) << " ";
  }

  // Expected output: 2 9 1 4 0 -2

  return 0;
}