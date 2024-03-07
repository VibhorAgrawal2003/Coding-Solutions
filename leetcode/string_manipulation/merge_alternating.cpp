#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string mergeAlternately(string word1, string word2) {

    int p{}, q{};
    int m{(int)word1.size()};
    int n{(int)word2.size()};

    string res{};

    int x{};
    while (p < m || q < n) {
      if (p < m && (x % 2 == 0 || q >= n)) {
        res += word1[p++];
      }

      if (q < n && (x % 2 != 0 || p >= m)) {
        res += word2[q++];
      }

      x++;
    }

    return res;
  }
};

int main() {
  Solution S;

  vector<pair<string, string>> testcases{};
  testcases.push_back((pair<string, string>){"abc", "pqr"});
  testcases.push_back((pair<string, string>){"x", "abcdef"});
  testcases.push_back((pair<string, string>){"abcdefg", "j"});
  testcases.push_back((pair<string, string>){"ab", "pqrs"});

  for (auto x : testcases) {
    cout << S.mergeAlternately(x.first, x.second) << "\n";
  }

  return 0;
}