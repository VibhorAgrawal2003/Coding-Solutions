#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {

    int sizeS = (int)size(s);
    int sizeT = (int)size(t);

    int q = 0;
    for (int p = 0; p < sizeT; p++) {
      if (q == sizeS) {
        return true;
      }
      if (s[q] == t[p]) {
        q++;
      }
    }

    return (q == sizeS);
  }
};

int main() {

  Solution S;
  vector<pair<string, string>> testcases{};
  testcases.push_back((pair<string, string>){"abc", "axxyzzbmcz"});
  testcases.push_back((pair<string, string>){"mon", "pokemon"});
  testcases.push_back((pair<string, string>){"key", "elephant"});
  testcases.push_back((pair<string, string>){"sandbox", "sandboxes"});
  testcases.push_back((pair<string, string>){"laugh", "landofthefree"});

  cout << boolalpha;
  for (auto x : testcases) {
    cout << S.isSubsequence(x.first, x.second) << "\n";
  }

  return 0;
}