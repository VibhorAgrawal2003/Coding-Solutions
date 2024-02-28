#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> void showVector(vector<T> &vec) {
  for (auto x : vec) {
    cout << x << " ";
  }
  cout << endl;
}

/**
 * KADANES ALGORITHM
 * This solution uses a smart observation.
 * We only need to lug forward a subarray if it increases the sum.
 * Therefore, only need to carry on a result if it is positive.
 * While we are calculating these sums, we can check against the maxsum.
 */
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxsum{INT_MIN}, sum{0};
    for (int i = 0; i < nums.size(); i++) {

      if (sum > 0) {
        sum += nums[i];
      } else {
        sum = nums[i];
      }

      if (sum > maxsum) {
        maxsum = sum;
      }
    }
    return maxsum;
  }
};

/**
 * This solution uses a Divide and Conquer approach.
 */
class Subpar {
public:
  int maxThree(int &x, int &y, int &z) {
    return (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
  }

  int findCrossSum(vector<int> &nums, int start, int mid, int end) {
    int lsum = nums[mid];
    int rsum = nums[mid + 1];

    int i{}, tsum = 0;
    for (i = mid; i >= 0; i--) {
      tsum += nums[i];
      if (tsum > lsum) {
        lsum = tsum;
      }
    }

    tsum = 0;
    for (i = mid + 1; i <= end; i++) {
      tsum += nums[i];
      if (tsum > rsum) {
        rsum = tsum;
      }
    }

    return lsum + rsum;
  }

  int maxSubArrayCalc(vector<int> &nums, int start, int end) {

    if (start == end) {
      return nums[start];
    } else {
      int mid = start + (end - start) / 2;
      int lsum = maxSubArrayCalc(nums, start, mid);
      int rsum = maxSubArrayCalc(nums, mid + 1, end);
      int csum = findCrossSum(nums, start, mid, end);

      return maxThree(lsum, rsum, csum);
    }
  }

  int maxSubArray(vector<int> &nums) {
    return maxSubArrayCalc(nums, 0, nums.size() - 1);
  }
};

/**
 * This approach iterates through all the subarrays.
 */
class Brute {
public:
  int maxSubArray(vector<int> &nums) {
    int maxsum{INT_MIN};
    for (int i = 0; i < nums.size(); i++) {
      int sum{0};
      for (int j = i; j < nums.size(); j++) {
        sum += nums[j];
        if (sum > maxsum) {
          maxsum = sum;
        }
      }
    }
    return maxsum;
  }
};

int main() {

  vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> v2 = {5, 4, -1, 7, 8};
  vector<int> v3 = {-2, -1};
  vector<int> v4 = {-2, -1, 0, -1};
  vector<int> v5 = {-100, -99, -1, -2, -4};
  vector<int> v6 = {-2, 1};
  vector<int> v7 = {8, -19, 5, -4, 20};

  Solution S;
  cout << S.maxSubArray(v1) << endl;
  cout << S.maxSubArray(v2) << endl;
  cout << S.maxSubArray(v3) << endl;
  cout << S.maxSubArray(v4) << endl;
  cout << S.maxSubArray(v5) << endl;
  cout << S.maxSubArray(v7) << endl;

  // Subpar P;
  // cout << P.maxSubArray(v1) << endl;
  // cout << P.maxSubArray(v2) << endl;
  // cout << P.maxSubArray(v3) << endl;
  // cout << P.maxSubArray(v4) << endl;
  // cout << P.maxSubArray(v5) << endl;

  // Brute B;
  // cout << B.maxSubArray(v1) << endl;
  // cout << B.maxSubArray(v2) << endl;
  // cout << B.maxSubArray(v3) << endl;
  // cout << B.maxSubArray(v4) << endl;
  // cout << B.maxSubArray(v5) << endl;

  // Solutions
  // 6, 23, -1, 0, -1, 1, 21

  return 0;
}