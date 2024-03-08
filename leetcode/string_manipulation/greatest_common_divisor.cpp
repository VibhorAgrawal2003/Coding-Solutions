#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    string gcd{};
    string prefix;

    int maxsize{};
    int m = (int)size(str1);
    int n = (int)size(str2);

    // Calculate HCF of sizes of strings
    for (int i = min(m, n); i >= 1; i--) {
      if (m % i == 0 && n % i == 0) {
        maxsize = i;
        break;
      }
    }

    // Find longest possible prefix
    for (int i = 0; i < maxsize; i++) {
      prefix += str1[i];
    }

    // Match every prefix with both strings
    for (int i = (int)size(prefix); i >= 1; i--) {
      bool flag1{true};
      bool flag2{true};

      for (int j = 0; j < m; j++) {
        if (str1[j] != prefix[j % i]) {
          flag1 = false;
          break;
        }
      }

      for (int j = 0; j < n; j++) {
        if (str2[j] != prefix[j % i]) {
          flag2 = false;
          break;
        }
      }

      if (flag1 && flag2) {
        for (int j = 0; j < i; j++) {
          gcd += prefix[j];
        }
        break;
      }
    }

    return gcd;
  }
};

int main() {

  Solution S;
  vector<pair<string, string>> testcases{};
  testcases.push_back((pair<string, string>{"abcabc", "abc"}));
  testcases.push_back((pair<string, string>{"ababab", "abab"}));
  testcases.push_back((pair<string, string>{"leet", "code"}));
  testcases.push_back((pair<string, string>{"abcabc", "abab"}));
  testcases.push_back((pair<string, string>{"abababab", "abab"}));

  for (auto x : testcases) {
    cout << S.gcdOfStrings(x.first, x.second) << "\n";
  }

  return 0;
}