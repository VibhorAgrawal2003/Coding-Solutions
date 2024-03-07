#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define d 256

void rabin_carp_search(string text, string pattern, int q) {

  int n = (int)size(text);
  int m = (int)size(pattern);
  int p = 0;
  int t = 0;
  int h = 1;
  int i{}, j{};

  // String pointers
  const char *textPtr = text.c_str();
  const char *patPtr = pattern.c_str();

  // Perform hashing
  for (i = 0; i < m - 1; i++) {
    h = (h * d) % q;
  }

  for (i = 0; i < m; i++) {
    t = (d * t + *(textPtr + i)) % q;
    p = (d * p + *(patPtr + i)) % q;
  }

  // Pattern matching
  for (i = 0; i <= n - m; i++) {

    if (p == t) {
      for (j = 0; j < m; j++) {
        if (text[i + j] != pattern[j]) {
          break;
        }
      }

      if (j == m) {
        cout << "Valid hit - index: " << i << "\n";
      } else {
        cout << "Spurious hit - index: " << i << "\n";
      }
    }

    if (i < n - m) {
      t = (d * (t - *(textPtr + i) * h) + *(textPtr + i + m)) % q;
      if (t < 0) {
        t += q;
      }
    }
  }
}

int main() {

  vector<tuple<string, string, int>> testcases{};
  testcases.push_back(
      (tuple<string, string, int>){"2359023141526739921", "31415", 13});
  testcases.push_back(
      (tuple<string, string, int>){"3141592653589793", "26", 11});

  for (auto x : testcases) {
    cout << " - - - \n";
    rabin_carp_search(get<0>(x), get<1>(x), get<2>(x));
  }

  return 0;
}