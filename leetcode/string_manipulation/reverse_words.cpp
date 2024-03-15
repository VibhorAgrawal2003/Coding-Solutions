#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string res{};
    string word{};
    vector<string> words{};
    bool found = false;

    // Parse the string and locate words
    for (auto x : s) {
      if (found) {
        if (isalnum(x)) {
          word += x;
        }
        else {
          found = false;
          words.insert(words.begin(), word);
          word = "";
        }
      } else {
        if (isalnum(x)) {
          found = true;
          word += x;
        }
      }
    }

    // Catch the last word as well
    if (word != "") {
      words.insert(words.begin(), word);
    }

    // Convert words into result string
    for (size_t i = 0; i < words.size() - 1; i++) {
      res += words[i];
      res += " ";
    }
    res += words.back();

    return res;
  }
};

int main() {

  Solution S;
  cout << S.reverseWords("   the   sky  is     blue   ") << "\n";
  cout << S.reverseWords("mountains    in wonderland") << "\n";
  cout << S.reverseWords("honeybeesAreLovelyCreatures") << "\n";
  cout << S.reverseWords("i came across   an    amazing person  ") << "\n";

  return 0;
}