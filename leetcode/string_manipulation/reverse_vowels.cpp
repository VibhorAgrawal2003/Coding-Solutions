#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  bool isvowel(char x) {
    x = tolower(x);
    char vowels[] {'a', 'e', 'i', 'o', 'u'};
    bool isvowel {false};
    for (auto v : vowels) {
      if (x == v) {
        isvowel = true;
        break;
      }
    }
    return isvowel;
  }

  string reverseVowels(string s) {
    int p = 0;
    int q = size(s) - 1;
    string t = s;

    while (p <= q) {
      bool vowelP = isvowel(t[p]);
      bool vowelQ = isvowel(t[q]);

      if (vowelP && vowelQ) {
        swap(t[p++], t[q--]);
      }
      else {
        if (!vowelP) {
          p++;
        }
        if (!vowelQ) {
          q--;
        }
      }
    }
    return t;
  }
};

int main() {

  Solution S;
  vector<string> testcases{};
  testcases.push_back("leetcode");
  testcases.push_back("hello");
  testcases.push_back("abcd");
  testcases.push_back("abcdefghij");

  for (auto x : testcases) {
    cout << x << " " << S.reverseVowels(x) << "\n";
  }

  return 0;
}