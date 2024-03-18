#include <iostream>
#include <vector>

using namespace std;

/**
 * We find the product of all non-zero numbers as well as
 * the number of zeroes in the input array.
 *
 * We use that information to find each element's value
 * in the answer array.
 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> answer{};
    int prod = 1;
    int zeroes = 0;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        zeroes++;
      } else {
        prod *= nums[i];
      }
    }

    if (zeroes > 1) {
      for (int i = 0; i < n; i++) {
        answer.push_back(0);
      }
    } else if (zeroes == 1) {
      for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
          answer.push_back(prod);
        } else {
          answer.push_back(0);
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        answer.push_back(prod / nums[i]);
      }
    }

    return answer;
  }
};

/**
 * Here, we run a nested loop to iteratively calculate the
 * right product for every element of the answer array.
 */
class Brute {
public:
  vector<int> productExceptSelf(vector<int> &nums) {

    vector<int> answer{};

    for (int i = 0; i < (int)nums.size(); i++) {
      int prod = 1;
      for (int j = 0; j < (int)nums.size(); j++) {
        if (i != j) {
          prod *= nums[j];
        }
      }
      answer.push_back(prod);
    }

    return answer;
  }
};